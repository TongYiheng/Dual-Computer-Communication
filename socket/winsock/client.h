#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <WinSock2.h>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <iostream>
#include <QDebug>
#include <QTextCodec>


namespace Ui {
class client;
}

extern Ui::client *uic;

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);

    ~client();

public slots:
    void getFilePath();

private slots:
    void on_connectButton_clicked();

    void on_sendMessageButton_clicked();

    void on_findFileButton_clicked();

    void on_sendFileButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::client *ui;
    SOCKET sockClient;
    SOCKET sockClientFile;
    static void* ctrlRecvMsg(void* args);
    static void* ctrlRecvFile(void* args);
    static client* MyPointer;
signals:
    void createQFileDialog();
};

void ui_init(Ui::client *ui_ptr);   //初始化指针uic

#endif // CLIENT_H
