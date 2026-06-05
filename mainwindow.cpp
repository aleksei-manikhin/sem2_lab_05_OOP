#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "elevatorsystem.h"
#include "shaftview.h"

#include <QPushButton>
#include <QSignalBlocker>
#include <QTime>
#include <QVariant>

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
    cabinButtons[4] = ui->cabinFloorButton4;
    cabinButtons[5] = ui->cabinFloorButton5;

    callUpButtons[1] = ui->callUpButton1;
    callUpButtons[2] = ui->callUpButton2;
    callUpButtons[3] = ui->callUpButton3;
    callUpButtons[4] = ui->callUpButton4;

    callDownButtons[2] = ui->callDownButton2;
    callDownButtons[3] = ui->callDownButton3;
    callDownButtons[4] = ui->callDownButton4;
    callDownButtons[5] = ui->callDownButton5;
}

void MainWindow::connectCabinButtons()
{
    for (auto it = cabinButtons.begin(); it != cabinButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();

        button->setProperty("floor", floor);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::setClickedButtonChecked);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::requestCabinFloorFromButton);
    }
}

void MainWindow::connectCallButtons()
{
    for (auto it = callUpButtons.begin(); it != callUpButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();

        button->setProperty("floor", floor);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::setClickedButtonChecked);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::requestUpFloorCallFromButton);
    }

    for (auto it = callDownButtons.begin(); it != callDownButtons.end(); ++it) {
        QPushButton *button = it.value();
        const int floor = it.key();

        button->setProperty("floor", floor);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::setClickedButtonChecked);
        connect(button, &QPushButton::clicked,
                this, &MainWindow::requestDownFloorCallFromButton);
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
    connect(system, &ElevatorSystem::currentFloorChanged,
            this, &MainWindow::onCurrentFloorChanged);
    connect(system, &ElevatorSystem::targetFloorChanged,
            this, &MainWindow::onTargetFloorChanged);
    connect(system, &ElevatorSystem::directionChanged,
            this, &MainWindow::onDirectionChanged);
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

    connect(system, &ElevatorSystem::cabinStateChanged,
            this, &MainWindow::onCabinStateChanged);
    connect(system, &ElevatorSystem::doorStateChanged,
            this, &MainWindow::onDoorStateChanged);
}

void MainWindow::initializeFloorTexts()
{
    ui->floorNumberLabel4->setText("4");
    ui->floorCaptionLabel4->setText(floorCaption(4));
    ui->cabinFloorButton4->setText("4");
}

void MainWindow::setButtonChecked(QPushButton *button, bool checked)
{
    if (!button) {
        return;
    }

    const QSignalBlocker blocker(button);
    button->setChecked(checked);
}

void MainWindow::setClickedButtonChecked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    setButtonChecked(button, true);
}

void MainWindow::requestCabinFloorFromButton()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) {
        return;
    }

    system->requestCabinFloor(button->property("floor").toInt());
}

void MainWindow::requestUpFloorCallFromButton()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) {
        return;
    }

    system->requestFloorCall(button->property("floor").toInt(), Direction::Up);
}

void MainWindow::requestDownFloorCallFromButton()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) {
        return;
    }

    system->requestFloorCall(button->property("floor").toInt(), Direction::Down);
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

void MainWindow::appendLog(const QString &message)
{
    const QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->eventLogEdit->appendPlainText(QString("[%1] %2").arg(time, message));
}

void MainWindow::onCurrentFloorChanged(int floor)
{
    ui->currentFloorValueLabel->setText(QString::number(floor));
    shaftView->animateCabinToFloor(floor);
}

void MainWindow::onTargetFloorChanged(int floor)
{
    ui->targetFloorValueLabel->setText(QString::number(floor));
}

void MainWindow::onDirectionChanged(Direction direction)
{
    ui->directionValueLabel->setText(directionText(direction));
}

void MainWindow::onCabinStateChanged(CabinState state)
{
    ui->cabinStateValueLabel->setText(cabinStateText(state));
}

void MainWindow::onDoorStateChanged(DoorState state)
{
    ui->doorsStateValueLabel->setText(doorStateText(state));
    shaftView->animateDoors(state);
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

QString MainWindow::floorCaption(int floor) const
{
    return QString("Этаж %1").arg(floor);
}
