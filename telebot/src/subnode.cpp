//This program subscribes to telebot and shows its messages on the screen

//This header defines the standard ROS classes.
#include <ros/ros.h>
//#include <iomanip>
#include <telebot/Coord.h>
//#include <fstream>
#include "SimpleSerial.h"

void dataMessageRecieved(const telebot::Coord msg) {
     
	std::ostringstream ID;
	std::ostringstream GOAL;	
	std::ostringstream SPD;
	
	ID << msg.ID;
	GOAL << msg.GOAL_POS;
	SPD << msg.SPEED;
	/*if(msg.ID == 1 || msg.ID == 2)
	{
	     std::ostringstream F1;
	     std::ostringstream F2;
	     std::ostringstream F3;
	     std::ostringstream F4;
	     std::ostringstream F5;
	     F1 << msg.F1;
	     F2 << msg.F2;
	     F3 << msg.F3;
	     F4 << msg.F4;
	     F5 << msg.F5;

	     std::string data = std::string() + '<' + ID.str() + ' ' + F1.str() + ' ' + F2.str() + ' ' + F3.str() + ' ' + F4.str() + ' ' + F5.str() + ' ' + SPD.str() + '>';	
	     ROS_INFO_STREAM(data);
             SimpleSerial serial("/dev/ttyUSB0",57600);	

	     serial.writeString(data);
	}*/

	//else{
	
	std::string data = std::string() + '<' + ID.str() + ' ' + GOAL.str() + ' ' + SPD.str() + '>';	
	ROS_INFO_STREAM(data);
        SimpleSerial serial("/dev/ttyUSB0",57600);

        serial.writeString(data);
	//}
       //ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "<" << msg.ID << " " << msg.GOAL_POS << " " << msg.SPEED << ">");
}

int main(int argc, char **argv) {
     //Initialize the ROS system and become a node
     ros::init(argc, argv, "telebot_sub");
     ros::NodeHandle nh;

     //Create a subscriber object
     ros::Subscriber sub = nh.subscribe("motor_coord", 1000, &dataMessageRecieved);

     //Let ROS take over
     ros::spin();
     
}
