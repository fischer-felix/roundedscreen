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
    setWindowFlag(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlag(Qt::WindowTransparentForInput, true);

    QPalette pal = palette();
    pal.setColor(QPalette::Window,QColor(0,0,0,0));
    setPalette(pal);

    if (corner == 0) {
        setWindowTitle("Left_Top_1");
        setGeometry(0,0,24,24);
    } else if (corner == 1) {
        setWindowTitle("Right_Top_1");
        setGeometry(QApplication::primaryScreen()->size().width()-24,0,24,24);
    } else if (corner == 2) {
        setWindowTitle("Left_Bottom_1");
        setGeometry(0,QApplication::primaryScreen()->size().height()-24,24,24);
    } else if (corner == 3) {
        setWindowTitle("Right_Bottom_1");
        setGeometry(QApplication::primaryScreen()->size().width()-24,QApplication::primaryScreen()->size().height()-24,24,24);
    } 

    else if (corner == 4) {
        setWindowTitle("Left_Top_2");
        setGeometry(QApplication::primaryScreen()->size().width()+0,0,24,24);
    } else if (corner == 5) {
        setWindowTitle("Right_Top_2");
        setGeometry(QApplication::primaryScreen()->size().width()+QApplication::primaryScreen()->size().width()-24,0,24,24);
    } else if (corner == 6) {
        setWindowTitle("Left_Bottom_2");
        setGeometry(QApplication::primaryScreen()->size().width()+0,QApplication::primaryScreen()->size().height()-24,24,24);
    } else if (corner == 7) {
        setWindowTitle("Right_Bottom_2");
        setGeometry(QApplication::primaryScreen()->size().width()+QApplication::primaryScreen()->size().width()-24,QApplication::primaryScreen()->size().height()-24,24,24);
    } 

    else if (corner == 8) {
        setWindowTitle("Left_Top_3");
        setGeometry(3840,0,24,24);
    } else if (corner == 9) {
        setWindowTitle("Right_Top_3");
        setGeometry(4866,0,24,24);
    } else if (corner == 10) {
        setWindowTitle("Left_Bottom_3");
        setGeometry(3840,1656,24,24);
    } else if (corner == 11) {
        setWindowTitle("Right_Bottom_3");
        setGeometry(4866,1656,24,24);
    }
}

MainWindow::~MainWindow()
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // setup painter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    painter.setBrush(QBrush(QColor(0,0,0,255)));
    painter.setPen(QPen(QColor(0,0,0,255),10));

    if (corner == 0) painter.drawArc(-5,-5,width()+10,height()+10,1600,1000);
    if (corner == 1) painter.drawArc(-5,-5,width()+10,height()+10,0,1200);
    if (corner == 2) painter.drawArc(-5,-5,width()+10,height()+10,2900,1200);
    if (corner == 3) painter.drawArc(-5,-5,width()+10,height()+10,-1300,1200);
    if (corner == 4) painter.drawArc(-5,-5,width()+10,height()+10,1600,1000);
    if (corner == 5) painter.drawArc(-5,-5,width()+10,height()+10,0,1200);
    if (corner == 6) painter.drawArc(-5,-5,width()+10,height()+10,2900,1200);
    if (corner == 7) painter.drawArc(-5,-5,width()+10,height()+10,-1300,1200);
    if (corner == 8) painter.drawArc(-5,-5,width()+10,height()+10,1600,1000);
    if (corner == 9) painter.drawArc(-5,-5,width()+10,height()+10,0,1200);
    if (corner == 10) painter.drawArc(-5,-5,width()+10,height()+10,2900,1200);
    if (corner == 11) painter.drawArc(-5,-5,width()+10,height()+10,-1300,1200);
}

