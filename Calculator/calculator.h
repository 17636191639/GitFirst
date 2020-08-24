#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_pb_num0_clicked();
    void on_pb_num1_clicked();
    void on_pb_num2_clicked();
    void on_pb_num3_clicked();
    void on_pb_num4_clicked();
    void on_pb_num5_clicked();
    void on_pb_num6_clicked();
    void on_pb_num7_clicked();
    void on_pb_num8_clicked();
    void on_pb_num9_clicked();


    void on_pb_add_clicked();
    void on_pb_sub_clicked();
    void on_pb_mul_clicked();
    void on_pb_div_clicked();

    void on_pb_equal_clicked();

    void on_pb_clear_clicked();

    void on_pb_dip_clicked();



    void on_pb_back_clicked();

private:
    Ui::Calculator *ui;
    QString m_exp;
};

#endif // CALCULATOR_H
