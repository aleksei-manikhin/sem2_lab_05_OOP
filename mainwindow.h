#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "elevatorenums.h"

#include <QMainWindow>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ElevatorSystem;
class QPushButton;
class ShaftView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setClickedButtonChecked();
    void requestCabinFloorFromButton();
    void requestUpFloorCallFromButton();
    void requestDownFloorCallFromButton();
    void onCurrentFloorChanged(int floor);
    void onTargetFloorChanged(int floor);
    void onDirectionChanged(Direction direction);
    void onCabinStateChanged(CabinState state);
    void onDoorStateChanged(DoorState state);

private:
    void setupModel();
    void setupButtonMaps();
    void connectCabinButtons();
    void connectCallButtons();
    void connectDoorButtons();
    void connectSystemSignals();
    void initializeView();
    void initializeFloorTexts();

    void setButtonChecked(QPushButton *button, bool checked);
    void setCabinButtonLight(int floor, bool enabled);
    void setFloorCallLight(int floor, Direction direction, bool enabled);
    void appendLog(const QString &message);

    QString directionText(Direction direction) const;
    QString cabinStateText(CabinState state) const;
    QString doorStateText(DoorState state) const;
    QString floorCaption(int floor) const;

    Ui::MainWindow *ui;
    ElevatorSystem *system = nullptr;
    ShaftView *shaftView = nullptr;
    QMap<int, QPushButton *> cabinButtons;
    QMap<int, QPushButton *> callUpButtons;
    QMap<int, QPushButton *> callDownButtons;
};
#endif // MAINWINDOW_H
