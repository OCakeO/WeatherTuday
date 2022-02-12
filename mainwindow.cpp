#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    downloader = new Downloader();
    downloaderMSK = new DownloaderMSK();
    openJson = new OpenJson();

    downloader->getDataDME();
    downloaderMSK->getDataMSK();
    connect(downloader, &Downloader::onReadyDME, this, &MainWindow::setValuesTuday);

    QDateTime tuday = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(tuday);
}

void MainWindow::setValuesTuday(){
    QList <QJsonObject> listAllVal = openJson->readJson(Other::date, setCity);
    QList <QString> listAllValToStrMain;
    int countAll = 0;
    for(int i =0;i<listAllVal.length(); i++)
        foreach(const QString& key, listAllVal.at(i).keys()) {  //MUST HAVE!!!!!!!!!!!!!!!!!
             QJsonValue value = listAllVal.at(i).value(key);
             if(i == 0|| i == 1 || i == 3 ){
                 countAll++;
                 if(value.isDouble()){
                     double val = value.toDouble();
                     listAllValToStrMain.append(QString::number(val));
                     qDebug() << "Key" << i << countAll << " = "<< key << ", Value = " << val;
                 }
                 if(value.isString()){
                     QString val = value.toString();
                     qDebug() << "Key" << i << " = "<< key << ", Value = " << val;
                 }
             }
        }
    if(clickBut == 1){
        ui->all->setText(listAllValToStrMain.at(0));

        ui->feels_like->setText(tempKToC(listAllValToStrMain.at(1)));

        ui->humidity->setText(listAllValToStrMain.at(3));
        ui->pressure->setText(listAllValToStrMain.at(4));

        ui->temp->setText(tempKToC(listAllValToStrMain.at(6)));
        ui->temp_max->setText(tempKToC(listAllValToStrMain.at(7)));
        ui->temp_min->setText(tempKToC(listAllValToStrMain.at(8)));

        ui->deg->setText(degToText(listAllValToStrMain.at(9)));
        ui->gust->setText(listAllValToStrMain.at(10));
        ui->speed->setText(listAllValToStrMain.at(11));
}
    else{
        ui->all->setText(listAllValToStrMain.at(0));

        ui->feels_like->setText(tempKToC(listAllValToStrMain.at(1)));

        ui->humidity->setText(listAllValToStrMain.at(2));
        ui->pressure->setText(listAllValToStrMain.at(3));

        ui->temp->setText(tempKToC(listAllValToStrMain.at(4)));
        ui->temp_max->setText(tempKToC(listAllValToStrMain.at(5)));
        ui->temp_min->setText(tempKToC(listAllValToStrMain.at(6)));

        ui->deg->setText(degToText(listAllValToStrMain.at(7)));
        //ui->gust->setText(listAllValToStrMain.at(10));
        ui->speed->setText(listAllValToStrMain.at(8));
    }


}
QString MainWindow::tempKToC(QString temps) {

    double oldValue = temps.toDouble();
    oldValue = oldValue - 273;
    return QString::number(oldValue);
}
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::degToText(QString deg){
    QString degText;
    double degToint = 0;
    degToint = deg.toDouble();
    qDebug() << degToint;
    if(degToint >= 340 || degToint <= 25)
        degText = "Северный";
    if(degToint >=26 || degToint <= 68)
        degText = "Северо-восточный";
    if(degToint >=69 || degToint <= 114)
        degText = "Восточный";
    if(degToint >=115 || degToint <= 160)
        degText = "Юго-вотсточный";
    if(degToint >=161 || degToint <= 206)
        degText = "Южный";
    if(degToint >=207 || degToint <= 252)
        degText = "Юго-западный";
    if(degToint >=253 || degToint <= 298)
        degText = "Западный";
    if(degToint >=299 || degToint <= 339)
        degText = "Северо-западный";
    else
       degText ="";

    return degText;
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->all->clear();
    ui->feels_like->clear();
    ui->humidity->clear();
    ui->pressure->clear();
    ui->temp->clear();
    ui->temp_max->clear();
    ui->temp_min->clear();
    ui->deg->clear();
    ui->gust->clear();
    ui->speed->clear();

    if (clickBut == 0){
        ui->pushButton_3->setText("Погода в Домодедово");
        setCity = "MSK";
        ui->label_7->setText("Погода в Москве");
        clickBut = 1;
        setValuesTuday();
    }
    else{
        ui->pushButton_3->setText("Погода в Москве");
        setCity = "DME";
        ui->label_7->setText("Погода в Домодедово");
        clickBut = 0;
        setValuesTuday();
    }

}

