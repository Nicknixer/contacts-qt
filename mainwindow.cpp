#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir().mkdir("Contacts");
    updateList();
//    addF = new addForm();
//    addF ->show();
}

void MainWindow::updateList()
{
    ui->listContacts->clear();
    QDir dr("Contacts");
    ls = dr.entryList(QStringList("*"),QDir::Files);
    ui->listContacts->insertItems(0, ls);
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::formAddContactClose()
{
    updateList();
}

void MainWindow::on_listContacts_itemClicked(QListWidgetItem *item)
{
    QFile fileContact("Contacts/"+item->text());
    if(fileContact.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&fileContact);
        ui->lNick->setText(stream.readLine());
        ui->lName->setText(stream.readLine());
        ui->lFatherName->setText(stream.readLine());
        ui->lFamily->setText(stream.readLine());
        ui->lCity->setText(stream.readLine());
        ui->lICQ->setText(stream.readLine());

        ui->lVK->setText(stream.readLine());
        ui->lVK->setText("<a href='"+ui->lVK->text()+"'>"+ui->lVK->text()+"</a>");
        ui->lVK->setOpenExternalLinks(true);

        ui->lOK->setText(stream.readLine());
        ui->lOK->setText("<a href='"+ui->lOK->text()+"'>"+ui->lOK->text()+"</a>");
        ui->lOK->setOpenExternalLinks(true);


        ui->lFaceBook->setText(stream.readLine());
        ui->lFaceBook->setText("<a href='"+ui->lFaceBook->text()+"'>"+ui->lFaceBook->text()+"</a>");
        ui->lFaceBook->setOpenExternalLinks(true);

        ui->lPhone->setText(stream.readLine());
        ui->lMail->setText(stream.readLine());
        ui->lInfo->setText(stream.readLine());
    }
}



void MainWindow::on_butAddContact_clicked()
{
    addF = new addForm();
    addF->show();
    connect(addF,SIGNAL(closing()),this,SLOT(formAddContactClose()));


}


void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_action_3_triggered()
{
    emit on_butAddContact_clicked();
}
