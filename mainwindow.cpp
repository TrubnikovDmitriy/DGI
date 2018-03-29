#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int comparator(const void* left, const void* right) {
    QString left_str = *(QString*)left;
    QString right_str = *(QString*)right;
    return (left_str > right_str);
}

void MainWindow::on_pushButton_clicked()
{
    QStringList list = ui->plainTextEdit->toPlainText().split('\n');



    qsort(&list[0], list.size(), sizeof(list[0]), comparator);

    ui->plainTextEdit->clear();
    for (int i = 0; i < list.size(); ++i) {
        qDebug() << list[i];
        ui->plainTextEdit->appendPlainText(list[i]);
    }
}
