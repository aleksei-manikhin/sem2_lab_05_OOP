#ifndef ELEVATORDOORS_H
#define ELEVATORDOORS_H

#include "elevatorenums.h"

#include <QObject>
#include <QTimer>

class ElevatorDoors : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorDoors(QObject *parent = nullptr);

    DoorState state() const;
    bool isClosed() const;
    bool isOpen() const;

    static constexpr int OpeningTimeMs = 900;
    static constexpr int OpenedTimeMs = 1200;
    static constexpr int ClosingTimeMs = 900;

public slots:
    void open();
    void close();
    void extendOpenTime();

signals:
    void stateChanged(DoorState state);
    void opened();
    void closed();
    void logMessage(const QString &message);

private slots:
    void finishOpening();
    void finishWaiting();
    void finishClosing();

private:
    void setState(DoorState state);
    void startOpening();
    void startClosing();
    void stopDoorTimers();

    DoorState doorState = DoorState::Closed;
    QTimer openingTimer;
    QTimer openedTimer;
    QTimer closingTimer;

};

#endif // ELEVATORDOORS_H
