#include <QCoreApplication>
#include "os_db.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QCoreApplication a(argc, argv);

    OS_DB* os_db = new OS_DB();

    return a.exec();
}
