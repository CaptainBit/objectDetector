#pragma once

#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

class ObjectGrabber
{
public:
	ObjectGrabber();
	void setMat(Mat imgToSet);
	int getNumberObject();
private:
	Mat _img;
};


