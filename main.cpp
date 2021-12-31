#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>

#include <QQmlComponent>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#define TRUN_ON_OPENCV 0

int main(int argc, char *argv[])
{

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/main.qml")));
    QObject *mainPage = component.create();
    QObject *item = mainPage->findChild<QObject *>("buttonTest");
    item->setProperty("text", "Text from C++");
#else
     QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "licensePlate_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
#endif


    return app.exec();
}


