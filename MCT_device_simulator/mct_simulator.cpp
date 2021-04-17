#include "mct_simulator.h"
#include "ui_mct_simulator.h"


MCT_Simulator::MCT_Simulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCT_Simulator)
{
    ui->setupUi(this);
    initUI();
    time.setHMS(0, 4, 0);
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateCountDown()));
    connect(ui->downButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->upButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->okButton, SIGNAL(released()), this, SLOT(okButtonPressed()));
    connect(ui->returnButton, SIGNAL(released()), this, SLOT(returnButtonPressed()));
    connect(ui->powerButton, SIGNAL(released()), this, SLOT(powerButtonPressed()));
    connect(ui->menuButton, SIGNAL(released()), this, SLOT(menuButtonPressed()));
    connect(ui->rightButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->leftButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->batterySlider,SIGNAL(valueChanged(int)),this,SLOT(setBattery()));

}

MCT_Simulator::~MCT_Simulator()
{
    delete ui;
}
void MCT_Simulator::menuButtonPressed()
{
    if (isOn == true){
        changetoMainMenu();
        timer.stop();
    }
}

void MCT_Simulator::directionButtonPressed()
{
    if (isOn){
        QPushButton *button = (QPushButton*) sender();
        QListWidget *menu = ui->listWidget;
        if(button->objectName() == "downButton" && ui->listWidget->currentRow() != downUpper && ui->listWidget->currentRow() != -1)
        {
            int rowNum = ui->listWidget->currentRow();
            ui->listWidget->setCurrentRow(rowNum+1);
        }

        else if (button->objectName() == "upButton" && ui->listWidget->currentRow() != upUpper && ui->listWidget->currentRow() != 1)
        {
            int rowNum = ui->listWidget->currentRow();
            ui->listWidget->setCurrentRow(rowNum-1);
        }
        else if (button->objectName() == "leftButton" && powerLevel != 0 && (state == "Frequency Treatment" || state == "Programs Treatment"))
        {
            powerLevel--;
            menu->item(5)->setText("Power : " + QString::number(powerLevel));
        }
        else if (button->objectName() == "rightButton" && powerLevel != 100 && (state == "Frequency Treatment" || state == "Programs Treatment"))
        {
            powerLevel++;
            menu->item(5)->setText("Power : " + QString::number(powerLevel));
        }
    }

}

void MCT_Simulator::powerButtonPressed()
{
    QListWidget *menu = ui->listWidget;

    if (menu->item(2)->text() == "POWER OFF" && isOn == false && batteryLevel > 0) {
        isOn = true;
        changetoMainMenu();
    }else{
        timer.stop();
        isOn = false;
        changetoPowerOff();
    }
}

void MCT_Simulator::returnButtonPressed()
{
    if (isOn){
        QListWidget *menu = ui->listWidget;
        if (menu->item(0)->text() == "Frequency" || menu->item(0)->text() == "Programs"){
            changetoMainMenu();
        }else if (menu->item(0)->text() == "Rcord this treatment?")
        {
             if (state == "Frequency"){changetoFrequency();}
            else if (state == "Programs") {changetoPrograms();}
        }else if (state == "Frequency Treatment")  {changetoFrequency();

        }else if (state == "Programs Treatment")  {changetoFrequency();
        }
        timer.stop();
    }

}

void MCT_Simulator::okButtonPressed()
{
    QListWidget *menu = ui->listWidget;
    QString temp = menu->currentItem()->text();
    if (isOn == true){
        if (temp == "Frequency"){
            changetoFrequency();
        }else if (temp == "Programs"){
            changetoPrograms();
        }else if ((state == "Frequency" || state =="Programs") && menu->item(0)->text() != "Rcord this treatment?"){
            currentTreatment = menu->currentItem()->text();
            askForRecording();
        }else if (temp == "Yes"){
            recordingToggle = true;
            changetoSelectBattery();
        }else if (temp == "No"){
            recordingToggle = false;
            changetoSelectBattery();
        }
        else if (state == "Frequency Treatment" || state == "Programs Treatment"){
            isTreatment = true;
            changetoTreatment();
        }
    }
}

void MCT_Simulator::updateCountDown()
{
    QListWidget *menu = ui->listWidget;
    if(ui->contactBox->isChecked() == true){
        if (state == "Frequency Treatment"){
            time = time.addSecs(+1);
        }else {
            time = time.addSecs(-1);
        }

        menu->item(2)->setText(time.toString("m:ss"));
        updateBattery();
    }



}
//state: Main / Frequency / Programs

//recording(state, currentTreatment);

//This function chagnes the list widget to main menu layout


void MCT_Simulator::updateBattery(){
        batteryLevel -= powerLevel * 1;
        QLabel *batteryText = ui->batteryText;

        if (batteryLevel  <= 0){
            batteryLevel = 0;
            timer.stop();
            changetoPowerOff();
        }
        batteryText->setText(QString::number(batteryLevel) + "%");
        ui->batterySlider->setValue(batteryLevel);

}

void MCT_Simulator::setBattery(){
    batteryLevel = ui->batterySlider->value();
    QLabel *batteryText = ui->batteryText;
    batteryText->setText(QString::number(batteryLevel) + "%");
    if(batteryLevel == 0){
        changetoPowerOff();
    }
}

void MCT_Simulator::changetoMainMenu()
{
    state = "Main";
    setUnhidden();
    downUpper = 4;
    upUpper = 1;
    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("Main Menu");
    menu->item(1)->setText("Programs");
    menu->item(2)->setText("Frequency");
    menu->item(3)->setText("History");
    menu->item(4)->setText("Recording Setting");
    menu->item(5)->setText("");
    menu->setCurrentRow(1);
}

void MCT_Simulator::changetoFrequency()
{
    state = "Frequency";
    setUnhidden();
    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("Frequency");
    menu->item(1)->setText("10Hz");
    menu->item(2)->setText("20Hz");
    menu->item(3)->setText("125Hz");
    menu->item(4)->setText("7720");
    menu->item(5)->setText("");
    menu->setCurrentRow(1);

    menu->item(3)->setHidden(false);
    menu->item(4)->setHidden(false);
}

void MCT_Simulator::changetoPrograms()
{
    state = "Programs";
    setUnhidden();

    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("Programs");
    menu->item(1)->setText("Allergy");
    menu->item(2)->setText("Pain");
    menu->item(3)->setText("Bloating");
    menu->item(4)->setText("Dystonia");
    menu->setCurrentRow(1);


}

void MCT_Simulator::changetoSelectBattery()
{
     powerLevel = 0;
     upUpper = 5;
     downUpper = 5;
     QListWidget *menu = ui->listWidget;
     state = state + " Treatment";
     qInfo() << "Current State " + state;
     menu->item(0)->setText(currentTreatment);
     menu->item(1)->setText("");

     if (state == "Frequency Treatment"){
         time.setHMS(0, 0 ,0);
     }else if (state == "Programs Treatment"){
         time.setHMS(0, 5, 0);
     }
     menu->setCurrentRow(5);
     menu->item(2)->setText(time.toString("m:ss"));
     menu->item(3)->setHidden(false);
     menu->item(3)->setText("");
     menu->item(4)->setHidden(false);
     menu->item(4)->setText("");
     menu->item(5)->setText("Power : " + QString::number(powerLevel));
}

void MCT_Simulator::changetoTreatment()
{

    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText(currentTreatment);
    menu->item(1)->setText("");


    timer.start(1000);
}
void MCT_Simulator::changetoPowerOff()
{
    isOn = false;
    upUpper = 2;
    downUpper = 2;
    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("");
    menu->item(1)->setText("");
    menu->item(2)->setText("POWER OFF");
    menu->item(3)->setText("");
    menu->item(4)->setText("");
    menu->item(5)->setText("");
    menu->setCurrentRow(2);

}

void  MCT_Simulator::askForRecording()
{

    QListWidget *menu = ui->listWidget;
    menu->setCurrentRow(1);
    qInfo() << "Current Treatment" + currentTreatment;
    downUpper = 2;
    menu->item(0)->setText("Rcord this treatment?");
    menu->item(1)->setText("Yes");
    menu->item(2)->setText("No");
    menu->item(3)->setHidden(true);
    menu->item(4)->setHidden(true);
}

void MCT_Simulator::setUnhidden()
{
    QListWidget *menu = ui->listWidget;
    menu->item(1)->setHidden(false);
    menu->item(2)->setHidden(false);
    menu->item(3)->setHidden(false);
    menu->item(4)->setHidden(false);
    downUpper = 4;
}


//This function sets the icons for all the buttons and sets the display into default (Poweroff)
void MCT_Simulator::initUI()
{
    isOn = false;
    batteryLevel = 100;
    changetoPowerOff();
    QPixmap pixmap("/home/student/Desktop/GroupProject/MCT_device_simulator/left_icon.png");
    ui->leftButton->setIcon(QIcon(pixmap));
    ui->leftButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/right_icon.png");
    ui->rightButton->setIcon(QIcon(pixmap));
    ui->rightButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/down_icon.png");
    ui->downButton->setIcon(QIcon(pixmap));
    ui->downButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/up_icon.png");
    ui->upButton->setIcon(QIcon(pixmap));
    ui->upButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/ok_icon.png");
    ui->okButton->setIcon(QIcon(pixmap));
    ui->okButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/return_icon.png");
    ui->returnButton->setIcon(QIcon(pixmap));
    ui->returnButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/menu_icon.png");
    ui->menuButton->setIcon(QIcon(pixmap));
    ui->menuButton->setIconSize(QSize(30, 30));

    pixmap.load("/home/student/Desktop/GroupProject/MCT_device_simulator/power_icon.png");
    ui->powerButton->setIcon(QIcon(pixmap));
    ui->powerButton->setIconSize(QSize(30, 30));

}

