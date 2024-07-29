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
                                 "    background-color: white;"
                                 "color:black;"
                                 "    border-radius: 20px;" // Adjust the radius as needed
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
                                 "    background-color: black;"
            "color:white;"
                                 "    border-radius: 20px;" // Adjust the radius as needed
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
                         "    background-color: white;"
                         "    color: black;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "}";

    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 20pt;"
                          "    background-color: black;"
                          "    color: white;"
                          "    border-radius: 20px;"
                          "    font: bold;" // Adjust the radius as needed
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

//       ui->ULTRASONICBUT1->setEnabled(true);
//       ui->ULTRASONICBUT2->setEnabled(true);
//       ui->ULTRASONICBUT3->setEnabled(true);
//       ui->ULTRASONICBUT4->setEnabled(true);
//       ui->label_8->setStyleSheet(styleSheet7);
//       ui->label_9->setStyleSheet(styleSheet7);
//       ui->label_39->setStyleSheet(styleSheet7);
//       ui->label_38->setStyleSheet(styleSheet7);

   }
   else
   {
       ui->label->setStyleSheet(styleSheet5);

      //  qDebug()<<"handpiece off"<<status;
       ui->Start_tune_2->setEnabled(false);
     //  QMessageBox::information(nullptr,"warning","please connect handpiece");
//        ui->ULTRASONICBUT1->setEnabled(false);
//        ui->ULTRASONICBUT2->setEnabled(false);
//        ui->ULTRASONICBUT3->setEnabled(false);
//        ui->ULTRASONICBUT4->setEnabled(false);
//        ui->label_8->setStyleSheet(styleSheet6);
//        ui->label_9->setStyleSheet(styleSheet6);
//        ui->label_39->setStyleSheet(styleSheet6);
//        ui->label_38->setStyleSheet(styleSheet6);
     //flag1=false;
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
    pretimer->stop();


}

void prime::on_pushButton_5_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: white;"
                                 "color:black;"

                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";


   Tune();
    ui->Tune_but->setStyleSheet(styleSheet);

}

void prime::on_pushButton_6_clicked()
{


   m->show();

}

void prime::on_pushButton_8_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: white;"
                                 "color:black;"

                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";
  Prime();
    ui->prime1_but->setStyleSheet(styleSheet);

}

