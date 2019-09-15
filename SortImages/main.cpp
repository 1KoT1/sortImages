#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qDebug()<<QCoreApplication::applicationFilePath();
    QSettings config(QCoreApplication::applicationFilePath() + ".ini", QSettings::IniFormat);
    config.setIniCodec("UTF-8");
    qDebug()<<config.value("SourceDir");
    qDebug()<<config.value("TrashDir");
    qDebug()<<config.value("ValidDir");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
