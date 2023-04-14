#ifndef QNODE_H
#define QNODE_H

#include <QObject>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int32.hpp"
#include <thread>

class QNode : public QObject {
    Q_OBJECT
public:
    QNode(int argc=0, char** argv=nullptr, QObject *parent = nullptr);

    //Subscribers variables
    //first module
    float motor_speed_sx1 = 0.0;
    float motor_speed_dx1 = 0.0;
    int battery_voltage1 = 0;
    //second module
    float motor_speed_sx2 = 0.0;
    float motor_speed_dx2 = 0.0;
    int battery_voltage2 = 0;
    //third module
    float motor_speed_sx3 = 0.0;
    float motor_speed_dx3 = 0.0;
    int battery_voltage3 = 0;

Q_SIGNALS:
    //announce new data from ROS
    void msgSubscribed();

private:
    rclcpp::Node::SharedPtr m_RosNode;
    //first module
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr m_BatteryVoltage1_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_sx1_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_dx1_Sub;

    void m_BatteryVoltage1_Callback(const std_msgs::msg::Int32::SharedPtr msg);
    void m_MotorSpeed_sx1_Callback(const std_msgs::msg::Float32::SharedPtr msg);
    void m_MotorSpeed_dx1_Callback(const std_msgs::msg::Float32::SharedPtr msg);

    //second module
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr m_BatteryVoltage2_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_sx2_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_dx2_Sub;

    void m_BatteryVoltage2_Callback(const std_msgs::msg::Int32::SharedPtr msg);
    void m_MotorSpeed_sx2_Callback(const std_msgs::msg::Float32::SharedPtr msg);
    void m_MotorSpeed_dx2_Callback(const std_msgs::msg::Float32::SharedPtr msg);

    //third module
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr m_BatteryVoltage3_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_sx3_Sub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr m_MotorSpeed_dx3_Sub;

    void m_BatteryVoltage3_Callback(const std_msgs::msg::Int32::SharedPtr msg);
    void m_MotorSpeed_sx3_Callback(const std_msgs::msg::Float32::SharedPtr msg);
    void m_MotorSpeed_dx3_Callback(const std_msgs::msg::Float32::SharedPtr msg);
};

#endif // QNODE_H
