#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#define TRUN_ON_OPENCV 0

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.load(url);

#if TRUN_ON_OPENCV
    // read an image
    cv::Mat image = cv::imread("C:\\Users\\willy\\Desktop\\9b060ac5f7e3434585b5c69000318898.jpeg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
#endif
    return app.exec();
}
