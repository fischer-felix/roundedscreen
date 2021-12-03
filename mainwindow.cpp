#include "mainwindow.h"

#include <QApplication>
#include <QPainter>
#include <QScreen>

MainWindow::MainWindow(QMainWindow *parent, unsigned short corner)
    : QMainWindow(parent)
{
    this->corner = corner;

    setWindowFlag(Qt::Tool);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QPalette pal = palette();
    pal.setColor(QPalette::Window,QColor(0,0,0,0));
    setPalette(pal);

    if (corner == 0) {
        setWindowTitle("Left_Top");
        setGeometry(1920,0,24,24);
    } else if (corner == 1) {
        setWindowTitle("Right_Top");
        setGeometry(1920+1920-24,0,24,24);
    } else if (corner == 2) {
        setWindowTitle("Left_Bottom");
        setGeometry(1920,1080-24,24,24);
    } else if (corner == 3) {
        setWindowTitle("Right_Bottom");
        setGeometry(1920+1920-24,1080-24,24,24);
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // setup painter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(QBrush(QColor(0,0,0,255)));
    painter.setPen(QPen(QColor(0,0,0,255),10));

    if (corner == 0) painter.drawArc(-5,-5,width()+10,height()+10,1600,1000);
    if (corner == 1) painter.drawArc(-5,-5,width()+10,height()+10,0,1200);
    if (corner == 2) painter.drawArc(-5,-5,width()+10,height()+10,2900,1200);
    if (corner == 3) painter.drawArc(-5,-5,width()+10,height()+10,-1300,1200);
}

