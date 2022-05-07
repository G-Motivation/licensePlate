#include "licenseplatedialog.h"

#include <QApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#define TRUN_ON_TEST 0
using namespace testing;

#if TRUN_ON_TEST
bool check()
{
    return true;
}
TEST(Function, check)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(check());
}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    #if TRUN_ON_TEST
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
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
    return a.exec();
}
