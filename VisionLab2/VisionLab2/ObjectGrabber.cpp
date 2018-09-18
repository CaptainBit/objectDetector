#include "ObjectGrabber.h"

ObjectGrabber::ObjectGrabber(){}

void ObjectGrabber::setMat(Mat imgToSet)
{
	_img = imgToSet;
}

int ObjectGrabber::getNumberObject() 
{
	int nbObject = 0;
	Mat tabColor = _img.clone();
	tabColor.setTo(0);
	int minimum;
	for (int row = 1; row < _img.rows; row++) 
	{

		for (int col = 1; col < _img.cols; col++ )
		{
			uchar middle = _img.at<uchar>(row, col);
			uchar left = tabColor.at<uchar>(row, col - 1);
			uchar top = tabColor.at<uchar>(row - 1, col);

			//si pixel est blanche
			if (middle == 255) 
			{
				if (left != 0 || top != 0)
				{
					minimum = min(left, top);
					if (minimum == 0) {
						tabColor.at<uchar>(row, col) = max(left, top);
					}
					else
					{
						tabColor.at<uchar>(row, col) = minimum;
					}
				}
				else
				{
					nbObject++;
					tabColor.at<uchar>(row, col) = nbObject;
				}
				
			}
			
		}
	}
	int imax = 0;
	for (int row = _img.rows -2 ; row >= 0; row--)
	{

		for (int col = _img.cols -2 ; col >= 0; col--)
		{
			uchar middle = _img.at<uchar>(row, col);
			uchar right = tabColor.at<uchar>(row, col + 1);
			uchar bottom = tabColor.at<uchar>(row +1, col);

			//si pixel est blanche
			if (middle == 255)
			{
				if (right != 0 || bottom != 0)
				{
					minimum = min(right, bottom);
					if (minimum == 0) 
					{
						tabColor.at<uchar>(row, col) = max(right, bottom);
					}
					else {
						tabColor.at<uchar>(row, col) = minimum;
					}
					if (imax < tabColor.at<uchar>(row, col))
						imax = tabColor.at<uchar>(row, col);
				}
			}

		}
	}
	return imax;
}

