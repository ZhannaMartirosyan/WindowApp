#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = std::vector<Car> ();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(0);
    std::ifstream fin;

    fin.open("test.txt");
    std::string mod;
    int speed;
    int pass;
    int maxsp;
    int maxps;
    if(!fin)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("File not found!");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
    else {
        std::string test;
        while(!fin.eof())
        {
            fin >> speed;
            fin >> maxsp;
            fin >> pass;
            fin >> maxps;
            fin >> mod;

            int rows = ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(rows+1);

            QString qmod = QString::fromStdString(mod);
            Car tmp = Car(qmod, maxsp, maxps);
            tmp.SetPass(pass);
            tmp.SetSpeed(speed);
            data.push_back(tmp);

            QTableWidgetItem *newItem = new QTableWidgetItem(qmod);
            ui->tableWidget->setItem(rows, 0, newItem);
            newItem = new QTableWidgetItem(QString::number(tmp.GetSpeed()));
            ui->tableWidget->setItem(rows, 1, newItem);
            newItem = new QTableWidgetItem(QString::number(tmp.GetPass()));
            ui->tableWidget->setItem(rows, 2, newItem);
            newItem = new QTableWidgetItem(QString::number(maxsp));
            ui->tableWidget->setItem(rows, 3, newItem);
            newItem = new QTableWidgetItem(QString::number(maxps));
            ui->tableWidget->setItem(rows, 4, newItem);

    }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString mod = ui->ModelEdit->text();
    int speed = ui->SpeedEdit->text().toInt();
    int pass = ui->PassEdit->text().toInt();
    int maxsp = ui->MaxspeedEdit->text().toInt();
    int maxps = ui->MaxpassEdit->text().toInt();

    int rows = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rows+1);

    Car tmp = Car(mod, maxsp, maxps);
    tmp.SetPass(pass);
    tmp.SetSpeed(speed);
    data.push_back(tmp);

    QTableWidgetItem *newItem = new QTableWidgetItem(mod);
    ui->tableWidget->setItem(rows, 0, newItem);
    newItem = new QTableWidgetItem(QString::number(tmp.GetSpeed()));
    ui->tableWidget->setItem(rows, 1, newItem);
    newItem = new QTableWidgetItem(QString::number(tmp.GetPass()));
    ui->tableWidget->setItem(rows, 2, newItem);
    newItem = new QTableWidgetItem(QString::number(maxsp));
    ui->tableWidget->setItem(rows, 3, newItem);
    newItem = new QTableWidgetItem(QString::number(maxps));
    ui->tableWidget->setItem(rows, 4, newItem);

//    data.push_back(ui->lineEdit->text().toStdString());
}

void MainWindow::on_pushButton_2_clicked()
{
    int rows = ui->tableWidget->rowCount();
    ui->tableWidget->removeRow(rows-1);
}

void MainWindow::SaveData(std::string file)
{
        std::ofstream fout;
        fout.open(file, std::ios_base::app);
        for(int i = 0; i <data.size(); i++)
        {
            fout<<data[i].GetString()<<"\n";
        }
        fout.close();

}

void MainWindow::on_pushButton_3_clicked()
{
        SaveData("test.txt");
}
