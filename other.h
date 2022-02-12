#ifndef OTHER_H
#define OTHER_H

#include <include.h>

class Other{
    public:
    QString date = QDate::currentDate().toString("yyyy.MM.dd");
    QString path = QCoreApplication::applicationDirPath();
};



#endif // OTHER_H
