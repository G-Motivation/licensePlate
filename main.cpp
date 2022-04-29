#include "licenseplatedialog.h"

#include <QApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    licensePlateDialog w;
    w.show();

    cv::Mat image = cv::imread("C:/Users/Willy/Desktop/278908130_7560594323980957_4943708686815806592_n.jpg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);

    return a.exec();
}
