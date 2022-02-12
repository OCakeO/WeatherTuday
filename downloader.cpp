#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    // Инициализируем менеджер ...
    manager = new QNetworkAccessManager();
    // ... и подключаем сигнал о завершении получения данных к обработчику полученного ответа
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResultDME);
}

void Downloader::getDataDME()
{//,
    QUrl url("API"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    manager->get(request);      // Выполняем запрос
}

void Downloader::onResultDME(QNetworkReply *reply)
{
    if(!reply->error()){
        QDir dir = path;
        dir.cd("../../Weather");
        QString pathDate = dir.path();
        QFile *file = new QFile(pathDate + "/WeatherTudayDME/"+ date +".xml");
        // Создаём файл или открываем его на перезапись ...
        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
            file->close();                  // закрываем файл
        emit onReadyDME(); // Посылаем сигнал о завершении получения файла
    }
  }
}

