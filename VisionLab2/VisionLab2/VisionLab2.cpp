// VisionLab2.cpp : définit le point d'entrée pour l'application console.
//

#include <opencv2\opencv.hpp>
#include "stdafx.h"
#include "ObjectGrabber.h"


using namespace cv;
using namespace std;



int main()
{

	ObjectGrabber objGrabber;
	int nb;

	Mat hsv_image,mask2,mask1, mask;

	
	Mat picture = imread("trafficlight.jpg", 1);
	vector<Vec4i> hierarchy;
	vector<vector<Point> > contours;
	cvtColor(picture, hsv_image, COLOR_BGR2HSV);


	////Masque pour avoir les trois couleurs
	inRange(hsv_image, Scalar(20, 100, 100), Scalar(30, 255, 255), mask2);
	inRange(hsv_image, Scalar(0, 100, 100), Scalar(10, 255, 255), mask1);
	bitwise_or(mask1, mask2, mask);

	objGrabber.setMat(mask);
	nb = objGrabber.getNumberObject();
	imshow("bin", mask);
	cout << nb;
	
	//inRange(hsv_image, Scalar(45, 50, 50), Scalar(90, 255, 255), mask3);
	////OU binaire pour ajouter les couleurs
	//bitwise_or(mask1, mask2, mask);
	//bitwise_or(mask, mask3, mask);
	//findContours(mask, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	////trouver les plus gros contours
	//int largestArea = 0;
	//int largestContourIndex = 0;
	//int secondLargestArea = 0;
	//int secondContourIndex = 0;

	////trouver le plus gros
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	double area = contourArea(contours[i]);
	//	if (area > largestArea) {
	//		largestArea = area;
	//		largestContourIndex = i;
	//	}

	//}
	////trouver le deuxieme plus gros
	//for (int i = 0; i< contours.size(); i++)
	//{
	//	double area = contourArea(contours[i]);
	//	if (area > secondLargestArea && area < largestArea) {
	//		secondLargestArea = area;
	//		secondContourIndex = i;

	//	}
	//}
	//

	//drawContours(picture, contours, largestContourIndex, Scalar(128, 128, 128), -1, 8, hierarchy, 0, Point());
	//drawContours(picture, contours, secondContourIndex , Scalar(112, 128, 144), -1, 8, hierarchy, 0, Point());

	//imshow("picture", picture);
	//imshow("Treshold", mask);
	//imshow("originale", pictureOrig);

	//waitKey(0);
	waitKey(0);
    return 0;
}


