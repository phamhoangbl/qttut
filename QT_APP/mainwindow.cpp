#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

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

void MainWindow::on_myButton_clicked()
{
    ui->myLabel->setText("Hello World");
}

void MainWindow::on_messageBox_clicked()
{
    //QMessageBox::question(this, tr("The title"), tr("You just show a message"), QMessageBox::Yes, QMessageBox::No);

//    QMessageBox msgBox(QMessageBox::question(this, tr("This is title"), tr("You just show a message"), QMessageBox::Yes, QMessageBox::No));

//    if (msgBox.exec() == QMessageBox::No) {
//        return;
//    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("the title");
    msgBox.setIconPixmap(QPixmap(":/MyFiles/icon-messagebox.png"));
    msgBox.setText("You just show a message");
    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        ui->myLabel->setText(trUtf8("Đã chọn Yes"));
    }else {
        ui->myLabel->setText(trUtf8("Đã chọn No"));
    }
}

void MainWindow::on_dialog_clicked()
{
//    SecDialog secDialog;
//    secDialog.setModal(true);
//    secDialog.exec();
    secDialog = new SecDialog(this);
    secDialog->show();

}
