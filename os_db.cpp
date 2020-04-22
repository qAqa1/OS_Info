#include "os_db.h"

//#include <windows.h>
//#include <stdio.h>
////#include <iostream>
//#include <conio.h>
//#include<TCHAR.H>
#include <QDebug>
#include <QOperatingSystemVersion>
#include <QSysInfo>

using namespace std;

OS_DB::OS_DB()
{
    qDebug() << QOperatingSystemVersion::current();
    qDebug() << "----------------------------------";
    QOperatingSystemVersion inf =  QOperatingSystemVersion::current();
//    qDebug() << inf.name();
//    qDebug() << inf.majorVersion();
//    qDebug() << inf.minorVersion();
//    qDebug() << inf.microVersion();
//    qDebug() << inf.type();
//    p_name = inf.name().toStdString();
    qDebug() << "p_name" << " - "<< inf.name();
    qDebug() << "p_version" << " - " << inf.majorVersion();
    qDebug() << "p_buildNumber" << " - " << inf.microVersion();
    qDebug() << "p_servicePack" << " - " << inf.minorVersion();
    qDebug() << "p_compName" << " - " << QSysInfo::machineUniqueId();
    qDebug() << "p_osType" << " - " << inf.type();

}

OS_DB::OS_DB(std::string name, std::string version, int buildNumber, int servicePack,
             std::string compName, std::string osType)
{

}
