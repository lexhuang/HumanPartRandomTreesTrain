
#include <stdio.h>
#include <dirent.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

Mat processFrame, phaseDataFloat, showFrame;
double dx[12], dy[12];
#define PI 3.14159265
#define test PI / 180.0
int fileCount = -2;

static void onMouse( int event, int x, int y, int, void* )
{
    if( event == EVENT_LBUTTONDBLCLK ){
        cout << x << ", " << y << " phase:" << phaseDataFloat.at<uint16_t>(x, y) << endl;
        processFrame.copyTo(showFrame);
        circle(showFrame, Point(x,y), 1, Scalar(255, 255, 255));
        int r = 50;
        circle(showFrame, Point(x,y), 50, Scalar(255, 255, 255));
        for(int i = 0; i < 12; i++){
            line(showFrame, Point(x, y), Point((double)(x + r * dx[i]), (double)(y + r* dy[i])), Scalar(255,255,255));
        }

        for(int i = -5; i < 6; i++){
            circle(showFrame, Point(x + i,y), 1, Scalar(255, 0, 0));
        }
        imshow("test", showFrame);
    }
}

int main(int argc, char *argv[])
{
    string folderName = "/home/lexhuang/humanSample/";
    string fileName = "sample6.yml";
    for(int i = 0; i < 12; i++){
        dx[i] = cos(i * 30 * test);
        dy[i] = sin(i * 30 * test);
    }

    DIR *dpdf;
    struct dirent *epdf;
    dpdf = opendir("/home/lexhuang/humanSample/");
    if (dpdf != NULL){
       while (epdf = readdir(dpdf)){
          cout << epdf->d_name << endl;
          fileCount++;
          // std::out << epdf->d_name << std::endl;
       }
    }
    cout << "File Count:" << fileCount << endl;

    FileStorage fs("/home/lexhuang/humanSample/sample6.yml", FileStorage::READ );
    fs["process"] >> processFrame;
    fs["float"] >> phaseDataFloat;
    namedWindow("test", 0);
    imshow("test", processFrame);
    setMouseCallback("test", onMouse, 0);
    cvWaitKey(0);
    system("pause");
    return 1;
}

