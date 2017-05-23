#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QDialog(parent)
{
    userinfo = new QLabel("You are welcome!");
    line = new QLineEdit;
    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Stop and Escape");

    Ok->setDisabled(true);
    Cancel->setDisabled(true);
    line->setDisabled(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(userinfo);
    layout->addWidget(line);

    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addWidget(Ok);
    layout2->addWidget(Cancel);

    QHBoxLayout *mainlay = new QHBoxLayout;
    mainlay->addLayout(layout);
    mainlay->addLayout(layout2);

    Thief = false; alisset = false; aliswork = false;
    AlarmInfo = new QLabel; AlarmInfo->setText("Alarm isn't set");
    Set = new QPushButton("SET");
    Disable = new QPushButton("DISABLE");
    Stop = new QPushButton("STOP");
    ClientInfo = new QLabel("Quietly");

    Set->setDisabled(false);
    Disable->setDisabled(true);
    Stop->setDisabled(true);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(AlarmInfo);
    lay->addWidget(Set);
    lay->addWidget(Disable);
    lay->addWidget(Stop);
    lay->addWidget(ClientInfo);

    QHBoxLayout *RML = new QHBoxLayout;
    RML->addLayout(mainlay);
    RML->addLayout(lay);

    connect(Set,SIGNAL(clicked()),this,SLOT(Setclick()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(SOMEbody()));
    connect(Ok,SIGNAL(clicked()),this,SLOT(reactpass()));
    connect(Cancel,SIGNAL(clicked()),this,SLOT(userexit()));
    connect(Stop,SIGNAL(clicked()),this,SLOT(alstopped()));
    connect(Disable,SIGNAL(clicked()),this,SLOT(disabled()));

    setLayout(RML);

}
void MainWindow::alstopped()
{
    alisset=false; aliswork = false;
    line->setDisabled(true);
    Ok->setDisabled(true);

    Set->setEnabled(true);
    Disable->setEnabled(false);
    Stop->setEnabled(false);
    AlarmInfo->setText("Alarm isn't set");
    ClientInfo->setText("Quietly");

}
void MainWindow::disabled()
{
    alisset = false; aliswork = false;
    line->setEnabled(false);
    Set->setEnabled(true);
    Disable->setEnabled(false);
    Stop->setEnabled(false);
    AlarmInfo->setText("Alarm isn't set");
    userinfo->setText("You are welcome!");
    ClientInfo->setText("Quietly");
}
void MainWindow::userexit()
{
    line->clear();
    line->setEnabled(true);
    Ok->setDisabled(true);
    ClientInfo->setText("User escaped");
    Cancel->setEnabled(false);
    if(alisset)
    {
        userinfo->setText("Enter the password");
        Disable->setEnabled(true);
    }
    else
    {
        AlarmInfo->setText("Alarm isn't set");
        if(!aliswork)Set->setEnabled(true);
        userinfo->setText("You are welcome!");
    }
}
void MainWindow::Setclick()
{
    alisset=true;
    userinfo->setText("Enter the password");
    Cancel->setDisabled(false);
    line->setDisabled(false);
    AlarmInfo->setText("Alarm is set");
    Set->setDisabled(true);
    Disable->setDisabled(false);
}
void MainWindow::reactpass()
{
    if(!alisset)
        return;
    alisset = false;
    line->setEnabled(false);
    Ok->setEnabled(false);
    if(line->text()=="right_pass")
       {
        userinfo->setText("SUCCESS");
        AlarmInfo->setText("Alarm isn't set");
        line->clear();
        ClientInfo->setText("User inside");
        Ok->setDisabled(true);
        Disable->setDisabled(true);
    }
    else
    {
        aliswork = true;
        userinfo->setText("Loading...");
        AlarmInfo->setText("ALARM IS WORKING");
        Disable->setDisabled(true);
        Stop->setDisabled(false);
        ClientInfo->setText("There is f**king THIEF!");

    }
}
void MainWindow::SOMEbody()
{
    Ok->setEnabled(true);
    Cancel->setEnabled(true);
    ClientInfo->setText("Someone is typing a pass...");
}

