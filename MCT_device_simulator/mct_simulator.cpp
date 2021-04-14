#include "mct_simulator.h"
#include "ui_mct_simulator.h"

MCT_Simulator::MCT_Simulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCT_Simulator)
{
    ui->setupUi(this);
    initUI();

    connect(ui->downButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->upButton, SIGNAL(released()), this, SLOT(directionButtonPressed()));
    connect(ui->okButton, SIGNAL(released()), this, SLOT(okButtonPressed()));
    connect(ui->returnButton, SIGNAL(released()), this, SLOT(returnButtonPressed()));
    connect(ui->powerButton, SIGNAL(released()), this, SLOT(powerButtonPressed()));
}

MCT_Simulator::~MCT_Simulator()
{
    delete ui;
}

void MCT_Simulator::directionButtonPressed()
{
    QPushButton *button = (QPushButton*) sender();
    if(button->objectName() == "downButton" && ui->listWidget->currentRow() != 4 && ui->listWidget->currentRow() != -1)
    {
        int rowNum = ui->listWidget->currentRow();
        ui->listWidget->setCurrentRow(rowNum+1);
    }else if (button->objectName() == "upButton" && ui->listWidget->currentRow() != 1)
    {
        int rowNum = ui->listWidget->currentRow();
        ui->listWidget->setCurrentRow(rowNum-1);
    }

}

void MCT_Simulator::powerButtonPressed()
{
    QListWidget *menu = ui->listWidget;

    if (menu->item(2)->text() == "POWER OFF" && isOn == false) {
        isOn = true;
        changetoMainMenu();
    }else{
        isOn = false;
        changetoPowerOff();
    }
}

void MCT_Simulator::returnButtonPressed()
{
    QListWidget *menu = ui->listWidget;
    if (menu->item(0)->text() == "Frequency" || menu->item(0)->text() == "Programs"){
        changetoMainMenu();
    }
}

void MCT_Simulator::okButtonPressed()
{
    QListWidget *menu = ui->listWidget;

    if (menu->currentItem()->text() == "Frequency"){
        menu->item(0)->setText("Frequency");
        menu->item(1)->setText("10Hz");
        menu->item(2)->setText("20Hz");
        menu->item(3)->setText("125Hz");
        menu->item(4)->setText("7720");
        menu->setCurrentRow(1);
    }else if (menu->currentItem()->text() == "Programs"){
        menu->item(0)->setText("Programs");
        menu->item(1)->setText("Allergy");
        menu->item(2)->setText("Pain");
        menu->item(3)->setText("Bloating");
        menu->item(4)->setText("Dystonia");
        menu->setCurrentRow(1);
    }
}

//This function chagnes the list widget to main menu layout
void MCT_Simulator::changetoMainMenu()
{
    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("Main Menu");
    menu->item(1)->setText("Programs");
    menu->item(2)->setText("Frequency");
    menu->item(3)->setText("History");
    menu->item(4)->setText("Recording Setting");
    menu->setCurrentRow(1);
}

void MCT_Simulator::changetoPowerOff()
{
    QListWidget *menu = ui->listWidget;
    menu->item(0)->setText("");
    menu->item(1)->setText("");
    menu->item(2)->setText("POWER OFF");
    menu->item(3)->setText("");
    menu->item(4)->setText("");
    menu->setCurrentRow(-1);
    //menu->item(5)->setFlags(Qt::ItemIsSelectable);
}

//This function sets the icons for all the buttons and sets the display into default (Poweroff)
void MCT_Simulator::initUI()
{
    isOn = false;
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

