#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    on_pb_clear_clicked();
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << event->key();
    switch (event->key())
    {
    case Qt::Key_0: on_pb_num0_clicked(); break;
    case Qt::Key_1: on_pb_num1_clicked(); break;
    case Qt::Key_2: on_pb_num2_clicked(); break;
    case Qt::Key_3: on_pb_num3_clicked(); break;
    case Qt::Key_4: on_pb_num4_clicked(); break;
    case Qt::Key_5: on_pb_num5_clicked(); break;
    case Qt::Key_6: on_pb_num6_clicked(); break;
    case Qt::Key_7: on_pb_num7_clicked(); break;
    case Qt::Key_8: on_pb_num8_clicked(); break;
    case Qt::Key_9: on_pb_num9_clicked(); break;

    case Qt::Key_Plus: on_pb_add_clicked(); break;
    case Qt::Key_Minus: on_pb_sub_clicked(); break;
    case Qt::Key_Asterisk: on_pb_mul_clicked(); break;
    case Qt::Key_Slash: on_pb_div_clicked(); break;

    case Qt::Key_Backspace: on_pb_back_clicked(); break;

    case Qt::Key_Return: on_pb_equal_clicked(); break;//
    case Qt::Key_Enter: on_pb_equal_clicked(); break;// 小键盘enter
    default:
        break;
    }
}


void Calculator::on_pb_equal_clicked()   // "="
{
    QString exp_text = m_exp;

    QStringList exp_list = exp_text.split(" ");
    QStringList list_except_add;
    qDebug() << exp_list;

    double value = exp_list[0].toDouble();
///////////////////////////先计算乘除 将加减保存到另一个字符串///////////////////////
    for(int i = 1; i < exp_list.length(); i += 2)
    {
        if(exp_list[i] == "+")
        {
            //value += exp_list[i + 1].toDouble();
            list_except_add.append(QString::number(value));
            list_except_add.append("+");
            value = exp_list[i + 1].toDouble();
        }else if(exp_list[i] == "-")
        {
            //value -= exp_list[i + 1].toDouble();
            list_except_add.append(QString::number(value));
            list_except_add.append("-");
            value = exp_list[i + 1].toDouble();
        }else if(exp_list[i] == "*")
        {
            value *= exp_list[i + 1].toDouble();
        }else if(exp_list[i] == "/")
        {
            value /= exp_list[i + 1].toDouble();
        }
    }
    list_except_add.append(QString::number(value));
    qDebug() << list_except_add;
////////////////////////////////////////计算加减////////////////////////////////////
    value = list_except_add[0].toDouble();

    for(int i = 1; i < list_except_add.length(); i += 2)
    {
        if(list_except_add[i] == "+")
        {
            value += list_except_add[i + 1].toDouble();
        }else if(list_except_add[i] == "-")
        {
            value -= list_except_add[i + 1].toDouble();
        }
    }
    qDebug() << value;
    ui->lb_result->setText(QString::number(value));
    m_exp.clear();
}


void Calculator::on_pb_clear_clicked()
{
    m_exp.clear();
    ui->lb_express->setText("0");
    ui->lb_result->setText("0");
}

void Calculator::on_pb_add_clicked()
{

    m_exp += " + ";
    ui->lb_express->setText(m_exp);
}


void Calculator::on_pb_sub_clicked()
{

    m_exp += " - ";
    ui->lb_express->setText(m_exp);
}


void Calculator::on_pb_mul_clicked()
{

    m_exp += " * ";
    ui->lb_express->setText(m_exp);
}


void Calculator::on_pb_div_clicked()
{

    m_exp += " / ";
    ui->lb_express->setText(m_exp);
}


void Calculator::on_pb_num0_clicked()
{

    m_exp += "0";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num1_clicked()
{

    m_exp += "1";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num2_clicked()
{

    m_exp += "2";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num3_clicked()
{

    m_exp += "3";
    ui->lb_express->setText(m_exp);
}


void Calculator::on_pb_num4_clicked()
{

    m_exp += "4";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num5_clicked()
{

    m_exp += "5";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num6_clicked()
{

    m_exp += "6";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num7_clicked()
{

    m_exp += "7";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num8_clicked()
{

    m_exp += "8";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_num9_clicked()
{

    m_exp += "9";
    ui->lb_express->setText(m_exp);
}

void Calculator::on_pb_dip_clicked()
{

    m_exp += ".";
    ui->lb_express->setText(m_exp);
}



void Calculator::on_pb_back_clicked()
{
    qDebug() << "before " << m_exp;

    if(m_exp[m_exp.length() - 1] == ' ')
    {
        m_exp.remove(m_exp.length() - 3, 3);

    }else
    {
        m_exp.remove(m_exp.length() - 1 , 1 );
    }

    qDebug() << "after " << m_exp;
    ui->lb_express->setText(m_exp);
}
