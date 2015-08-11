//Author: Yonah Elorza

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    VideoCapture lefteye(0);    
    VideoCapture righteye(1);

    while(1){
    Mat cameraFrame1;
    Mat cameraFrame2;

    lefteye >> cameraFrame1;
    righteye >> cameraFrame2;

    namedWindow("OpenCV1", WINDOW_NORMAL);
    namedWindow("OpenCV2", WINDOW_NORMAL);

    imshow("OpenCV1", cameraFrame1);
    imshow("OpenCV2", cameraFrame2);

    waitKey(1);
    }
    return 0;
}
