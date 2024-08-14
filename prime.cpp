#include "prime.h"
#include "ui_prime.h"
#include <QMessageBox>
#include<QTimer>
#include<QFile>
#include<QImage>
#include<QDebug>
#include<QIODevice>

prime::prime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prime)
{
    ui->setupUi(this);
    move(0,0);
    m=new MainWindow;
    sur=new doctor;
    set=new settings;
    hand=new hwhandler;
    ui->progressBar_2->setRange(0,100);
    //hand->freq_count(2500);
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    background-color: transparent;"
                         "    image: url(:/images/g3645.png);"
                         "    color: black;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";


    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; border-radius:50px}";
    QString styleSheet3 =
                "QTabBar::tab {"
                "    font-size: 16px; /* Set the font size */"
                "    border-radius: 10px; /* Set the border radius */"
                "}";
//ui->tabWidget->setStyleSheet(styleSheet3);

     ui-> tabWidget->setStyleSheet(tabStyle);
    ui->tabWidget->setTabText(0 ,"     PRIME        ");
    ui->tabWidget->setTabText(1 ,"     TUNE         ");
    ui->tabWidget->setTabText(2 ,"     CLEAN        ");



    statusUpdateTimer = new QTimer(this);
    connect(statusUpdateTimer, &QTimer::timeout, this, &prime::onUpdateStatusTimeout);
    statusUpdateTimer->start(500); // Update every second


   connect(ui->prime1_but,&QPushButton::clicked,this,&prime::Prime);

   connect(ui->Tune_but,&QPushButton::clicked,this,&prime::Tune);
  connect(ui->Start_tune_2,&QPushButton::clicked,this,&prime::Start_Tune);
   connect(ui->clean_but,&QPushButton::clicked,this,&prime::Clean);

   connect(ui->prime1_but, &QPushButton::clicked, [=](){
       ui->prime1_but->setStyleSheet(styleSheet);

   });
   connect(ui->Tune_but, &QPushButton::clicked, [=](){
       ui->Tune_but->setStyleSheet(styleSheet);

   });
  connect(ui->clean_but, &QPushButton::clicked, [=](){
      ui->clean_but->setStyleSheet(styleSheet);

  });

    timer1=new QTimer;
    connect(timer1, &QTimer::timeout, this, &prime::timer);
    pretimer=new QTimer;
    connect(pretimer,&QTimer::timeout,this,&prime::primetimer);

      ui->progressBar_2->setRange(0, 100);
     current(ui->tabWidget->currentIndex());



}

prime::~prime()
{
    delete ui;
}
void prime::click()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/g3042.png);"
                         "    background-color: transparent;"
                         "    color: white;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";


   ui->prime1_but->setStyleSheet(styleSheet);
   ui->Tune_but->setStyleSheet(styleSheet);
   ui->clean_but->setStyleSheet(styleSheet);


}
void prime::current(int tab)
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/g3645.png);"
                         "    background-color: transparent;"
                         "    color: black;"
                         //"    border-radius: 20px;" // Uncomment if needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";

    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 20pt;"
                          "    image: url(:/images/g3042.png);"
                          "    background-color: transparent;"
                          "    color: white;"
                          //"    border-radius: 20px;" // Uncomment if needed
                          "    font-weight: bold;"  // Corrected from 'font: bold;'
                          "}"
                          "QPushButton:focus {"
                          "    outline: none;"
                          "    border: none;"
                          "}";

    // Reset all buttons to the default style
    ui->prime1_but->setStyleSheet(styleSheet1);
    ui->Tune_but->setStyleSheet(styleSheet1);
    ui->clean_but->setStyleSheet(styleSheet1);

    // Set the style for the current tab
    if (tab == 0) {
        ui->prime1_but->setStyleSheet(styleSheet);
    } else if (tab == 1) {
        ui->Tune_but->setStyleSheet(styleSheet);
    } else if (tab == 2) {
        ui->clean_but->setStyleSheet(styleSheet);
    }
}


void prime::update()
{

}

void prime::hp(int connected)
{

}

void prime::exportGPIO(int pin)
{
    QFile file("/sys/class/gpio/export");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << pin;
        file.close();
      //  qDebug() << "GPIO" << gpioNumber << "exported.";
    }/* else {
      //  qDebug() << "Failed to export GPIO" << gpioNumber;
    }*/
}

void prime::setGPIODirection(const QString &direction,int pin)
{
    QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(pin));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << direction;
        file.close();
       // qDebug() << "GPIO" << gpioNumber << "set to" << direction;
    } /*else {
        qDebug() << "Failed to set direction for GPIO" << gpioNumber;
    }*/
}

int prime::readGPIOValue(int pin)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(pin));
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        int value;
        stream >> value;
        file.close();
        //qDebug() << "Read value from GPIO" << gpioNumber << ":" << value;
        return value;
    } /*else {
        qDebug() << "Failed to read value from GPIO" << gpioNumber;
        return -1;
    }*/
}






void prime::updatehandpieceStatus()
{
    int status = readGPIOValue(960);


    QString styleSheet4 = "QLabel {"
          "image: url(:/images/connected.png);"
            "border:none;"


 "}";

    QString styleSheet5 = "QLabel {"

            "image: url(:/images/notconnected.png);"

         "border:none;"

                                     "}";

   if(status==0)
   {
       ui->label->setStyleSheet(styleSheet4);

      // qDebug()<<"handpiece on"<<status;
       ui->Start_tune_2->setEnabled(true);



   }
   else
   {
       ui->label->setStyleSheet(styleSheet5);

      //  qDebug()<<"handpiece off"<<status;
       ui->Start_tune_2->setEnabled(false);
       QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Info", "Tune is not completed");

       // Set the message box to show
       msgBox->show();

       // Create a QTimer to close the message box after 500 ms
       QTimer::singleShot(700, msgBox, [msgBox]() {
           msgBox->hide();  // Hide the message box
           delete msgBox;   // Delete the message box to free memory

   });
   }
}


void prime::start_irrigation()
{
    hand->pinchvalve_on();
    hand->safetyvent_on();
    qDebug() << "Irrigation started";
    ui->start_check_2->setChecked(true);
     pretimer->start(290);
    // Move to the next step after starting irrigation
    QTimer::singleShot(15000, this, &prime::champer_Filled);
}
void prime::motoron()
{

    hand->write_motor(0x01,0x03,40);
    qDebug() << "Motor started";
    ui->motor_Check_2->setChecked(true);
    pretimer->start(290);

    QTimer::singleShot(15000, this, &prime::start_irrigation);
}

void prime::motoroff()
{
    hand->write_motor(0x00,0x00,0);
}
void prime::champer_Filled()
{

    qDebug() << "Chamber Filled";
    ui->wait_Check_2->setChecked(true);
    pretimer->start(290);

    // Finish the prime process
    QTimer::singleShot(15000, this, &prime::done);
}
bool prime::checkChamberFill()
{
}
void prime::done()
{
    qDebug() << "Prime process done";
    ui->done_Check_2->setChecked(true);
    pretimer->start(290);
  //  ui->progressBar_2->setValue(100);

 hand->safetyvent_off();
 hand->pinchvalve_off();
    motoroff();

}


void prime::onUpdateStatusTimeout(){
    updatehandpieceStatus();
}



void prime::timer(){
    int value = ui->progressBar->value();
       if (value < 100) {
           ui->progressBar->setValue(value + 1);
     // hand->freq_count(2500);

        } else {
            timer1->stop();
            m->show();
            m->setTuneMode(true);
            m->DIATHERMYBUT(); // Show the main window after progress is complete
        }



}

void prime::primetimer()
{
    int value = ui->progressBar_2->value();
       if (value < 100) {
           ui->progressBar_2->setValue(value + 1);
     // hand->freq_count(2500);

        }
       else {
                   pretimer->stop();
                 // Show the main window after progress is complete
               }
}
void prime::Prime()
{


    ui->tabWidget->setCurrentIndex(0);
  click();
   timer1->stop();
}

void prime::Tune()
{

    ui->tabWidget->setCurrentIndex(1);

    click();

}

void prime::Clean()
{

    ui->tabWidget->setCurrentIndex(2);

    click();
   timer1->stop();
}


void prime::Start_Tune()
{

   hand->freq_count(2500);
   hand->phaco_on();
   hand->phaco_power(80);

        ui->progressBar_2->setValue(0);
        timer1->start(500); // Update every 100 ms



}







void prime::on_start_prime_but_2_clicked()
{
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);
 ui->progressBar->setValue(0);

 motoron();
 start_irrigation();
 ui->Tune_but->show();
}

void prime::on_begin_clean_but_2_clicked()
{
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);
    ui->progressBar->setValue(0);
    motoron();
    hand->pinchvalve_on();
    pretimer->stop();


}

void prime::on_pushButton_5_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: transparent;"
                                 "color:black;"
     "  image: url(:/images/g3645.png);"
                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";


   Tune();
    ui->Tune_but->setStyleSheet(styleSheet);

}

void prime::on_pushButton_6_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Info");
    msgBox.setText("Tune is not completed. Do you want to continue?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    int ret = msgBox.exec(); // Get the user's choice

    if (ret == QMessageBox::Yes) {
        m->show();
        m->setTuneMode(false);
         m->DIATHERMYBUT();
    } else {
        // Handle the case where "No" is clicked (optional)
    }


}

void prime::on_pushButton_8_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: transparent;"
                                 "color:black;"
     "  image: url(:/images/g3645.png);"
                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";
  Prime();
    ui->prime1_but->setStyleSheet(styleSheet);

}

