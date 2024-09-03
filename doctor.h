#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>
#include"keypad.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#define PATH "/home/phacohigh.db"

class QLineEdit;
namespace Ui {
class doctor;
}

class doctor : public QDialog
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = nullptr);
    ~doctor();
    bool eventFilter(QObject* object, QEvent* event);
    QString surgeonid;
    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);
   void onSurgeonSelectionChanged(const QString &surgeonName);
   void setLastSelectedValue();

public slots:



   void onComboBoxIndexChanged(int index);
    void on_clicked(const QString& digit);
    void on_clickedenter();
    void clickedtab(int tab1);
    void click(int tab);
    int increasebutton(int input);
    int decreasebutton(int input);

private slots:
    void DiathermyBut();

    void PhacoBut();

    void IrrigationAspirationBut();

    void VitrectomyBut();

    void BackBut();

    void on_QuadBut_phaco_clicked();

    void on_ChopBut_phaco_clicked();

    void on_ScupltBut_phaco_clicked();

    void on_EpinBut_phaco_clicked();

    void on_pushButton_clicked();

    void pumpvalue();

  void on_SaveDiaBut_clicked();

  void handleDataSaved();


signals:

  void sendleftfootvalues(const QString &text1);
  void sendrightfootvalues(const QString &text2);
  void sendbleftfootvalues(const QString &text3);
  void sendbrightfootvalues(const QString &text4);
              void leftfoot(const QString &value);
              void rightfoot(const QString &value);
              void bottomleft(const QString &value);
              void bottomright(const QString &value);
              void pumpsignal(const QString &value);
              void sendValues(
                     const QString &comboBoxValue,
                      const QString &combo,
                     int dia,
                     int us1pow, int us1vac, int us1asp,
                     int us2pow, int us2vac, int us2asp,
                     int us3pow, int us3vac, int us3asp,
                     int us4pow, int us4vac, int us4asp,
                     int ia1vac, int ia1asp,
                     int ia2vac, int ia2asp,
                     int vitcut, int vitvac, int vitasp,
                     const QString &powmode,
                     const QString &vacmode,
                     const QString &powmethod,
                     const QString &us2powmode,
                     const QString &us2vacmode,
                     const QString &us2powermethod,
                     const QString &us3powmode,
                     const QString &us3vacmode,
                     const QString &us3powermethod,
                     const QString &us4powmode,
                     const QString &us4vacmode,
                     const QString &us4powermethod,
                     const QString &ia1mode,
                     const QString &ia2mode,
                     const QString &vitmode,
                     const QString &vitvacmode
                 );



private:
    Ui::doctor *ui;
    int value =0;
    keypad *key;
    int getvalue(int input);
    QMap<QString, QMap<int, QStringList>> surgeonData;
    QMap<QLineEdit*, int> lastValidValues;  // Declare the QMap as a member variable
    QMap<QLineEdit*, int> lastValidValues1;  // Declare the QMap as a member variable
    QSqlDatabase db;

};

#endif // DOCTOR_H
