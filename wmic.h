#ifndef WMIC_H
#define WMIC_H

#include <QString>

namespace Wmic
{
    QString GetValue(QString command, QString paramName);
};

#endif // WMIC_H
