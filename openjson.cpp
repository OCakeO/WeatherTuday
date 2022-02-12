#include "openjson.h"

QString OpenJson::file(QString dateTuday, QString city){
    QFile file;
    QString val;
    QDir dir = path;

    dir.cd("../../Weather");
    QString pathDate = dir.path();
    if (city == "DME")
    pathDate.append("/WeatherTudayDME/"+ dateTuday +".xml");
    if (city == "MSK")
    pathDate.append("/WeatherTudayMSK/"+ dateTuday +".xml");

    file.setFileName(pathDate);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    return val;
}

QList <QJsonObject> OpenJson::readJson(QString dateTuday, QString city)
{
    QString val;
    val = file(dateTuday, city);
    qDebug() << val;
    QJsonDocument documentJson = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject setDocJsonToObj = documentJson.object();

    QList <QJsonValue> listDocJsonToVal;
    QList <QJsonObject> listValJsonToObj;
    QList <QJsonArray> listValJsonToArray;

    foreach(const QString& key, setDocJsonToObj.keys()) {
            QJsonValue value = setDocJsonToObj.value(key);
            listDocJsonToVal.append(value);
            qDebug() << listDocJsonToVal.last();

            if (listDocJsonToVal.last().isArray()){
                listValJsonToArray.append(listDocJsonToVal.last().toArray());
                listDocJsonToVal.append(listValJsonToArray.last().first());
            }
            if (listDocJsonToVal.last().isObject())
                listValJsonToObj.append(listDocJsonToVal.last().toObject());

    }
qDebug() << "//////////////////////////////////////////////////////////////////////";


        return listValJsonToObj;
}
