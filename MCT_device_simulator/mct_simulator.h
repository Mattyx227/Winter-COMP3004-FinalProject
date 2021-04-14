#ifndef MCT_SIMULATOR_H
#define MCT_SIMULATOR_H

#include <QMainWindow>
#include <QDebug>

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
    void changetoPowerOff();
    ~MCT_Simulator();

private:
    Ui::MCT_Simulator *ui;
    bool isOn;

private slots:
    void directionButtonPressed();  //Handles direction buttons
    void okButtonPressed();         //Handles the ok button
    void returnButtonPressed();
    void powerButtonPressed();
};



#endif // MCT_SIMULATOR_H
