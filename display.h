#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>

namespace Ui {
class display;
}

class display : public QDialog
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();

private slots:
    void BackBut();

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
