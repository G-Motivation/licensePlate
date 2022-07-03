#include <QApplication>
#include <runyolo.h>
#define TRUN_ON_TEST 1
using namespace testing;

#if TRUN_ON_TEST
TEST(licensePlateDialog, yoloFile)
{
    EXPECT_TRUE(runYolo::w->setUpYOLO(runYolo::yolo));
    if (!runYolo::yolo) ASSERT_TRUE(0);
}
TEST(licensePlateDialog, yoloDetect)
{
   cv::Mat image = cv::imread("C:/Users/Willy/Desktop/191103-13921-1-apGNK.png", 1);
   EXPECT_TRUE(runYolo::w->detectbyYOLO(image, runYolo::yolo));
}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    runYolo::w = std::make_unique<licensePlateDialog>();
    #if TRUN_ON_TEST
    ::testing::InitGoogleTest(&argc, argv);
    #endif
#if 0
    cv::Mat image = cv::imread("C:/Users/Willy/Desktop/marion/11f56bdd.jpg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
#endif
    return (RUN_ALL_TESTS() && a.exec());
}
