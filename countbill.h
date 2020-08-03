#ifndef COUNTBILL_H
#define COUNTBILL_H

#include <QDialog>

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Countbill;
}

class Countbill : public QDialog
{
    Q_OBJECT

public:
    explicit Countbill(QWidget *parent = nullptr);
    ~Countbill();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Countbill *ui;
    QSqlDatabase database;
};

#endif // COUNTBILL_H
