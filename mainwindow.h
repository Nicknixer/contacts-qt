#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addform.h>
#include <QListWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

private slots:

    void on_listContacts_itemClicked(QListWidgetItem *item);

    void on_butAddContact_clicked();


    void on_actionQuit_triggered();

    void formAddContactClose();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
    addForm *addF;
    void updateList();
    QStringList ls;
};

#endif // MAINWINDOW_H
