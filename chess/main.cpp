#include <QApplication>
#include <QLocale>
#include <QTranslator>
//#include "view/mywidget.h"
#include "view/mymainwindow.h"
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
    MyMainWindow main_window;
    main_window.show();
//    MainWidget w;
    msapp app;
    app.Init(main_window.chess_board);
    //w.show();
    return a.exec();
}
