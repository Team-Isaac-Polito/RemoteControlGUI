#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include <QQuickItem>
#include <qnode.h>

class BackEnd : public QObject
{
    Q_OBJECT

    Q_PROPERTY (int dynamicRange READ dynamicRange WRITE setDynamicRange NOTIFY dynamicRangeChanged)
    //first module
    Q_PROPERTY (float motorSpeed_sx1 READ motorSpeed_sx1 WRITE setMotorSpeed_sx1 NOTIFY motorSpeed_sx1Changed)
    Q_PROPERTY (float motorSpeed_dx1 READ motorSpeed_dx1 WRITE setMotorSpeed_dx1 NOTIFY motorSpeed_dx1Changed)
    Q_PROPERTY (int batteryVoltage1 READ batteryVoltage1 WRITE setBatteryVoltage1 NOTIFY batteryVoltage1Changed)
    //second module
    Q_PROPERTY (float motorSpeed_sx2 READ motorSpeed_sx2 WRITE setMotorSpeed_sx2 NOTIFY motorSpeed_sx2Changed)
    Q_PROPERTY (float motorSpeed_dx2 READ motorSpeed_dx2 WRITE setMotorSpeed_dx2 NOTIFY motorSpeed_dx2Changed)
    Q_PROPERTY (int batteryVoltage2 READ batteryVoltage2 WRITE setBatteryVoltage2 NOTIFY batteryVoltage2Changed)
    //third module
    Q_PROPERTY (float motorSpeed_sx3 READ motorSpeed_sx3 WRITE setMotorSpeed_sx3 NOTIFY motorSpeed_sx3Changed)
    Q_PROPERTY (float motorSpeed_dx3 READ motorSpeed_dx3 WRITE setMotorSpeed_dx3 NOTIFY motorSpeed_dx3Changed)
    Q_PROPERTY (int batteryVoltage3 READ batteryVoltage3 WRITE setBatteryVoltage3 NOTIFY batteryVoltage3Changed)


    QML_ELEMENT
public:
    explicit BackEnd(int argc, char** argv, QQuickItem *item = nullptr, QObject *parent = nullptr);
    QNode qnode;

    //QML connection functions
    int dynamicRange() const { return m_dynamicRange; }
    void setDynamicRange(int dynamicRange){
        if(m_dynamicRange == dynamicRange)
            return;

        m_dynamicRange = dynamicRange;
        emit dynamicRangeChanged();
    }

    //first mdoule
    int batteryVoltage1() const {return m_BatteryVoltage1; }
    float motorSpeed_sx1() const {return m_MotorSpeed_sx1; }
    float motorSpeed_dx1() const {return m_MotorSpeed_dx1; }

    void setBatteryVoltage1(int bat){
        if(m_BatteryVoltage1 == bat)
            return;
        m_BatteryVoltage1 = bat;
        emit batteryVoltage1Changed();
    }
    void setMotorSpeed_sx1(float speed){
        if(m_MotorSpeed_sx1 == speed)
            return;
        m_MotorSpeed_sx1 = speed;
        emit motorSpeed_sx1Changed();
    }
    void setMotorSpeed_dx1(float speed){
        if(m_MotorSpeed_dx1 == speed)
            return;
        m_MotorSpeed_dx1 = speed;
        emit motorSpeed_dx1Changed();
    }

    //second mdoule
    int batteryVoltage2() const {return m_BatteryVoltage2; }
    float motorSpeed_sx2() const {return m_MotorSpeed_sx2; }
    float motorSpeed_dx2() const {return m_MotorSpeed_dx2; }

    void setBatteryVoltage2(int bat){
        if(m_BatteryVoltage2 == bat)
            return;
        m_BatteryVoltage2 = bat;
        emit batteryVoltage2Changed();
    }
    void setMotorSpeed_sx2(float speed){
        if(m_MotorSpeed_sx2 == speed)
            return;
        m_MotorSpeed_sx2 = speed;
        emit motorSpeed_sx2Changed();
    }
    void setMotorSpeed_dx2(float speed){
        if(m_MotorSpeed_dx2 == speed)
            return;
        m_MotorSpeed_dx2 = speed;
        emit motorSpeed_dx2Changed();
    }

    //third mdoule
    int batteryVoltage3() const {return m_BatteryVoltage3; }
    float motorSpeed_sx3() const {return m_MotorSpeed_sx3; }
    float motorSpeed_dx3() const {return m_MotorSpeed_dx3; }

    void setBatteryVoltage3(int bat){
        if(m_BatteryVoltage3 == bat)
            return;
        m_BatteryVoltage3 = bat;
        emit batteryVoltage3Changed();
    }
    void setMotorSpeed_sx3(float speed){
        if(m_MotorSpeed_sx3 == speed)
            return;
        m_MotorSpeed_sx3 = speed;
        emit motorSpeed_sx3Changed();
    }
    void setMotorSpeed_dx3(float speed){
        if(m_MotorSpeed_dx3 == speed)
            return;
        m_MotorSpeed_dx3 = speed;
        emit motorSpeed_dx3Changed();
    }

public slots:
    void updateGUI();

signals:
    //QML connection signals
    void dynamicRangeChanged();
    //first module
    void batteryVoltage1Changed();
    void motorSpeed_sx1Changed();
    void motorSpeed_dx1Changed();
    //second module
    void batteryVoltage2Changed();
    void motorSpeed_sx2Changed();
    void motorSpeed_dx2Changed();
    //third module
    void batteryVoltage3Changed();
    void motorSpeed_sx3Changed();
    void motorSpeed_dx3Changed();


private:
    int m_dynamicRange = 0;
    //first module
    int m_BatteryVoltage1 = 0;
    float m_MotorSpeed_sx1 = 0;
    float m_MotorSpeed_dx1 = 0;
    //second module
    int m_BatteryVoltage2 = 0;
    float m_MotorSpeed_sx2 = 0;
    float m_MotorSpeed_dx2 = 0;
    //third module
    int m_BatteryVoltage3 = 0;
    float m_MotorSpeed_sx3 = 0;
    float m_MotorSpeed_dx3 = 0;
};

#endif // BACKEND_H
