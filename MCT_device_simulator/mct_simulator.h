#ifndef MCT_SIMULATOR_H
#define MCT_SIMULATOR_H

#include <QMainWindow>
#include <QDebug>
#include "frequency.h"
#include <QTimer>
#include <QTime>

namespace Ui {
class MCT_Simulator;
}

class MCT_Simulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MCT_Simulator(QWidget *parent = nullptr);
    void initUI();
    void changetoMainMenu();
    void changetoFrequency();
    void changetoPrograms();
    void changetoPowerOff();
    void askForRecording();
    void setUnhidden();
    void changetoTreatment();
    void changetoSelectBattery();
    void updateBattery();

    ~MCT_Simulator();
    //Frequency f;
    QString state;
    int powerLevel = 0;
    QString currentTreatment;
    QTime time;
    QTimer timer;


private:
    Ui::MCT_Simulator *ui;
    bool isOn;
    bool recordingToggle;
    bool isTreatment = false;
    double batteryLevel;
    int downUpper;
    int downLower;
    int upUpper;
    int upLower;

private slots:
    void directionButtonPressed();  //Handles direction buttons
    void okButtonPressed();         //Handles the ok button
    void returnButtonPressed();
    void powerButtonPressed();
    void menuButtonPressed();
    void updateCountDown();
    void setBattery();

};



#endif // MCT_SIMULATOR_H
