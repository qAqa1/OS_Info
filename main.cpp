#include <QCoreApplication>
#include "os_db.h"
#include "processordb.h"

#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QCoreApplication a(argc, argv);

//    OS_DB* os_db = new OS_DB();
    ProcessorDB/***/ pr/* = new ProcessorDB()*/;
    qDebug() << pr;

    return a.exec();
}
