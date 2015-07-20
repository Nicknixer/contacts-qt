#include "addform.h"
#include "ui_addform.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

addForm::addForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addForm)
{
    ui->setupUi(this);

}

addForm::~addForm()
{
    delete ui;
}
void addForm::msg(QString arg)
{
    QMessageBox ms;
    ms.setText(arg);
    ms.exec();
    return;
}

void addForm::on_butClear_clicked()
{
    ui->lNick->clear();
    ui->lName->clear();
    ui->lFathername->clear();
    ui->lFamily->clear();
    ui->lCity->clear();
    ui->lICQ->clear();
    ui->lVK->setText("http://vk.com/");
    ui->lOK->setText("http://ok.ru/profile/");
    ui->lFacebook->setText("https://fb.com/profile.php?id=");
    ui->lMail->clear();
    ui->lPhone->clear();
    ui->lInfo->clear();
}

void addForm::on_butCancel_clicked()
{
    this->close();
}

void addForm::add_contact()
{
    QFile fileNewContact("Contacts/"+ui->lName->text().simplified()+" "+ui->lNick->text().simplified());
    if(fileNewContact.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream sout(&fileNewContact);
        sout<<ui->lNick->text().simplified()<<endl
           << ui->lName->text().simplified()<<endl
           << ui->lFathername->text().simplified()<<endl
           << ui->lFamily->text().simplified()<<endl
           << ui->lCity->text().simplified()<<endl
           << ui->lICQ->text().simplified()<<endl
           << ui->lVK->text().simplified()<<endl
           << ui->lOK->text().simplified()<<endl
           << ui->lFacebook->text().simplified()<<endl
           << ui->lPhone->text().simplified()<<endl
           << ui->lMail->text().simplified()<<endl
           << ui->lInfo->toPlainText().simplified()<<endl;
    }
    fileNewContact.close();
    emit closing();
    this->close();
}


void addForm::on_butAdd_clicked()
{

    if(ui->lName->text().simplified() == "")
    {
        msg(trUtf8("Поле <b>Имя</b> не должно быть пустым."));
        return;
    }
    if(ui->lNick->text().simplified() == "")
    {
        msg(trUtf8("Поле <b>Никнейм</b> не должно быть пустым."));
        return;
    }
    if(QFile::exists("Contacts/"+ui->lName->text().simplified()+" "+ui->lNick->text().simplified()))
    {
        QMessageBox* pmbx =
                            new QMessageBox(trUtf8("Добавление контакта"),
                            trUtf8("Контакт с таким <b>именем</b> и <b>никнеймом</b> уже существует, вы желаете перезаписать его?"),
                            QMessageBox::Question,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        int n = pmbx->exec();
        delete pmbx;
        if (n == QMessageBox::Yes)
        {
            add_contact();
        }
    }
    else
    {
        add_contact();
    }
}
