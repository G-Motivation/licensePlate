#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>

#include <QQmlComponent>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/main.qml")));

    QObject *mainPage = component.create();
    QObject *item = mainPage->findChild<QObject *>("buttonTest");
    item->setProperty("text", "Text from C++");

    return app.exec();
}
