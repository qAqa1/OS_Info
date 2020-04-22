#include "processordb.h"

#include <QOperatingSystemVersion>
#include <QProcess>

namespace WmicParams
{
// wmic cpu get - все параметры

    const QString name = "name",
//                  DeviceID = "DeviceID",
                  NumberOfCores = "NumberOfCores",
                  NumberOfLogicalProcessors = "NumberOfLogicalProcessors",
                  MaxClockSpeed = "MaxClockSpeed";
}

ProcessorDB::ProcessorDB()
{
    QString OSName = QSysInfo::kernelType();

    QOperatingSystemVersion inf = QOperatingSystemVersion::current();

    QOperatingSystemVersion::OSType OSType = inf.type();

    if (OSType == QOperatingSystemVersion::OSType::Windows)
    {
        p_id = 0;
        p_name = GetWindowsCPUParam(WmicParams::name).toStdString();
        p_clock = GetWindowsCPUParam(WmicParams::MaxClockSpeed).toDouble();
        p_logicCores = GetWindowsCPUParam(WmicParams::NumberOfLogicalProcessors).toInt();
        p_physCores = GetWindowsCPUParam(WmicParams::NumberOfCores).toInt();
        p_perf = CalcGflops(p_clock, p_physCores);
    }
}

QString ProcessorDB::ClearStr(QString sourceStr, QStringList trash)
{
    for (QString t : trash)
    {
        sourceStr = sourceStr.replace(t, "");
    }

    return sourceStr;
}

QString ProcessorDB::GetWindowsCPUParam(QString paramName)
{
    QString cpucorp = "wmic cpu get " + paramName;
    QProcess windowscpu;
    windowscpu.start(cpucorp);
    windowscpu.waitForFinished();
    QString windowsOutput = windowscpu.readAllStandardOutput();
    QString reslut = ClearStr(windowsOutput, {paramName,"\r", "\n", " "});
    return reslut;
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
