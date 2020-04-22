#include "wmic.h"

#include <QProcess>
#include <QDebug>

QString ClearStr(QString sourceStr, QStringList trash)
{
    for (QString t : trash)
    {
        sourceStr = sourceStr.replace(t, "");
    }

    return sourceStr;
}

QString Wmic::GetValue(QString command, QString paramName)
{
    QString cpucorp = "wmic " + command + " " + paramName;
    QProcess windowscpu;
    windowscpu.start(cpucorp);
    windowscpu.waitForFinished();
    QString windowsOutput = QString::fromLocal8Bit(windowscpu.readAllStandardOutput());
    QString reslut = ClearStr(windowsOutput, {"\r", "\n", paramName});
    reslut = reslut.trimmed();
    return reslut;
}
