#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QLabel>
#include "QSettings"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QLabel *permanent;
    QString strffmpegPath;
    QString strVideoPath;
    QString strOutputPath;

    ~MainWindow();

private slots:
    void on_BrowseButton_1_clicked();

    void on_BrowseButton_2_clicked();

    void on_BrowseButton_3_clicked();

    void on_JPGButton_clicked();

    void on_PNGButton_clicked();

    void on_JPG2MP4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
