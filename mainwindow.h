#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <downloader.h>
#include <downloadermsk.h>
#include <openjson.h>
#include <include.h>
#include <other.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, Other
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
// добавить массив на DME and MSK
// добавить массив на DME[30] and MSK[30]
// добавить button DME/MSK
// добавить button [30]

private slots:
    void on_pushButton_3_clicked();

private:
    QString degToText(QString deg);
    QString setCity = "DME";
    bool clickBut = 0;
    void setValuesTuday();
    void readJson();
    QString tempKToC(QString);
    Ui::MainWindow *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
    DownloaderMSK *downloaderMSK; // Объявляем объект класса для скачивания данных по http
    OpenJson *openJson;
};
#endif // MAINWINDOW_H
