#include "processordb.h"

#include <QOperatingSystemVersion>
#include <QString>
#include <QStringList>
#include "wmic.h"

namespace WmicParams
{
// wmic cpu get - все параметры

    const QString name = "Name",
//                  DeviceID = "DeviceID",
                  NumberOfCores = "NumberOfCores",
                  NumberOfLogicalProcessors = "NumberOfLogicalProcessors",
                  MaxClockSpeed = "MaxClockSpeed";
}

ProcessorDB::ProcessorDB(int id)
{
    QOperatingSystemVersion inf = QOperatingSystemVersion::current();
    QOperatingSystemVersion::OSType OSType = inf.type();

    if (OSType == QOperatingSystemVersion::OSType::Windows)
    {
        p_id = (double)id;
        p_name = GetWindowsCPUParam(WmicParams::name).toStdString();
        p_clock = GetWindowsCPUParam(WmicParams::MaxClockSpeed).toDouble();
        p_logicCores = GetWindowsCPUParam(WmicParams::NumberOfLogicalProcessors).toInt();
        p_physCores = GetWindowsCPUParam(WmicParams::NumberOfCores).toInt();
        p_perf = CalcGflops(p_clock, p_physCores);
    }
}

ProcessorDB::ProcessorDB(int id, std::string name, double perf, double clock, int logicCores, int physCores)
{
    p_id = (double)id;
    p_name = name;
    p_clock = perf;
    p_logicCores = clock;
    p_physCores = logicCores;
    p_perf = physCores;
}

QString ProcessorDB::GetWindowsCPUParam(QString paramName)
{
    return Wmic::GetValue("cpu get", paramName);
}

double ProcessorDB::CalcGflops(double maxClockSpeed, double coresCount)
{
    const double m = 0.004; // 4*10^-3
    return maxClockSpeed * coresCount * m;
}

QString ProcessorDB::DebugDescription() const
{
    QString result = "";
    const QString border = ", ";
    const QString borderBetweenTitleAndValue = " = ";

    result += "Id";
    result += borderBetweenTitleAndValue;
    result += QString::number(Id());
    result += border;

    result += "Name";
    result += borderBetweenTitleAndValue;
    result += QString::fromStdString(Name());
    result += border;

    result += "Performance";
    result += borderBetweenTitleAndValue;
    result += QString::number(Performance());
    result += border;

    result += "Clock";
    result += borderBetweenTitleAndValue;
    result += QString::number(Clock());
    result += border;

    result += "LogicCores";
    result += borderBetweenTitleAndValue;
    result += QString::number(LogicCores());
    result += border;

    result += "PhysCores";
    result += borderBetweenTitleAndValue;
    result += QString::number(PhysCores());
    return result;
}

ProcessorDB::operator QString() const { return  DebugDescription(); }

ProcessorDB::operator std::string() const { return  DebugDescription().toStdString(); }
