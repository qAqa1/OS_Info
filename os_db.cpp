#include "os_db.h"

#include <QOperatingSystemVersion>
#include <QSysInfo>
#include <QMetaEnum>
#include <QMetaObject>
#include "wmic.h"

using namespace std;

OS_DB::OS_DB()
{
    QOperatingSystemVersion inf = QOperatingSystemVersion::current();
    QOperatingSystemVersion::OSType OSType = inf.type();

    if (OSType == QOperatingSystemVersion::OSType::Windows)
    {
        p_name = Wmic::GetValue("os get", "Caption").toStdString();
    }
    else
    {
        p_name = inf.name().toStdString();
    }
    p_version = std::to_string(inf.majorVersion());
    p_buildNumber = inf.microVersion();
    p_servicePack = inf.minorVersion();
    p_compName = QSysInfo::machineUniqueId().toStdString();
    p_osType = inf.type();
}

OS_DB::OS_DB(std::string name, std::string version, int buildNumber, int servicePack,
             std::string compName, QOperatingSystemVersion::OSType osType)
{
    p_name = name;
    p_version = version;
    p_buildNumber = buildNumber;
    p_servicePack = servicePack;
    p_compName = compName;
    p_osType = osType;
}

QString OS_DB::DebugDescription() const
{
    QString result = "";
    const QString border = ", ";
    const QString borderBetweenTitleAndValue = " = ";

    result += "Name";
    result += borderBetweenTitleAndValue;
    result += QString::fromStdString(Name());
    result += border;

    result += "Version";
    result += borderBetweenTitleAndValue;
    result += QString::fromStdString(Version());
    result += border;

    result += "CompName";
    result += borderBetweenTitleAndValue;
    result += QString::fromStdString(CompName());
    result += border;

    result += "BuildNumber";
    result += borderBetweenTitleAndValue;
    result += QString::number(BuildNumber());
    result += border;

    result += "ServicePack";
    result += borderBetweenTitleAndValue;
    result += QString::number(ServicePack());
    result += border;

    result += "OsType";
    result += borderBetweenTitleAndValue;
    result += QString::number(OsType());
    return result;
}

OS_DB::operator QString()  const { return  DebugDescription(); }

OS_DB::operator std::string() const { return  DebugDescription().toStdString(); }
