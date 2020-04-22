#ifndef OS_DB_H
#define OS_DB_H

#include <iostream>


class OS_DB
{
public:
 OS_DB();
 OS_DB(std::string name, std::string version, int buildNumber, int servicePack,
       std::string compName, std::string/*OSTypeDB**/ osType);
 OS_DB(const OS_DB& cpy);
 ~OS_DB();

 std::string Name() const { return p_name; }
 std::string Version() const { return p_version; }
 std::string CompName() const { return p_compName; }
 int BuildNumber() const { return p_buildNumber; }
 int ServicePack() const { return p_servicePack; }
// OSTypeDB* OsType() const { return p_osType; }
 std::string OsType() const { return p_osType; }

private:
 // название операционной системы
 std::string p_name;
 std::string p_version;
 int p_buildNumber;
 int p_servicePack;
 // имя машины
 std::string p_compName;
// OSTypeDB* p_osType = nullptr;
 std::string p_osType;
};
#endif // OS_DB_H
