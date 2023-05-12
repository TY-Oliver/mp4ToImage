#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 主窗口信息设置
    this->setWindowTitle("FFMPEG图片视频处理");
    this->setWindowIcon(QIcon("./icon (1).png"));

    //状态栏显示永久信息
    permanent = new QLabel(this);
    permanent->setText("Welcome!");
    ui->statusBar->addPermanentWidget(permanent);

    // 初始化信息
    QSettings setting("./info.ini",QSettings::IniFormat);
    ui->ffmpegPath->setText(setting.value("ffmpegPath").toString());
    ui->OutPutPath->setText(setting.value("OutPutPath").toString());
    ui->VideoPath->setText(setting.value("VideoPath").toString());
    strffmpegPath = setting.value("ffmpegPath").toString();
    strOutputPath = setting.value("OutPutPath").toString();
    strVideoPath = setting.value("VideoPath").toString();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BrowseButton_1_clicked()
{
    strffmpegPath = QFileDialog::getOpenFileName(this,"open file","./","exe(*.exe);;All file(*.*)");
    ui->ffmpegPath ->setText(strffmpegPath.toUtf8());


    //Qt中使用QSettings类读写ini文件
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
    QSettings *configIniWrite = new QSettings("./info.ini", QSettings::IniFormat);
    //向ini文件写入内容
    configIniWrite->setValue("ffmpegPath", ui->ffmpegPath->text());//
    //写入完成后删除指针
    delete configIniWrite;

}

void MainWindow::on_BrowseButton_2_clicked()
{
    strVideoPath = QFileDialog::getOpenFileName(this,"open file","./","mp4(*.mp4);;All file(*.*)");
    ui->VideoPath ->setText(strVideoPath.toUtf8());

    //Qt中使用QSettings类读写ini文件
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
    QSettings *configIniWrite = new QSettings("./info.ini", QSettings::IniFormat);
    //向ini文件写入内容
    configIniWrite->setValue("VideoPath", ui->VideoPath->text());//
    //写入完成后删除指针
    delete configIniWrite;
}

void MainWindow::on_BrowseButton_3_clicked()
{
    strOutputPath = QFileDialog::getExistingDirectory(this,"Out Put Path","./");
    ui->OutPutPath ->setText(strOutputPath.toUtf8());

    //Qt中使用QSettings类读写ini文件
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
    QSettings *configIniWrite = new QSettings("./info.ini", QSettings::IniFormat);
    //向ini文件写入内容
    configIniWrite->setValue("OutPutPath", ui->OutPutPath->text());//
    //写入完成后删除指针
    delete configIniWrite;
}

void MainWindow::on_JPGButton_clicked()
{
    QProcess p(0);
    QString Command = QString("%1 -i %2 %3/%4").arg(strffmpegPath).arg(strVideoPath).arg(strOutputPath).arg("%d.jpg");
    qDebug() << Command;
    p.start(Command);
    this -> permanent ->setText("Processing...");
    p.waitForStarted(-1);
    p.waitForFinished(-1);
    this -> permanent ->setText("Finished!");
    qDebug()<<QString::fromLocal8Bit(p.readAll());

}

void MainWindow::on_PNGButton_clicked()
{
    QProcess p(0);
    QString Command = QString("%1 -i %2 %3/%4").arg(strffmpegPath).arg(strVideoPath).arg(strOutputPath).arg("%d.png");
    qDebug() << Command;
    p.start(Command);
    this -> permanent ->setText("Processing...");
    p.waitForStarted(-1);
    p.waitForFinished(-1);
    this -> permanent ->setText("Finished!");
    qDebug()<<QString::fromLocal8Bit(p.readAll());

}

void MainWindow::on_JPG2MP4_clicked()
{

    QProcess p(0);
    QString Command = QString("%1 -f image2 -i %2/%3 %4").arg(strffmpegPath).arg(strOutputPath).arg("%d.jpg").arg(ui->VideoPath->text());
    qDebug() << Command;
    p.start(Command);
    this -> permanent ->setText("Processing...");
    p.waitForStarted(-1);
    p.waitForFinished(-1);
    this -> permanent ->setText("Finished!");
    qDebug()<<QString::fromLocal8Bit(p.readAll());
}
