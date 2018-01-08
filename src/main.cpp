#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "healthdata.h"
#include "healthdatame.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QCoreApplication::setOrganizationName("Iktwo");
    QCoreApplication::setOrganizationDomain("iktwo.com");
    QCoreApplication::setApplicationName("Health");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<HealthDataMe>("com.iktwo.health", 1, 0, "HealthDataMe");
    qmlRegisterType<HealthData>("com.iktwo.health", 1, 0, "HealthData");

    engine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
