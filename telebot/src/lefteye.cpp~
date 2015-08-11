#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include "SimpleSerial.h"

int main(int argc, char **argv){

	ros::init(argc, argv, "lstream_pub");
	ros::NodeHandle nh;
  	image_transport::ImageTransport it(nh);
	
	image_transport::Publisher pub = it.advertise("stream_img", 1);

	std::istringstream video_sourceCmd("/dev/video0");
        int video_source;
        // Check if it is indeed a number
        //if(!(video_sourceCmd >> video_source)) return 1;
   
        cv::VideoCapture cap(video_source);
        // Check if video device can be opened with the given index
        //if(!cap.isOpened()) return 1;
        cv::Mat frame;
        sensor_msgs::ImagePtr msg;
  
        ros::Rate loop_rate(5);
        while (nh.ok()) {
          cap >> frame;
          // Check if grabbed frame is actually full with some content
          if(!frame.empty()) {
            msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
            pub.publish(msg);
            cv::waitKey(1);
          }
      
          ros::spinOnce();
          loop_rate.sleep();
        }
}
