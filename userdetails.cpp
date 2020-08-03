    #include "userdetails.h"
    #include "ui_userdetails.h"
    #include <QSqlError>
    #include "mainwindow.h"
    #include <iostream>


    Userdetails::Userdetails(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Userdetails)

    {
        ui->setupUi(this);

    }

    Userdetails::~Userdetails()
    {

    }

    void Userdetails::on_pushButton_3_clicked() //count bill button
    {
       // open countbill window without closing userdetails
        Countbill countbill;
        countbill.setModal(true);
        countbill.exec();
    }

    void Userdetails::on_pushButton_4_clicked()
    {

        {
                // database connection
                QSqlDatabase database;
                database = QSqlDatabase::addDatabase("QMYSQL","MyConnect");
                database.setHostName("localhost");
                database.setUserName("root");
                database.setPassword("");
                database.setDatabaseName("electricity");


            if(database.open()) {

                QSqlQuery query(database);


                if (query.prepare(QString("SELECT accno, fullname, address, telephone, units FROM user_reg_elec WHERE username = :username "))) {

                    //Add bindings
                    query.bindValue(":username",globelusername);//username value from mainwindow.cpp

                    if(query.exec()) {

                        while(query.next()) {
                            ui ->dislayaccountnumber ->setText(query.value(0).toString());
                            ui ->displayname ->setText(query.value(1).toString());
                            ui ->displayaddress ->setText(query.value(2).toString());
                            ui ->displattelephoneno ->setText(query.value(3).toString());
                            ui ->displayamountoebill ->setText(query.value(4).toString());
                        }
                    } else {
                        qDebug() << "Query did not execute due to: " << query.lastError().text();
                        QMessageBox::information(this, "Query did not execute", "Not successful executing the query");
                    }
                } else {
                    qDebug() << "Query not prepared due to the following error: " << query.lastError().text();
                }
            } else {
                qDebug() << "Database not opened due to: " << database.lastError().text();
                QMessageBox::information(this, "Database not open", "Not opened successfully");
            }

            database.close();
        }

        QSqlDatabase::removeDatabase("MyConnect");

}

void Userdetails::on_pushButton_2_clicked() //help button
{
    Helpp helpp;
    helpp.setModal(true);
    helpp.exec();

}

void Userdetails::on_pushButton_clicked()//exet button
{
    close();
}
