#ifndef USERDETAILS_H
#define USERDETAILS_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "helpp.h"
#include "countbill.h"




namespace Ui {
class Userdetails;
}

class Userdetails : public QDialog
{




    Q_OBJECT

public:
    explicit Userdetails(QWidget *parent = nullptr);
    ~Userdetails();

    QString username;
    QString password;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Userdetails *ui;
    QSqlDatabase databasse;
    Countbill *countbill;
    Helpp *helpp;


};

#endif // USERDETAILS_H
