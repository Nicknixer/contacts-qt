#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include <QDir>
#include <QMessageBox>
namespace Ui {
class addForm;
}

class addForm : public QWidget
{
    Q_OBJECT

public:
    explicit addForm(QWidget *parent = 0);
    ~addForm();

private slots:
    void on_butClear_clicked();

    void on_butCancel_clicked();

    void on_butAdd_clicked();
signals:
    void closing();

private:
    Ui::addForm *ui;
    void msg(QString arg);
    void add_contact();
};

#endif // ADDFORM_H
