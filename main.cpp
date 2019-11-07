#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include "pdf.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*
     * CONNEXION A LA BASE DE DONNEE
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Atlantik");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();

    //MainWindow w;
    //w.show();

    //Creer le pdf
    PDF *monPDF = new PDF("mesBateaux");

    delete monPDF;

    return a.exec();
}
