#ifndef OPENJSON_H
#define OPENJSON_H

#include <include.h>
#include <other.h>

class OpenJson : public QObject, public Other
{
    Q_OBJECT
public:
    QJsonArray test;
    QString file(QString dateTuday, QString city);
    static QString openJson();
    QList <QJsonObject> readJson(QString dateTuday, QString city);
};

#endif // OPENJSON_H
