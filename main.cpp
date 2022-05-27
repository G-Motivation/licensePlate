#include "licenseplatedialog.h"

#include <QApplication>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#define TRUN_ON_TEST 1
using namespace testing;

#if TRUN_ON_TEST
TEST(licensePlateDialog, yoloFile)
{
    licensePlateDialog w;
    EXPECT_TRUE(w.detectbyYOLO());
}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    #if TRUN_ON_TEST
    ::testing::InitGoogleTest(&argc, argv);
    ;
    #endif
    licensePlateDialog w;
    w.show();
#if 0
    cv::Mat image = cv::imread("C:/Users/Willy/Desktop/278908130_7560594323980957_4943708686815806592_n.jpg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
#endif
    return (!RUN_ALL_TESTS() && a.exec());
}
