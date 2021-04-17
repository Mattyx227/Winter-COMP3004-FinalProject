#ifndef RECORDING_H
#define RECORDING_H
#include <QString>
#include <iostream>
#include <QTime>
using namespace std;

class Recording{
public:
    Recording(QString s, QString t, QTime d, QDateTime da, int p);
    ~Recording();
    QString formatText();
    QString state;
    QString treatment;
    QTime duration;
    QDateTime date;
    int powerLevel;

};

#endif // RECORDING_H
