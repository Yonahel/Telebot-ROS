//Author: Yonah Elorza
//This program publishes motor coordinates to the mbed, which updates the mobility motors

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <telebot/Coord.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SimpleSerial.h"

using namespace std;

int main(int argc, char **argv) {
     ros::init(argc, argv, "mobility_pub");	

     ros::NodeHandle nh;

     //ros::Publisher pub = nh.advertise<telebot::Mobility>("mobility_sys", 1000);

     //telebot::Mobility msg;	
     
     ros::Rate loop_rate(10);

     while(ros::ok()){

     SimpleSerial serial("/dev/ttybluetooth",57600);

     std:string motor = serial.readLine();

     ROS_INFO_STREAM(motor);

     //pub.publish(msg);

     ros::spinOnce();

     loop_rate.sleep();

     }
}
