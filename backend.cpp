#include "backend.h"
#include"iostream"

BackEnd::BackEnd(int argc, char** argv, QQuickItem *item, QObject *parent):
    QObject(parent), qnode(argc, argv)
{
    std::cout << "Backend constructor..\n";

    //connect qnode var to backend
    QObject::connect(&qnode, SIGNAL(msgSubscribed()), this, SLOT(updateGUI()));

    //first module
    setBatteryVoltage1(int(qnode.battery_voltage1));
    setMotorSpeed_sx1(float(qnode.motor_speed_sx1));
    setMotorSpeed_dx1(float(qnode.motor_speed_dx1));
    //second module
    setBatteryVoltage2(int(qnode.battery_voltage2));
    setMotorSpeed_sx2(float(qnode.motor_speed_sx2));
    setMotorSpeed_dx2(float(qnode.motor_speed_dx2));
    //third module
    setBatteryVoltage3(int(qnode.battery_voltage3));
    setMotorSpeed_sx3(float(qnode.motor_speed_sx3));
    setMotorSpeed_dx3(float(qnode.motor_speed_dx3));
}

//update values in QML frontend
void BackEnd::updateGUI(){
    //first module
    setBatteryVoltage1(int(qnode.battery_voltage1));
    setMotorSpeed_sx1(float(qnode.motor_speed_sx1));
    setMotorSpeed_dx1(float(qnode.motor_speed_dx1));
    //second module
    setBatteryVoltage2(int(qnode.battery_voltage2));
    setMotorSpeed_sx2(float(qnode.motor_speed_sx2));
    setMotorSpeed_dx2(float(qnode.motor_speed_dx2));
    //third module
    setBatteryVoltage3(int(qnode.battery_voltage3));
    setMotorSpeed_sx3(float(qnode.motor_speed_sx3));
    setMotorSpeed_dx3(float(qnode.motor_speed_dx3));
}
