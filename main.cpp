#include "licenseplatedialog.h"

#include <QApplication>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#define TRUN_ON_TEST 1
using namespace testing;

extern std::shared_ptr<YOLO> yolo = nullptr;
extern std::unique_ptr<licensePlateDialog> w = nullptr;
#if TRUN_ON_TEST
TEST(licensePlateDialog, yoloFile)
{
    EXPECT_TRUE(w->setUpYOLO(yolo));
}
TEST(licensePlateDialog, yoloDetect)
{
    cv::Mat image = cv::imread("C:/Users/Willy/Desktop/__abby0415_285195171_898579464874078_5216776885753997202_n.jpg", 1);
    EXPECT_TRUE(w->detectbyYOLO(image, yolo));
}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    #if TRUN_ON_TEST
    ::testing::InitGoogleTest(&argc, argv);
    ;
    #endif
    w = std::make_unique<licensePlateDialog>();
#if 0
    w->show();
    cv::Mat image = cv::imread("C:/Users/Willy/Desktop/278908130_7560594323980957_4943708686815806592_n.jpg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
#endif
    return (!RUN_ALL_TESTS() && a.exec());
}
