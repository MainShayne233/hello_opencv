#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

int main(int argc, char** argv)
{
  char* imageName = argv[1];

  Mat image = imread( imageName, 1 );

  if ( argc != 2 || !image.data )
  {
    printf("I need a path to an image!"); 
    return -1;
  }

  Mat gray_image;
  cvtColor( image, gray_image, CV_BGR2GRAY );

  imwrite( "./gray_image.jpg", gray_image );

  namedWindow( imageName, 1 );
  namedWindow( "Gray Image", 1 );

  imshow( imageName, image );
  imshow( "Gray Image", gray_image );

  waitKey(0);

  return 0;
}
