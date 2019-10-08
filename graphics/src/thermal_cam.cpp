#ifdef WIN32
 #include <cv.h>
 #include <highgui.h>
#else
 #include <opencv/cv.h>
 #include <opencv/highgui.h>
#endif
#ifndef THERMAL_CAM_H
#define THERMAL_CAM_H

#ifdef _PRINT_HEADER_
  #warning "thermal_cam.h"
#endif
#include "gui_helper_functions.h"
#include "GraphicsCamera.h"
#include "GraphicsWindowInterface.h"
#include "GraphicsWidget.h"
#endif
#define MAX_H	500
#define MAX_W	500

namespace mars {
  namespace graphics {


using namespace std;
using namespace  cv;
int find_temp(int r, int g, int b);


int find_temp(int r, int g, int b) {
	return 0;
}

void thermal_cam::getTempImageData(char*buffer, int& width, int& height)
{
	rttImage = new osg::Image();
        rttImage->allocateImage(widgetWidth, widgetHeight,
                                1, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV);
        osgCamera->attach(osg::Camera::COLOR_BUFFER, rttImage.get());
        rttTexture->setImage(rttImage);


if(isRTTWidget) {
        Mat img = rttImage;
        cvtColor(img, hsv, COLOR_RGB2HSV);
        osg::Image *image =  img;
        width = img->s();
        height = img->t();
        memcpy(buffer, img->data(), width*height*4);
      }
      else
      {
        //slow but works...
        void *data;
        postDrawCallback->getTempImageData(&data, width, height);
        memcpy(buffer, data, width*height*4);
        free(data);
	  }


	//Mat img = imread("test.jpg");
	/*cv::Mat img= cv::imread("nature.png");
	
	Mat hsv;
	if (img.empty())
		cout << "failed to open image" << std::endl;
	else if(img.rows>300 || img.cols>300)
		cout << "Image Dimension must be less 300x300" << std::endl;
	else {
		cvtColor(img, hsv, COLOR_RGB2HSV);

		namedWindow("RGB", WINDOW_NORMAL);
		imshow("RGB", img);

		namedWindow("HSV", WINDOW_NORMAL);
		imshow("HSV", hsv);
		//imwrite("hsv.png", hsv);
	}*/



	/*int count=0;
	int h, s, v;
	double w, l;
	double b = 2.667771955e-3;
	double max,min, tmp;
	int temp[300][300];
	for (int i = 0; i < hsv.rows; i++) {
		for (int j = 0; j < hsv.cols; j++) {
			h = (int)hsv.at<Vec3b>(i, j)[0];
			s = (int)hsv.at<Vec3b>(i, j)[1];
			v = (int)hsv.at<Vec3b>(i, j)[2];
			w = 850 - (185 * h) / 220;
			l = w * 1e-8;
			temp[i][j] = (int)ceil(b / l);
			
			//cout << "HSV: " << r << ", " << g << ", " << b << "\n";
			
		}
	}
	min = 100000.00;
	max = -1;
	int x_min,x_max, y_min,y_max;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			if (temp[i][j] > max) {
				max = temp[i][j];
				x_max = i;
				y_max = j;
			}
			if (temp[i][j] < min) {
				min = temp[i][j];
				x_min = i;
				y_min = j;
			}
			//cout<<temp[i][j]<<" ";
		}
		//cout << endl;
	}
	cout << "Image Dimension: " << img.rows << "x" << img.cols << endl;
	cout << "Maximum Temperature: " << max << " at " << x_max << ", " << y_max << "\n";
	cout <<  "Minimum Temperature: "<<min << " at " <<x_min<<", "<<y_min<<"\n";

	waitKey(0);
	return 0;*/
}
 } // end of namespace graphics
} // end of namespace mars
