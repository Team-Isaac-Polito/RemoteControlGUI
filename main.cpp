#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QDebug>
#include <QThread>
#include <QVariant>
#include <QTime>
#include <backend.h>


void backendTry(BackEnd *backEnd){
    int var = 0;
    for(; var<=100; var++) {
        backEnd->setDynamicRange(var);

        QTime dieTime= QTime::currentTime().addMSecs(100);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    return;
}


int main(int argc, char *argv[])
{

    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QGuiApplication app(argc, argv);
    QQuickView view;

    view.setMaximumSize(QSize(800,480));
    view.setMinimumSize(QSize(800,480));
    view.engine()->addImportPath("qrc:/qml/imports");
    view.setSource(QUrl("qrc:/main.qml"));
    if(!view.errors().isEmpty())
        return -1;
    QQuickItem *item = view.rootObject();

    BackEnd backEnd(argc, argv, item);
    view.rootContext()->setContextProperty("backEnd", &backEnd);
    view.show();
    //view.showFullScreen();

    backendTry(&backEnd);

    return app.exec();
}
