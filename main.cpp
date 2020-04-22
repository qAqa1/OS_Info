#include <QCoreApplication>

#include "os_db.h"
#include "processordb.h"

#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "OS: ";
    OS_DB os_db;
    qDebug() << os_db;

    ProcessorDB pr(66);
    qDebug() << "Processor: ";
    qDebug() << pr;

    return a.exec();
}
