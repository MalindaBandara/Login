#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    //database connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("electricity");


    if(database.open()){

                QString username = ui ->lineEdit ->text();
                QString password = ui ->lineEdit_2 ->text();
                QString fullname = ui ->lineEdit_3 ->text();
                QString address = ui ->lineEdit_4 ->text();
                QString telephone = ui ->lineEdit_5 ->text();
               // QString units = ui ->lineEdit_6 ->text();


                // insert query
                QSqlQuery qry;

                qry.prepare("INSERT INTO user_reg_elec (username, password, fullname, address, telephone)"// database table
                            "VALUES (:username, :password, :fullname, :address, :telephone)");     // user input values

                qry.bindValue(":username", username);
                qry.bindValue(":password", password);
                qry.bindValue(":fullname", fullname);
                qry.bindValue(":address", address);
                qry.bindValue(":telephone", telephone);
              //  qry.bindValue(":units", units);

                //check if username is exists
                QSqlQuery query(QSqlDatabase::database("MyConnect"));

                query.prepare(QString("SELECT * FROM user_reg_elec WHERE username = :username "));

                query.bindValue(":username", username);

                //end

                if(qry.exec()){

                QMessageBox::information(this, "Data Insetrted", "Data Entered Sucessfully");
                //hide user login window and display user details window
                 hide();
                // mainwindow = new Userdetails(this);
                // mainwindow ->show();
                }

                else if (query.exec())
                {
                    QMessageBox::information(this, "Error", "User Name is Already Exits");
                }
                else {
                            QMessageBox::information(this, "Data not inserted", "Not Sucessfully");
                }


    }
                else{

                QMessageBox::information(this, "ERROR","Database Not Connected Sucessfully. Please CheckYyour Internet Connection");


}


}
