#ifndef HELPP_H
#define HELPP_H


#include <QDialog>

namespace Ui {
class Helpp;
}

class Helpp : public QDialog
{
    Q_OBJECT

public:
    explicit Helpp(QWidget *parent = nullptr);
    ~Helpp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Helpp *ui;
};

#endif // HELPP_H
