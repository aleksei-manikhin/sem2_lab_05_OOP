#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "elevatorsystem.h"
#include "shaftview.h"

#include <QPushButton>
#include <QSignalBlocker>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupModel();
    setupButtonMaps();
    connectCabinButtons();
    connectCallButtons();
    connectDoorButtons();
    connectSystemSignals();
    initializeView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel()
{
    system = new ElevatorSystem(this);
    shaftView = new ShaftView(ui->shaftFrame,
                              ui->elevatorCabinFrame,
                              ui->leftDoorFrame,
                              ui->rightDoorFrame,
                              this);
}

void MainWindow::setupButtonMaps()
{
    cabinButtons[1] = ui->cabinFloorButton1;
    cabinButtons[2] = ui->cabinFloorButton2;
    cabinButtons[3] = ui->cabinFloorButton3;
    cabinButtons[67] = ui->cabinFloorButton4;
    cabinButtons[5] = ui->cabinFloorButton5;

    callUpButtons[1] = ui->callUpButton1;
    callUpButtons[2] = ui->callUpButton2;
    callUpButtons[3] = ui->callUpButton3;
    callUpButtons[67] = ui->callUpButton4;

    callDownButtons[2] = ui->callDownButton2;
    callDownButtons[3] = ui->callDownButton3;
    callDownButtons[67] = ui->callDownButton4;
    callDownButtons[5] = ui->callDownButton5;
}

void MainWindow::connectCabinButtons()
{
    for (auto it = cabinButtons.begin(); it != cabinButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();

        connect(button, &QPushButton::clicked, this, [this, button, floor]() {
            setButtonChecked(button, true);
            system->requestCabinFloor(floor);
        });
    }
}

void MainWindow::connectCallButtons()
{
    for (auto it = callUpButtons.begin(); it != callUpButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();
        connect(button, &QPushButton::clicked, this, [this, button, floor]() {
            setButtonChecked(button, true);
            system->requestFloorCall(floor, Direction::Up);
        });
    }

    for (auto it = callDownButtons.begin(); it != callDownButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();
        connect(button, &QPushButton::clicked, this, [this, button, floor]() {
            setButtonChecked(button, true);
            system->requestFloorCall(floor, Direction::Down);
        });
    }
}

void MainWindow::connectDoorButtons()
{
    connect(ui->openDoorsButton, &QPushButton::clicked,
            system, &ElevatorSystem::requestDoorsOpen);
    connect(ui->closeDoorsButton, &QPushButton::clicked,
            system, &ElevatorSystem::requestDoorsClose);
    connect(ui->clearLogButton, &QPushButton::clicked,
            ui->eventLogEdit, &QPlainTextEdit::clear);
}

void MainWindow::connectSystemSignals()
{
    connect(system, &ElevatorSystem::cabinButtonLightChanged,
            this, &MainWindow::setCabinButtonLight);
    connect(system, &ElevatorSystem::floorCallLightChanged,
            this, &MainWindow::setFloorCallLight);
    connect(system, &ElevatorSystem::currentFloorChanged, this, [this](int floor) {
        ui->currentFloorValueLabel->setText(QString::number(floor));
        shaftView->animateCabinToFloor(floor);
    });
    connect(system, &ElevatorSystem::targetFloorChanged, this, [this](int floor) {
        ui->targetFloorValueLabel->setText(QString::number(floor));
    });
    connect(system, &ElevatorSystem::directionChanged, this, [this](Direction direction) {
        ui->directionValueLabel->setText(directionText(direction));
    });
    connect(system, &ElevatorSystem::logMessage, this, &MainWindow::appendLog);
}

void MainWindow::initializeView()
{
    initializeFloorTexts();
    ui->currentFloorValueLabel->setText("1");
    ui->targetFloorValueLabel->setText("-");
    ui->directionValueLabel->setText(directionText(Direction::Idle));
    ui->cabinStateValueLabel->setText(cabinStateText(CabinState::Stopped));
    ui->doorsStateValueLabel->setText(doorStateText(DoorState::Closed));

    connect(system, &ElevatorSystem::cabinStateChanged, this, [this](CabinState state) {
        ui->cabinStateValueLabel->setText(cabinStateText(state));
        setDoorControlsEnabled(state);
    });
    connect(system, &ElevatorSystem::doorStateChanged, this, [this](DoorState state) {
        ui->doorsStateValueLabel->setText(doorStateText(state));
        shaftView->animateDoors(state);
    });
    connect(system, &ElevatorSystem::controllerStateChanged, this, [this](ControllerState state) {
        statusBar()->showMessage(controllerStateText(state));
    });
}

void MainWindow::initializeFloorTexts()
{
    ui->floorNumberLabel4->setText("67");
    ui->floorCaptionLabel4->setText(floorCaption(67));
    ui->cabinFloorButton4->setText("67");
}

void MainWindow::setButtonChecked(QPushButton *button, bool checked)
{
    if (!button) {
        return;
    }

    const QSignalBlocker blocker(button);
    button->setChecked(checked);
}

void MainWindow::setCabinButtonLight(int floor, bool enabled)
{
    setButtonChecked(cabinButtons.value(floor, nullptr), enabled);
}

void MainWindow::setFloorCallLight(int floor, Direction direction, bool enabled)
{
    if (direction == Direction::Up) {
        setButtonChecked(callUpButtons.value(floor, nullptr), enabled);
        return;
    }

    setButtonChecked(callDownButtons.value(floor, nullptr), enabled);
}

void MainWindow::setDoorControlsEnabled(CabinState state)
{
    const bool enabled = state != CabinState::Moving
            && state != CabinState::PreparingToMove;

    ui->openDoorsButton->setEnabled(enabled);
    ui->closeDoorsButton->setEnabled(enabled);
}

void MainWindow::appendLog(const QString &message)
{
    const QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->eventLogEdit->appendPlainText(QString("[%1] %2").arg(time, message));
}

QString MainWindow::directionText(Direction direction) const
{
    if (direction == Direction::Up) {
        return "Up";
    }

    if (direction == Direction::Down) {
        return "Down";
    }

    return "Idle";
}

QString MainWindow::cabinStateText(CabinState state) const
{
    if (state == CabinState::PreparingToMove) {
        return "Preparing";
    }

    if (state == CabinState::Moving) {
        return "Moving";
    }

    return "Stopped";
}

QString MainWindow::doorStateText(DoorState state) const
{
    if (state == DoorState::Opening) {
        return "Opening";
    }

    if (state == DoorState::Open) {
        return "Open";
    }

    if (state == DoorState::Closing) {
        return "Closing";
    }

    return "Closed";
}

QString MainWindow::controllerStateText(ControllerState state) const
{
    if (state == ControllerState::Moving) {
        return "Elevator is moving";
    }

    if (state == ControllerState::UpdatingTarget) {
        return "Choosing next target";
    }

    if (state == ControllerState::TargetReached) {
        return "Target reached";
    }

    return "Elevator is idle";
}

QString MainWindow::floorCaption(int floor) const
{
    return QString("Этаж %1").arg(floor);
}
