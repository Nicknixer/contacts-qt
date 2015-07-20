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
        if (ui->lVK->text() == "http://vk.com/")
        {
            ui->lVK->clear();
        }
        else
        {
            ui->lVK->setText("<a href='"+ui->lVK->text()+"'>"+ui->lVK->text()+"</a>");
        }


        ui->lOK->setText(stream.readLine());
        if(ui->lOK->text() == "http://ok.ru/profile/")
        {
                ui->lOK->clear();
        }
                else
        {
                ui->lOK->setText("<a href='"+ui->lOK->text()+"'>"+ui->lOK->text()+"</a>");
        }



        ui->lFaceBook->setText(stream.readLine());
        if(ui->lFaceBook->text() == "https://fb.com/profile.php?id=")
        {
            ui->lFaceBook->clear();
        }
        else
        {
            ui->lFaceBook->setText("<a href='"+ui->lFaceBook->text()+"'>"+ui->lFaceBook->text()+"</a>");
        }


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

void MainWindow::on_action_4_triggered()
{
    about_form = new about();
    about_form->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem *item = ui->listContacts->currentItem();
    QMessageBox* pmbx =
                        new QMessageBox(trUtf8("Удаление контакта"),
                        trUtf8("Вы действительно хотите удалить <b>") + item->text() + "</b>?",
                        QMessageBox::Question,
                        QMessageBox::Yes,
                        QMessageBox::No,
                        QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Yes)
    {
        QFile("Contacts/"+item->text()).remove();
        ui->listContacts->takeItem(ui->listContacts->currentRow());
    }


}
