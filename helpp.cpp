#include "helpp.h"
#include "ui_helpp.h"
#include "mainwindow.h"

Helpp::Helpp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Helpp)
{
    ui->setupUi(this);
}

Helpp::~Helpp()
{
    delete ui;
}

void Helpp::on_pushButton_clicked()
{
    hide();
}
