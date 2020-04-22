#ifndef OS_DB_H
#define OS_DB_H

#include <iostream>
#include <QOperatingSystemVersion>

// TODO: портировать на линукс

class OS_DB
{
    public:
     OS_DB();
     OS_DB(std::string name, std::string version, int buildNumber, int servicePack,
           std::string compName, QOperatingSystemVersion::OSType/*OSTypeDB**/ osType);
     OS_DB(const OS_DB& cpy);
    // ~OS_DB();

     std::string Name() const { return p_name; }
     std::string Version() const { return p_version; }
     std::string CompName() const { return p_compName; }
     int BuildNumber() const { return p_buildNumber; }
     int ServicePack() const { return p_servicePack; }
    // OSTypeDB* OsType() const { return p_osType; }
     QOperatingSystemVersion::OSType OsType() const { return p_osType; }

    private:
     std::string p_name; // название операционной системы
     std::string p_version;
     int p_buildNumber;
     int p_servicePack;
     std::string p_compName; // имя машины
    // OSTypeDB* p_osType = nullptr;
     QOperatingSystemVersion::OSType p_osType;

     QString DebugDescription() const;
    public:
     operator QString() const;
     operator std::string() const;
};
#endif // OS_DB_H
