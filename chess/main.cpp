#include <QApplication>
#include <QLocale>
#include <QTranslator>
//#include "view/mywidget.h"
#include"./app/msapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "chess_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWidget w;
    msapp app;
    app.Init(w);
    //w.show();
    return a.exec();
}
