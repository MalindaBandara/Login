#include "countbill.h"
#include "ui_countbill.h"
#include "mainwindow.h"

Countbill::Countbill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Countbill)
{
    ui->setupUi(this);
}

Countbill::~Countbill()
{
    delete ui;
}

void Countbill::on_pushButton_clicked()
{
  //  QString unit = ui ->lineEdit ->text();
    int numofunit = ui->lineEdit->text().toInt();
    int bill = numofunit*10;// bill amount
    QString billam = QString::number(bill);// int bill value to string
    ui ->lineEdit_2 ->setText(billam);// display amount of bill


    //database connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("electricity");


    if(database.open()){


                // insert query
                QSqlQuery qry;

                qry.prepare("UPDATE user_reg_elec SET units='"+billam+"' WHERE username = '"+globelusername+"'");//update bill amount


                if(qry.exec()){

                QMessageBox::information(this, "Bill Amount", "This is new bill amount for used units");

                 hide();

                }

                else {
                            QMessageBox::information(this, "Data not inserted", "Not Sucessfully");
                }


    }
                else{

                QMessageBox::information(this, "ERROR","Database Not Connected Sucessfully. Please CheckYyour Internet Connection");


}
database.close();

}

void Countbill::on_pushButton_2_clicked()
{
    hide();
}
