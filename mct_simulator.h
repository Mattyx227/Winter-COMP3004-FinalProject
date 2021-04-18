#ifndef MCT_SIMULATOR_H
#define MCT_SIMULATOR_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QCoreApplication>
#include "recording.h"
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
    void changetoHistory();
    void changetoView();
    void askForRecording();
    void setUnhidden();
    void changetoTreatment();
    void changetoSelectBattery();
    void updateBattery();

    ~MCT_Simulator();
    QString state;
    QString currentTreatment;
    QString path = "/home/student/Desktop/GroupProject/MCT_device_simulator/";
    int powerLevel = 0;
    int highestLevel;
    QDateTime date;
    QTime time;
    QTimer timer;


private:
    Ui::MCT_Simulator *ui;
    bool isOn;
    bool recordingToggle;
    bool isTreatment = false;
    double batteryLevel;
    int downUpper;
    int upUpper;
    std::vector<Recording*> history;

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
