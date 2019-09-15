#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include "imageclassifikator.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QSettings config(QCoreApplication::applicationFilePath() + ".ini", QSettings::IniFormat);
	config.setIniCodec("UTF-8");

	QQmlApplicationEngine engine;
	ImageClassifikator imageClassifikator(
	      config.value("SourceDir").toString(),
	      config.value("ValidDir").toString(),
	      config.value("TrashDir").toString(),
	      &app);
	engine.rootContext()->setContextProperty("imageClassifikator", &imageClassifikator);
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
	                 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
