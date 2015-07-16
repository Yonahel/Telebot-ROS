//Author: Yonah Elorza
//This program publishes motor coordinates to the CM-700, which updates the local motors

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <telebot/Coord.h>
#include <sensor_msgs/JointState.h>
#include <fstream>
#include <iostream>

using namespace std;

ros::Publisher pub;

void dataMessageRecieved(const sensor_msgs::JointState msg) { 

	//ros::NodeHandle nh;
	telebot::Coord msg2;
	//pub = nh.advertise<telebot::Coord>("motor_coord", 1000);

	for(int x = 0; x < 12; x++){
 		if (msg.name[x] == "lshoulder_joint"){
		msg2.ID = 20;
		}
		else if (msg.name[x] == "l2shoulder_joint"){
		msg2.ID = 21;
		}
		else if (msg.name[x] == "lupperarm_joint"){
		msg2.ID = 22;
		}
		else if (msg.name[x] == "lelbow_joint"){
		msg2.ID = 23;
		}
		else if (msg.name[x] == "lforearm_joint"){
		msg2.ID = 24;
		}
		else if (msg.name[x] == "lwrist_joint"){
		msg2.ID = 25;
		}
		else if (msg.name[x] == "rshoulder_joint"){
		msg2.ID = 30;
		}
		else if (msg.name[x] == "r2shoulder_joint"){
		msg2.ID = 31;
		}
		else if (msg.name[x] == "rupperarm_joint"){
		msg2.ID = 32;
		}
		else if (msg.name[x] == "relbow_joint"){
		msg2.ID = 33;
		}
		else if (msg.name[x] == "rforearm_joint"){
		msg2.ID = 34;
		}
		else if (msg.name[x] == "rwrist_joint"){
		msg2.ID = 35;
		}
	
		if(msg.position[x] == 0)
		{
			msg2.GOAL_POS = 2048;	
		}
		else if (msg.position[x] < 0)
		{
			int y;
			y = msg.position[x];
			y *= -1;
			y /= 0.00149;
			msg2.GOAL_POS = 2048 - y; 
		}
		else if (msg.position[x] > 0)
		{
			int y;
			y /= 0.00149;
			msg2.GOAL_POS = 2048 + y;
		}
  
        	msg2.SPEED = (msg.velocity[x] * 60)/(2*3.14);
	 
	pub.publish(msg2);

	ROS_INFO_STREAM("Sending motor coordinates: " 
          << "ID=" << msg2.ID << " "
          << "Goal=" << msg2.GOAL_POS << " "
          << "Speed=" << msg2.SPEED
          );		
  	}
}

int main(int argc, char **argv) {
     ros::init(argc, argv, "telebot_pub");

     ros::NodeHandle nh;	
	
     pub = nh.advertise<telebot::Coord>("motor_coord", 1000);

     ros::Subscriber sub = nh.subscribe("joint_states", 1000, &dataMessageRecieved);

     ros::spin();
}
