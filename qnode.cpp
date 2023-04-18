#include "qnode.h"
#include <iostream>

QNode::QNode(int argc, char** argv, QObject *parent)
{
    rclcpp::init(argc, argv);

    //static executor
    rclcpp::executors::StaticSingleThreadedExecutor::SharedPtr rosExecutor;
    rosExecutor = std::make_shared<rclcpp::executors::StaticSingleThreadedExecutor>();
    m_RosNode = rclcpp::Node::make_shared("RemoteControlledNode");
    rosExecutor->add_node(m_RosNode);

    //assign subscriptions
    //first module
    m_BatteryVoltage1_Sub = m_RosNode->create_subscription<std_msgs::msg::Int32>("/battery_head", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_BatteryVoltage1_Callback,this,std::placeholders::_1));
    m_MotorSpeed_sx1_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/w_measure_head_left", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_sx1_Callback,this,std::placeholders::_1));
    m_MotorSpeed_dx1_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/temperature", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_dx1_Callback,this,std::placeholders::_1));
    //second module
    m_BatteryVoltage2_Sub = m_RosNode->create_subscription<std_msgs::msg::Int32>("/battery_middle", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_BatteryVoltage2_Callback,this,std::placeholders::_1));
    m_MotorSpeed_sx2_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/w_measure_middle_left", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_sx2_Callback,this,std::placeholders::_1));
    m_MotorSpeed_dx2_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/w_measure_middle_right", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_dx2_Callback,this,std::placeholders::_1));
    //third module
    m_BatteryVoltage2_Sub = m_RosNode->create_subscription<std_msgs::msg::Int32>("/battery_tail", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_BatteryVoltage3_Callback,this,std::placeholders::_1));
    m_MotorSpeed_sx2_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/w_measure_tail_left", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_sx3_Callback,this,std::placeholders::_1));
    m_MotorSpeed_dx2_Sub = m_RosNode->create_subscription<std_msgs::msg::Float32>("/w_measure_tail_right", rclcpp::SystemDefaultsQoS(), std::bind(&QNode::m_MotorSpeed_dx3_Callback,this,std::placeholders::_1));


    std::thread executor_thread(std::bind(&rclcpp::executors::StaticSingleThreadedExecutor::spin, rosExecutor));
    executor_thread.detach();
}

//first module
void QNode::m_BatteryVoltage1_Callback(const std_msgs::msg::Int32::SharedPtr msg){
    this->battery_voltage1 = msg->data;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_sx1_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_sx1 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_dx1_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_dx1 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
//second module
void QNode::m_BatteryVoltage2_Callback(const std_msgs::msg::Int32::SharedPtr msg){
    this->battery_voltage2 = msg->data;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_sx2_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_sx2 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_dx2_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_dx2 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
//third module
void QNode::m_BatteryVoltage3_Callback(const std_msgs::msg::Int32::SharedPtr msg){
    this->battery_voltage3 = msg->data;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_sx3_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_sx3 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
void QNode::m_MotorSpeed_dx3_Callback(const std_msgs::msg::Float32::SharedPtr msg){
    this->motor_speed_dx3 = (msg->data/1.3)+50;
    Q_EMIT this->msgSubscribed();
}
