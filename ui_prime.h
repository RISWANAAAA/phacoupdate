/********************************************************************************
** Form generated from reading UI file 'prime.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIME_H
#define UI_PRIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prime
{
public:
    QPushButton *clean_but;
    QPushButton *Tune_but;
    QPushButton *prime1_but;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QLabel *process_lab_2;
    QPushButton *start_prime_but_2;
    QCheckBox *start_check_2;
    QCheckBox *wait_Check_2;
    QCheckBox *motor_Check_2;
    QCheckBox *done_Check_2;
    QProgressBar *progressBar_2;
    QPushButton *pushButton_5;
    QWidget *tab_7;
    QLabel *handpice_img_2;
    QPushButton *Start_tune_2;
    QLabel *tick_lab_2;
    QLabel *initial_lab_2;
    QLabel *label;
    QPushButton *pushButton_6;
    QProgressBar *progressBar;
    QWidget *tab_8;
    QLabel *warning_lab_2;
    QTextEdit *Instruction_lab_2;
    QPushButton *begin_clean_but_2;
    QLabel *warning_img_2;
    QLabel *label_10;
    QPushButton *pushButton_8;

    void setupUi(QWidget *prime)
    {
        if (prime->objectName().isEmpty())
            prime->setObjectName(QString::fromUtf8("prime"));
        prime->resize(1280, 720);
        prime->setStyleSheet(QString::fromUtf8("background-color:rgb(83, 104, 120);"));
        clean_but = new QPushButton(prime);
        clean_but->setObjectName(QString::fromUtf8("clean_but"));
        clean_but->setGeometry(QRect(140, 480, 151, 91));
        clean_but->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"\n"
"border-radius:20px;\n"
"border:none;\n"
"font:bold;\n"
"border:3px solid black;"));
        Tune_but = new QPushButton(prime);
        Tune_but->setObjectName(QString::fromUtf8("Tune_but"));
        Tune_but->setGeometry(QRect(140, 320, 161, 91));
        Tune_but->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"\n"
"border-radius:20px;\n"
"border:none;\n"
"font:bold;border:3px solid black;"));
        prime1_but = new QPushButton(prime);
        prime1_but->setObjectName(QString::fromUtf8("prime1_but"));
        prime1_but->setGeometry(QRect(140, 170, 161, 91));
        prime1_but->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"\n"
"border-radius:20px;\n"
"border:none;\n"
"font:bold;border:3px solid black;"));
        tabWidget = new QTabWidget(prime);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(420, 10, 861, 711));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tab_6->setStyleSheet(QString::fromUtf8("background-color:rgb(83, 104, 120);"));
        process_lab_2 = new QLabel(tab_6);
        process_lab_2->setObjectName(QString::fromUtf8("process_lab_2"));
        process_lab_2->setGeometry(QRect(140, 20, 351, 51));
        process_lab_2->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:20px;\n"
"border:none;font:bold;"));
        start_prime_but_2 = new QPushButton(tab_6);
        start_prime_but_2->setObjectName(QString::fromUtf8("start_prime_but_2"));
        start_prime_but_2->setGeometry(QRect(260, 540, 281, 71));
        start_prime_but_2->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(36, 31, 49);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"border:none;font:bold;"));
        start_check_2 = new QCheckBox(tab_6);
        start_check_2->setObjectName(QString::fromUtf8("start_check_2"));
        start_check_2->setGeometry(QRect(110, 160, 721, 51));
        start_check_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Ubuntu Mono\";\n"
"\n"
""));
        wait_Check_2 = new QCheckBox(tab_6);
        wait_Check_2->setObjectName(QString::fromUtf8("wait_Check_2"));
        wait_Check_2->setGeometry(QRect(110, 260, 751, 71));
        wait_Check_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Ubuntu Mono\";\n"
"\n"
""));
        motor_Check_2 = new QCheckBox(tab_6);
        motor_Check_2->setObjectName(QString::fromUtf8("motor_Check_2"));
        motor_Check_2->setGeometry(QRect(110, 70, 381, 61));
        motor_Check_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Ubuntu Mono\";\n"
"\n"
""));
        done_Check_2 = new QCheckBox(tab_6);
        done_Check_2->setObjectName(QString::fromUtf8("done_Check_2"));
        done_Check_2->setGeometry(QRect(110, 370, 321, 41));
        done_Check_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Ubuntu Mono\";\n"
""));
        progressBar_2 = new QProgressBar(tab_6);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(110, 480, 561, 23));
        progressBar_2->setValue(0);
        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(690, 530, 171, 141));
        pushButton_5->setStyleSheet(QString::fromUtf8("image: url(:/images/nextimg.png);\n"
"background-color:transparent;\n"
"border:none;"));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tab_7->setStyleSheet(QString::fromUtf8("background-color:rgb(83, 104, 120);"));
        handpice_img_2 = new QLabel(tab_7);
        handpice_img_2->setObjectName(QString::fromUtf8("handpice_img_2"));
        handpice_img_2->setGeometry(QRect(10, 20, 841, 361));
        handpice_img_2->setStyleSheet(QString::fromUtf8("image: url(:/images/handpiece1.png);\n"
"border:none;\n"
"background-color:transparent;"));
        Start_tune_2 = new QPushButton(tab_7);
        Start_tune_2->setObjectName(QString::fromUtf8("Start_tune_2"));
        Start_tune_2->setGeometry(QRect(260, 510, 281, 71));
        Start_tune_2->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(36, 31, 49);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"border:none;\n"
"font:bold;"));
        tick_lab_2 = new QLabel(tab_7);
        tick_lab_2->setObjectName(QString::fromUtf8("tick_lab_2"));
        tick_lab_2->setGeometry(QRect(790, 420, 51, 41));
        tick_lab_2->setStyleSheet(QString::fromUtf8("\n"
"background-color:transparent;"));
        initial_lab_2 = new QLabel(tab_7);
        initial_lab_2->setObjectName(QString::fromUtf8("initial_lab_2"));
        initial_lab_2->setGeometry(QRect(20, 430, 31, 31));
        initial_lab_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        label = new QLabel(tab_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(710, 150, 111, 91));
        label->setStyleSheet(QString::fromUtf8(""));
        pushButton_6 = new QPushButton(tab_7);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(680, 530, 171, 151));
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/images/nextimg.png);\n"
"background-color:transparent;\n"
"border:none;"));
        progressBar = new QProgressBar(tab_7);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 432, 721, 31));
        progressBar->setValue(0);
        tabWidget->addTab(tab_7, QString());
        handpice_img_2->raise();
        Start_tune_2->raise();
        tick_lab_2->raise();
        initial_lab_2->raise();
        pushButton_6->raise();
        progressBar->raise();
        label->raise();
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tab_8->setStyleSheet(QString::fromUtf8("background-color:rgb(83, 104, 120);"));
        warning_lab_2 = new QLabel(tab_8);
        warning_lab_2->setObjectName(QString::fromUtf8("warning_lab_2"));
        warning_lab_2->setGeometry(QRect(50, 60, 431, 41));
        warning_lab_2->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(36, 31, 49);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"border:none;\n"
"font:bold;"));
        Instruction_lab_2 = new QTextEdit(tab_8);
        Instruction_lab_2->setObjectName(QString::fromUtf8("Instruction_lab_2"));
        Instruction_lab_2->setGeometry(QRect(110, 210, 741, 281));
        Instruction_lab_2->setStyleSheet(QString::fromUtf8("\n"
"font:20px;border:none;\n"
"background-color: transparent;\n"
""));
        begin_clean_but_2 = new QPushButton(tab_8);
        begin_clean_but_2->setObjectName(QString::fromUtf8("begin_clean_but_2"));
        begin_clean_but_2->setGeometry(QRect(300, 520, 291, 71));
        begin_clean_but_2->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(36, 31, 49);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:20px;\n"
"border:none;"));
        warning_img_2 = new QLabel(tab_8);
        warning_img_2->setObjectName(QString::fromUtf8("warning_img_2"));
        warning_img_2->setGeometry(QRect(70, 60, 31, 41));
        warning_img_2->setStyleSheet(QString::fromUtf8("image: url(:/images/warning1.png);\n"
"BACKGROUND-COLOR:TRANSPARENT;"));
        label_10 = new QLabel(tab_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 130, 651, 51));
        label_10->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;"));
        pushButton_8 = new QPushButton(tab_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(700, 540, 151, 141));
        pushButton_8->setStyleSheet(QString::fromUtf8("image: url(:/images/backimg.png);\n"
"border:none;\n"
"background-color:transparent;"));
        tabWidget->addTab(tab_8, QString());

        retranslateUi(prime);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(prime);
    } // setupUi

    void retranslateUi(QWidget *prime)
    {
        prime->setWindowTitle(QCoreApplication::translate("prime", "Form", nullptr));
        clean_but->setText(QCoreApplication::translate("prime", "CLEAN", nullptr));
        Tune_but->setText(QCoreApplication::translate("prime", "TUNE", nullptr));
        prime1_but->setText(QCoreApplication::translate("prime", "PRIME", nullptr));
        process_lab_2->setText(QCoreApplication::translate("prime", "     PROCESS ", nullptr));
        start_prime_but_2->setText(QCoreApplication::translate("prime", "START PRIME", nullptr));
        start_check_2->setText(QCoreApplication::translate("prime", "Start Irrigation Valve", nullptr));
        wait_Check_2->setText(QCoreApplication::translate("prime", "Wait For Chamber To Be Filled", nullptr));
        motor_Check_2->setText(QCoreApplication::translate("prime", "Start Motor", nullptr));
        done_Check_2->setText(QCoreApplication::translate("prime", "Done", nullptr));
        pushButton_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("prime", "Tab 1", nullptr));
        handpice_img_2->setText(QString());
        Start_tune_2->setText(QCoreApplication::translate("prime", "START TUNING ", nullptr));
        tick_lab_2->setText(QString());
        initial_lab_2->setText(QCoreApplication::translate("prime", "0", nullptr));
        label->setText(QString());
        pushButton_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("prime", "Tab 2", nullptr));
        warning_lab_2->setText(QCoreApplication::translate("prime", "   BEFORE CLEANING", nullptr));
        Instruction_lab_2->setHtml(QCoreApplication::translate("prime", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">1.Disconnect the Irrigation/Aspiration connectors from handpiece</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">2.Connect the irrigation,aspiration connectors together</span></p>\n"
"<p s"
                        "tyle=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">3.Disconnect the saline connection from irrigation.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">4.Disconnect the tubing from irriagtion valve.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weigh"
                        "t:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">5.dip the irrigation connector in distilled water bowl</span></p></body></html>", nullptr));
        begin_clean_but_2->setText(QCoreApplication::translate("prime", "Begin Clean", nullptr));
        warning_img_2->setText(QString());
        label_10->setText(QCoreApplication::translate("prime", " Instructions To Be Followed:", nullptr));
        pushButton_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("prime", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prime: public Ui_prime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIME_H
