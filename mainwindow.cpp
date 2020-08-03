    #include "mainwindow.h"
    #include "ui_mainwindow.h"

    QString globelusername;


    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        ui ->loginusername->setPlaceholderText("Username");
        ui ->loginpassword->setPlaceholderText("Password");

    }

    MainWindow::~MainWindow()
    {
        delete ui;

        }


    void MainWindow::on_pushButton_clicked()// new registration
    {
            //open new registration in new window
       // hide();
       // regist = new Register(this);
      //  regist ->show();
        Register regis;
        regis.setModal(true);
        regis.exec();


    }

     void MainWindow::on_pushButton_2_clicked()
    {
        //database connection
        QSqlDatabase db;
         db = QSqlDatabase ::addDatabase("QMYSQL");
         db.setHostName("localhost");
         db.setUserName("root");
         db.setPassword("");
         db.setDatabaseName("electricity");



         QString username = ui ->loginusername ->text();
         QString password = ui ->loginpassword ->text();

         if(db.open()){

             //query create

           //  QMessageBox::information(this, "Sucessfull ","Sucessfully Connect the Database");

             QSqlQuery query(QSqlDatabase::database("MyConnect"));

             query.prepare(QString("SELECT * FROM user_reg_elec WHERE username = :username AND password = :password"));

             query.bindValue(":username", username);
             query.bindValue(":password", password);


            globelusername = username; //globlevariable

        // check query


         if(!query.exec()){

         QMessageBox::information(this, "Failed", "Query Failed To Execute");
         }

         else {

             while (query.next()) {
                 QString usernameFromDB = query.value(1).toString();
                 QString passwordFromDB = query.value(2).toString();

                 if(usernameFromDB == username && passwordFromDB == password){

                     //QMessageBox::information(this, "Success", "login Success");


                    //hide user login window and display user details window
                     hide();
                     userdetails = new Userdetails(this);
                     userdetails ->show();

                     //Userdetails userdetails;
                    // userdetails.setModal(true);
                     //userdetails.exec();
                 }

                 else {

                      QMessageBox::information(this, "Failed", "login Failed Pleace Check Your Username and Password");
                 }

             }

         }


     }

     else{

     QMessageBox::information(this, "ERROR (Databae Connection)","Database Connection Failed");


     }database.close();



}

void MainWindow::on_pushButton_3_clicked()//help button login
{
    Helpp helpp;
    helpp.setModal(true);
    helpp.exec();
}
