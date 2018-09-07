#include "ObjectGrabber.h"

ObjectGrabber::ObjectGrabber(){}

void ObjectGrabber::setMat(Mat imgToSet)
{
	_img = imgToSet;
}

int ObjectGrabber::getNumberObject() 
{
	int nbObject = 0;
	int** tabColor = new int*[_img.rows, _img.cols];

	for (int col = 1; col < _img.cols; col++) 
	{

		for (int row = 1; row < _img.rows; row++ )
		{
			uchar middle = _img.at<uchar>(row, col);
			uchar left = _img.at<uchar>(row, col -1);
			uchar top = _img.at<uchar>(row -1, col);

			//si pixel est blanche
			if (middle == 255) 
			{
				//si pixel correspond
				if (tabColor[row - 1, col] != 0)
				{
					tabColor[row, col] = tabColor[row - 1, col];
				}
				else
				{
					if (tabColor[row, col - 1] != 0)
					{
						tabColor[row, col] = tabColor[row, col - 1];
					}
					else
					{
						nbObject++;
						tabColor[row, col] = new int[nbObject];
					}
				}
			}
			
		}
	}
	return 0;
}
