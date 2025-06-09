#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "basic_func.h"
#include "weather_provider.h"
#include "music_player.h"
#include "youtube_player.h"
#include "bluetoothmanager.h"
#include "mirror_provider.h"
#include "clicknotier.h"

#include "client.h" // vchan

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TimeProvider timeProvider;
    SpeedProvider speedProvider;
    WeatherProvider weatherProvider;
    MusicPlayer musicPlayer;
    YoutubePlayer youtubePlayerProvider;
    BluetoothManager btManager;
    MirrorProvider mirrorProvider;
    ClickNotifier clickNotifier;
    Client client;

//    QCommandLineParser parser;
//    parser.setApplicationDescription("Qt Wayland Application");
//    parser.addHelpOption(); // --help option
//    parser.addOption({{"fullscreen"}, "Enable fullscreen mode."}); // --fullscreen option
//    parser.addOption({{"display"}, "Set display output.", "display"}); // --display option
//    parser.process(app);

//    QWindow mainWindow;

//    if (parser.isSet("fullscreen")) {
//        qDebug() << "Fullscreen mode enabled.";
//        mainWindow.showFullScreen();
//    }else{
//        mainWindow.show();
//    }

//    // --display option
//    if (parser.isSet("display")) {
//        QString displayValue = parser.value("display");
        
//        if (displayValue == 'dashboard'){
//            mainWindow.setPosition(1000, 0);
//        }
//        else if (displayValue == 'infortainment'){
//            mainWindow.setPosition(0,0);
//        }
//    }

    client.start();

    engine.rootContext()->setContextProperty("timeProvider", &timeProvider);
    engine.rootContext()->setContextProperty("speedProvider", &speedProvider);
    engine.rootContext()->setContextProperty("weatherProvider", &weatherProvider);
    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);
    engine.rootContext()->setContextProperty("youtubePlayerProvider", &youtubePlayerProvider);
    engine.rootContext()->setContextProperty("btManager", &btManager);
    engine.rootContext()->setContextProperty("client", &client);
    engine.rootContext()->setContextProperty("clickNotifier", &clickNotifier);
    engine.rootContext()->setContextProperty("MirrorProvider", &mirrorProvider);
    qmlRegisterType<YoutubePlayer>("youtubePlayer", 1, 0, "YoutubePlayer");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
