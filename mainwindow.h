#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "register.h"
#include "userdetails.h"
//#include <QtSql>
//#include <QSqlDatabase>
//#include <QMessageBox>

extern QString globelusername;//


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


//QString username;
//QString password;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Register *regist;
    Userdetails *userdetails;
    QSqlDatabase database;

};
#endif // MAINWINDOW_H
