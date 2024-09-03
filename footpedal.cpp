#include "footpedal.h"
#include "ui_footpedal.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QTimer>

footpedal::footpedal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::footpedal),
    d1(new doctor)
{
    ui->setupUi(this);
    move(0, 0);

    // Export and set direction of GPIOs
    initializeGPIO();

    // Set up connections
    setupConnections();

    connect(ui->backbut, &QPushButton::clicked, this, &footpedal::Back);
    connect(ui->savebut, &QPushButton::clicked, this, &footpedal::on_pushButton_clicked);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &footpedal::readInitialGPIOValues);
    timer->start(350);
}

footpedal::~footpedal()
{
    delete ui;
    delete d1;
}

void footpedal::Back()
{
    this->close();
}

void footpedal::setupConnections()
{
    connect(ui->left_footcom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->right_footcom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->bleft_footcom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->bright_footcom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
}

void footpedal::storeComboBoxSelection(int index)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox)
    {
        QString action = comboBox->itemText(index);
        if (comboBox == ui->left_footcom) {
            leftFootcomAction = action;
        } else if (comboBox == ui->right_footcom) {
            rightFootcomAction = action;
        } else if (comboBox == ui->bleft_footcom) {
            bleftFootcomAction = action;
        } else if (comboBox == ui->bright_footcom) {
            brightFootcomAction = action;
        }
    }
}

void footpedal::readInitialGPIOValues()
{
    qDebug() << "Reading GPIO values...";

    int value1 = readGPIOValue(961);
    int value2 = readGPIOValue(962);
    int value3 = readGPIOValue(963);
    int value4 = readGPIOValue(964);

    qDebug() << "GPIO Values:"
             << "GPIO 961:" << value1
             << "GPIO 962:" << value2
             << "GPIO 963:" << value3
             << "GPIO 964:" << value4;

    performAction(leftFootcomAction, value1);
    performAction(rightFootcomAction, value2);
    performAction(bleftFootcomAction, value3);
    performAction(brightFootcomAction, value4);
}

void footpedal::performAction(const QString &action, int gpioValue)
{
    if (action == "Increment") {
        qDebug() << "Increment action for GPIO with value" << gpioValue;
        emit moveTopToBottom(gpioValue);
    } else if (action == "Decrement") {
        qDebug() << "Decrement action for GPIO with value" << gpioValue;
        emit moveBottomToTop(gpioValue);
    } else if (action == "Reflux") {
        qDebug() << "Reflux action for GPIO with value" << gpioValue;
        emit performReflux(gpioValue);
    } else if (action == "Power ON/OFF") {
        qDebug() << "Power action for GPIO with value" << gpioValue;
        emit togglePower(gpioValue);
    } else if (action == "PDM") {
        qDebug() << "PDM action for GPIO with value" << gpioValue;
        emit powerdm(gpioValue);
    } else if (action == "Continuous Irrigation") {
        qDebug() << "Continuous Irrigation action for GPIO with value" << gpioValue;
        emit continous_irrigation(gpioValue == 0);
    }
}

void footpedal::initializeGPIO()
{
    const QList<int> gpioPins = {961, 962, 963, 964};

    for (int gpioNumber : gpioPins) {
        exportGPIO(gpioNumber);
        setGPIODirection(gpioNumber, "in");
        qDebug() << "GPIO" << gpioNumber << "direction set to in";
    }

  readInitialGPIOValues();
}

void footpedal::exportGPIO(int gpioNumber)
{
    QFile file("/sys/class/gpio/export");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << gpioNumber;
        file.close();
    }
}

void footpedal::setGPIODirection(int gpioNumber, const QString &direction)
{
    QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(gpioNumber));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << direction;
        file.close();
    }
}

void footpedal::writeGPIOValue(int gpioNumber, int value)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(gpioNumber));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << value;
        file.close();
    }
}

int footpedal::readGPIOValue(int gpioNumber)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(gpioNumber));
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        int value;
        stream >> value;
        file.close();
        return value;
    }
    return -1;
}

void footpedal::updateFootpedalComboBoxes(const QString &surgeonName)
{
    QSqlQuery query(db);
    query.prepare(
        "SELECT footleft, footright, footbottomleft, footbottomright "
        "FROM phacohigh "
        "WHERE surgeon = :surgeon"
    );
    query.bindValue(":surgeon", surgeonName);

    if (!query.exec()) {
        qDebug() << "Failed to fetch footpedal data for surgeon:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        ui->left_footcom->setCurrentText(query.value("footleft").toString());
        ui->right_footcom->setCurrentText(query.value("footright").toString());
        ui->bleft_footcom->setCurrentText(query.value("footbottomleft").toString());
        ui->bright_footcom->setCurrentText(query.value("footbottomright").toString());
    }
}

void footpedal::combobox1(const QString &text)
{
    ui->left_footcom->setCurrentText(text);
}

void footpedal::combobox2(const QString &text)
{
    ui->right_footcom->setCurrentText(text);
}

void footpedal::combobox3(const QString &text)
{
    ui->bleft_footcom->setCurrentText(text);
}

void footpedal::combobox4(const QString &text)
{
    ui->bright_footcom->setCurrentText(text);
}

void footpedal::setSurgeonName(const QString &name)
{
   // currentSurgeonName = name;
}

void footpedal::on_pushButton_clicked()
{
    if (currentSurgeonName.isEmpty()) {
        qDebug() << "Surgeon name is not set. Cannot save footpedal settings.";
        return;
    }

    QSqlQuery query(db);
    query.prepare(
        "UPDATE phacohigh "
        "SET footleft = :footleft, "
        "footright = :footright, "
        "footbottomleft = :footbottomleft, "
        "footbottomright = :footbottomright "
        "WHERE surgeon = :surgeon"
    );
    query.bindValue(":footleft", ui->left_footcom->currentText());
    query.bindValue(":footright", ui->right_footcom->currentText());
    query.bindValue(":footbottomleft", ui->bleft_footcom->currentText());
    query.bindValue(":footbottomright", ui->bright_footcom->currentText());
    query.bindValue(":surgeon", currentSurgeonName);

    if (!query.exec()) {
        qDebug() << "Failed to update footpedal settings:" << query.lastError().text();
    } else {
        qDebug() << "Footpedal settings updated successfully.";
    }
}
