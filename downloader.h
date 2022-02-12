#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include "include.h"
#include <other.h>

class Downloader: public QObject, public Other
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);
signals:
    void onReadyDME();

public slots:
    void getDataDME();     // Метод инициализации запроса на получение данных
    void onResultDME(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

private:
    QNetworkAccessManager *manager;
};

#endif // DOWNLOADER_H
