#include<iostream>
#ifdef WIN32
 #include <cv.h>
 #include <highgui.h>
#else
 #include <opencv/cv.h>
 #include <opencv/highgui.h>
#endif
#define MAX_H	500
#define MAX_W	500

using namespace std;
using namespace  cv;
int find_temp(int r, int g, int b);


int find_temp(int r, int g, int b) {
	return 0;
}

int main()
{
	//Mat img = imread("test.jpg");
	Mat img = imread("nature.png", IMREAD_COLOR);
	
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
	}
	int count=0;
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
	return 0;
}
