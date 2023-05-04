#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->Display->setSmallDecimalPoint(true);
    ui->Display->setMode(QLCDNumber::Dec);
    ui->Display->setDigitCount(16);
}

void MainWindow::display_res(){
    while (m_display.size()>16)
        m_display.chop(1);
    ui->Display->display(m_display);
}

void MainWindow::do_ar_op(){
    switch (temp_op){
    case Operation::NOPE:
        answer = m_display.toDouble();
        m_display = "0";
        break;

    case Operation::PLUS:
        answer += m_display.toDouble();
        m_display = m_display.number(answer);
        display_res(); m_display = "0";
        break;

    case Operation::MINUS:
        answer -= m_display.toDouble();
        m_display = m_display.number(answer);
        display_res(); m_display = "0";
        break;

    case Operation::MULT:
        answer *= m_display.toDouble();
        m_display = m_display.number(answer);
        display_res(); m_display = "0";
        break;

    case Operation::DIV:
        if ((m_display == "0")||(m_display == "")){ m_display = "Error"; }
        else {answer /= m_display.toDouble(); m_display = m_display.number(answer);}
        display_res(); m_display = "0";
        break;
    default: ;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_1_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "1";
    else m_display+='1';
    display_res();
}


void MainWindow::on_Button_2_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "2";
    else m_display+='2';
    display_res();
}


void MainWindow::on_Button_3_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "3";
    else m_display+='3';
    display_res();
}


void MainWindow::on_Button_4_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "4";
    else m_display+='4';
    display_res();
}


void MainWindow::on_Button_5_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "5";
    else m_display+='5';
    display_res();
}


void MainWindow::on_Button_6_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "6";
    else m_display+='6';
    display_res();
}


void MainWindow::on_Button_7_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "7";
    else m_display+='7';
    display_res();
}


void MainWindow::on_Button_8_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "8";
    else m_display+='8';
    display_res();
}


void MainWindow::on_Button_9_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "9";
    else m_display+='9';
    display_res();
}


void MainWindow::on_Button_0_clicked()
{
    if ((m_display == "") || (m_display == "0"))
        m_display = "0";
    else m_display+='0';
    display_res();
}


void MainWindow::on_B_Backspace_clicked()
{
    if ((m_display != "") && (m_display!="0"))
        m_display.chop(1);
    else
        m_display = "0";

    display_res();
}



void MainWindow::on_B_Clear_clicked()
{
    m_display = "0";
    display_res();
}


void MainWindow::on_B_Clear_All_clicked()
{
    m_display = "0";
    answer = 0;
    temp_op = NOPE;
    display_res();
}


void MainWindow::on_B_plus_clicked()
{
    do_ar_op();
    temp_op = PLUS;
}


void MainWindow::on_B_sub_clicked()
{
    do_ar_op();
    temp_op = MINUS;
}


void MainWindow::on_B_mult_clicked()
{
    do_ar_op();
    temp_op = MULT;
}


void MainWindow::on_B_div_clicked()
{
    do_ar_op();
    temp_op = DIV;
}


void MainWindow::on_B_res_clicked()
{
    do_ar_op();
    temp_op = NOPE;
}


void MainWindow::on_B_inv_clicked()
{
    if (m_display.toDouble()!=0)
        m_display = m_display.number(1/m_display.toDouble());
    display_res();
}


void MainWindow::on_B_Sqr_clicked()
{
    m_display = m_display.number(m_display.toDouble()*m_display.toDouble());
    display_res();
}


void MainWindow::on_B_Sqrt_clicked()
{
    if (m_display.toDouble()>=0){
        m_display = m_display.number(sqrt(m_display.toDouble()));
        display_res();
    }
    else
    {
        m_display = "Error";
        display_res();
        m_display = "0";
    }

}


void MainWindow::on_B_change_m_clicked()
{
    m_display = m_display.number(m_display.toDouble()*(-1));
    display_res();
}


void MainWindow::on_B_point_clicked()
{
    if (m_display.contains('.') == 0)
        m_display+='.';
    display_res();
}


void MainWindow::on_B_MC_clicked()
{
    memory_slot = 0;
}


void MainWindow::on_B_MR_clicked()
{
    m_display = m_display.number(memory_slot);
    display_res();
}


void MainWindow::on_B_MS_clicked()
{
    memory_slot = answer;
}


void MainWindow::on_B_MAdd_clicked()
{
    memory_slot += m_display.toDouble();
    m_display = "0";
    display_res();
}

