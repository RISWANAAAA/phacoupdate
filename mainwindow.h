#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "settings.h"

#include "keypad.h"
//#include"demo.h"

#include <QMainWindow>
#include<QSlider>
#include<QPushButton>
#include<QLabel>
#include<QTableWidget>
#include<QMessageBox>
#include <QTimer>
#include<QIntValidator>

#include "footlib.h"
//#include "hhandler.h"
#include "vaccum.h"
//#include"reset.h"
#include<QElapsedTimer>
//#include "hwhandler.h"
#include"hwhandler.h"
//#include "motor.h"
//#include "motordone.h"
#include"doctor.h"
#define PATH "phaco1.db"
#include<QSqlQuery>
#include<QSqlRecord>

class settings;
class prime;
 class footpedal;
 class doctor;
 class demo;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;

             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // int valuemain=0;
    void startPoint();
    bool eventFilter(QObject* object, QEvent* event);
    //bool eventFilter(QObject* object, QEvent* event);
    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);
   // void highlightButton(QPushButton* button);
    void click();
    void exportGPIO(int pin);
    void setGPIODirection(const QString &direction,int pin);
    int readGPIOValue(int pin);
    int readGPIOValue1();
    void updateStatus();
    void printAllRows();

       void handlePowerOnOff();
       void handlePDM();
       void savesettings();


    int range=0;
    int rec;

    int butname=0;
    struct SystemState {
           bool powerOn;
           bool powerOn1;
           bool powerOn2;
           bool powerOn3;// Flag to track power state
           bool powerOn4;// Flag to track power state
           QString buttonState;    // To track button state
           QString button;
           //us2
           QString buttonstate1;
           QString button1;
           //us3
           QString buttonstate2;
           QString button2;
           //us4
           QString buttonstate3;
           QString button3;
           //vit
           QString buttonstate4;
           QString button4;

       }power;
    struct SurgeonData {
        QString surgeonName;
        int lineEdit1Value;
        int lineEdit2Value;
         int lineEdit3Value;
         QString powerDelivery;
         QString pdmMode;
         QString vacmode;
    };
    int Flow_LUT[42]={95,95,  //0
                    110,110,  //2
                    112,112,  //4
                    115,115,  //6
                    122,122,  //8
                    130,130, //10
                    145,145, //12
                    155,150, //14
                    165,155, //16
                    175,160, //18
                    185,170, //20
                    195,195, //22
                    205,205, //24
                    215,215, //26
                    225,225, //28
                    245,245, //30
                    255,255, //32
                    265,265, //34
                    275,275, //36
                    290,290, //38
                    299,299  //40
                    };



public slots:
     void userMessage(int value, int minValue, int maxValue);
     void updateLineedit(QLineEdit *lineEdit, int prevValue, int value, int maxValue);
    void on_clicked(const QString& digit);
    void on_clickedenter();
     void changeButtonColor(int tabIndex);
   //  void buttons();
     void current(int tab);
   //  void handpiece();
     void updateline();
 void tabupdate(int index);
 void footpedalcheck();

 void updateElapsedTime();
 void updateProgressBar();
void motoron(QLineEdit *lineEdit);
void motoroff();
void motorccwon();

 void increasebutton(QLineEdit *increaseline);
 void decreasebutton(QLineEdit *decreaseline);
 void vacbutton(QLineEdit *vacline);
 //void resetProgress();
 void powervit();

 void powercheck();
 void DIATHERMYBUT();
// void applyFootpedalSettings(const footpedal::FootpedalSettings &settings);
  //void valueReceived(int val);
 void onMainLineEditTextChanged(const QString &dpowmax);
 void movePushButtonTopToBottom();
    void movePushButtonBottomToTop();
    void footreflux();
    void powerdeliverymethod();
    void continousirrigation();
    void poweronoff();
    void poweron();
    void updateValues(const QString &surgeon, int tabIndex, const QStringList &values);
    void onCutMode_vitComChanged(int index);
    void onCutMode_vitComChanged1(int index);
    void onCutMode_vitComChanged2(int index);
    void onCutMode_vitComChanged3(int index);


private slots:



 void label43();
//void promptForUpdate(const QString &fieldName, const QString &newValue);
 void sensor2();
    void ULTRASONICBUT1();

    void ULTRASONICBUT2();

    void ULTRASONICBUT4();

    void IRRIGATIONBUT1();

    void IRRIGATIONBUT2();

    void VITRECTOMYBUT();


    void diapowup();

    void diapowdown();

    void vitcutup();

    void vitcutdown();

    void vitvacup();

    void vitvacdown();

    void vitflowup();

    void vitflowdown();

    void ia2vacup();

    void ia2vacdown();

    void ia2flowup();

    void ia2flowdown();

    void ia1vacup();

    void ia1vacdown();

    void ia1flowup();

    void ia1flowdown();

    void US1POWUP();

    void US1POWDOWN();

    void US1VACDOWN();

    void US1VACUP();

    void US1FLOWDOWN();

    void US1FLOWUP();

    //void on_pushButton_32_clicked();

    void us2powup();

    void us2powdown();

    void us2vacup();

    void us2vacdown();

    void us2flowup();

    void us2flowdown();

    void ULTRASONICBUT3();

    void us3powup();

    void us3powdown();

    void us3vacup();

    void us3vacdown();

    void us3flowup();

    void us3flowdown();

    void us4powup();

    void us4powdown();

    void us4vacup();

    void us4vacdown();

    void us4flowup();

    void us4flowdown();

    void SETTINGSBUT();

    void BACKBUT();

    void on_DIABUT_clicked();

    void us1_linear_nonlinear();

    void us2_linear_nonlinear();


    void us3_linear_nonlinear();

    void us4_linear_nonlinear();


    void ia1_linear_nonlinear();

    void ia2_linear_nonlinear();

    void vit_linear_nonlinear();

   // void on_pushButton_3_clicked();

   // void on_pushButton_clicked();



    void updatehandpieceStatus();

    void updatesensor();

 void onUpdateStatusTimeout(); // Slot to handle timer timeout
 void updateTimers();
 //void onActionTriggered(const QString &action, const QString &position);
 void settings_action(int index);

 void on_us1onoff_clicked();

 void on_us2onoff_clicked();

 void on_us3onoff_clicked();

 void on_us4onoff_clicked();

 void on_vitonoff_clicked();

 void on_pushButton_4_clicked();



void on_pushButton_5_clicked();

void on_us1vacmode_clicked();

void on_us2vacmode_clicked();

void on_us3vacmode_clicked();

void on_vitvacmode_clicked();

void on_us4vacmode_clicked();
void updateComboBox1(const QString &text);
void updateComboBox2(const QString &text);
void updateComboBox3(const QString &text);
void updateComboBox4(const QString &text);
 void onSurgeonChanged();
 void updateButtonSelection(int index);


 void on_pushButton_6_clicked();

 void on_pushButton_44_clicked();

 void on_pushButton_45_clicked();

 void on_pushButton_46_clicked();

 void on_pushButton_47_clicked();

 void on_pushButton_48_clicked();

 void on_pushButton_49_clicked();

 void on_pushButton_50_clicked();

 void on_pushButton_51_clicked();

 void on_pushButton_52_clicked();

 void on_pushButton_53_clicked();

 void on_pushButton_54_clicked();

 void on_pushButton_55_clicked();



 void on_SETTINGS_BUT_3_clicked();

 void on_CI5_2_clicked();

 void on_CI1_clicked();

 void on_CI2_clicked();

 void on_CI3_clicked();

 void on_CI4_clicked();

 void on_CI5_3_clicked();

 void on_CI5_4_clicked();

 void on_CI5_clicked();

signals:
    void sensorValueChanged(int value);


private:
    Ui::MainWindow *ui;
    int gpioNumber = 960; // Change this to your actual GPIO number
    int gpioNumber1=961;
     QTimer  *statusUpdateTimer;
       footpedal *foot;
   //  demo *de;
       doctor *in;
    int value1=0;
    int value2=0;
    int pulse=0;
    int ocupulse;
    int ocuburst;
    int singleburst=0;
    int multiburst=0;
    int coldphaco=0;
    int coldphaco1=0;
   int previousValue[7];
    settings *s;
    //prime *p;
    keypad *key;
    QMessageBox *message;
  QTimer timer2;
    QTimer *timer;
    footlib *lfoot;
   // hhandler *hard;
    hwhandler *handler;
   //   hwhandler *hwhand;
   QIntValidator *valid;
   QMessageBox *messageline;
    bool flag1=false;
    bool on;
int getvalue(int input);
int currentButtonIndex;

       // QElapsedTimer *timer8;
      //  Reset *r;
        qint64 elap=0;
        QElapsedTimer timer5;

           float effectiveTime ;

             QTime startTime;
             QTimer *sensortimer;
             //QTimer updateTimer;
             QTimer *footime;
             QTimer *protimer;
             QTimer *timer43;
             QTimer *footsensor;
             QTimer *timermsg;
             bool cius1;
             bool cius2;
             bool cius3;
             bool cius4;
             bool civit;
             bool ci_ia1;
             bool ci_ia2;
             bool cidia;



             QString us1;
             QString us2;
             QString us3;
             QString us4;
             QString ia1;
             QString ia2;
             QString vit;
             QString vus1;
             QString vus2;
             QString vus3;
             QString vus4;
             QString vvit;
             QTimer *footpedaltimer;
              int currentProgressBar=1;
              bool us1powon=false;
              bool us2powon;
              bool us3powon;
              bool us4powon;
              bool vitpowon;
              int dir;
              QTimer *powtimer;
              QTimer *surtimer;
              int currentValue;
              int maxValue;
              //int lvalue;
              Vaccum *vac;
              int roundToNearest60(int value);
              QElapsedTimer currentTimer;
              QTimer *updateTimer;
              qint64 elapsedTimeUS1, elapsedTimeUS2, elapsedTimeUS3, elapsedTimeUS4;
              int currentButton;
              void updateLabel();
              void switchTimer(int button);
               int counter=0;
 bool powerOn;
 QMap<QString, QMap<int, QStringList>> surgeonData;
void updateTabsBasedOnComboBox(const QString &text);


};
#endif // MAINWINDOW_H
