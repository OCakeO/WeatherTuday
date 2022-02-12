#ifndef DOWNLOADERMSK_H
#define DOWNLOADERMSK_H

#include "include.h"
#include <other.h>

class DownloaderMSK : public QObject, public Other
{
    Q_OBJECT
public:
    explicit DownloaderMSK(QObject *parent = 0);

signals:
    void onReadyMSK();

public slots:
    void getDataMSK();     // Метод инициализации запроса на получение данных
    void onResultMSK(QNetworkReply *reply);    // Слот обработки ответа о полученных данных
private:
    QNetworkAccessManager *manager;
};

#endif // DOWNLOADERMSK_H
