#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(445,140);
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}
DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent)
{

    setSegmentStyle(Filled);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);
    showTime();
    setWindowTitle(tr("Годинник"));
    resize(151, 61);
}

void DigitalClock::showTime()
{
    QTime   time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 5) == 0)
    {text[2] = ' ';}
    display(text);
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if ((time.second()%2)==0)
    {
        text[2] = ' ';
        text[5] = ' ';
    }
    ui->label->setText(text);
}

DigitalClock::~DigitalClock()
{
    delete ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}
