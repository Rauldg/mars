 #include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()
{
          Mat img;
         
          
          img = imread("getImage()", CV_LOAD_IMAGE_COLOR);

         
          if (img.empty()) {
                   cout << "Error" << endl;
                   return -1;
          }

          namedWindow("New_image", CV_WINDOW_AUTOSIZE);

          imshow("New_image", img);

          // print number of channels in image
          cout << "image channels: " << img.channels() <<  endl;

          // check if image is a single channel
          if (img.channels() == 1) {
                   Scalar pixel = img.at<uchar>(10, 10);
                   cout << "Pixel value at 5,6 cordinate : " << pixel.val[0] << endl;
          }
    // check if image is a 3 channel

          else if (img.channels() == 3) {
         
                   Vec3b pixel = img.at<Vec3b>(10, 10);
                   int blue = pixel.val[0];
                   int green = pixel.val[1];
                   int red = pixel.val[2];
          }

          else {
                   cout << "this is not a single channel image" << endl;
          }

          waitKey(0);
          return 0;
}
