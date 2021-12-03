#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    unsigned short corner;

public:
    MainWindow(QMainWindow *parent = nullptr, unsigned short corner = 0);
    ~MainWindow();

protected:
    virtual void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
