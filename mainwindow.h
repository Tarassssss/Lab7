#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>>
#include <QCheckBox>
#include <QPushButton>>
#include <QHBoxLayout>>
#include <QVBoxLayout>>
#include <QWidget>


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);


    QLabel *userinfo;
    QLineEdit *line;
    QPushButton *Ok;
    QPushButton *Cancel;
private:
    bool Thief;
    bool alisset;
    bool aliswork;
    QLabel *AlarmInfo;
    QPushButton *Set;
    QPushButton *Disable;
    QPushButton *Stop;
    QLabel *ClientInfo;
public slots:
    void reactpass();
    void Setclick();
    void SOMEbody();
    void userexit();
    void alstopped();
    void disabled();
    //void reactset(ChangeDim&);
};

#endif // MAINWINDOW_H
