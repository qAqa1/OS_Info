#ifndef PROCESSORDB_H
#define PROCESSORDB_H

#include <iostream>
#include <QString>

// TODO: портировать на линукс

class ProcessorDB
{
   public:
    ProcessorDB(int id);
    ProcessorDB(int id, std::string name, double perf, double clock, int logicCores, int physCores);
    ProcessorDB(const ProcessorDB& cpy);

    int Id() const { return p_id; }
    std::string Name() const { return p_name; }
    double Performance() const { return p_perf; }
    double Clock() const { return p_clock; }
    double LogicCores() const { return p_logicCores; }
    double PhysCores() const { return p_physCores; }

   private:
    int p_id;
    std::string p_name;
    double p_perf;
    double p_clock;
    int p_logicCores;
    int p_physCores;

    QString ClearStr(QString sourceStr, QStringList trash);
    QString GetWindowsCPUParam(QString paramName);
    double CalcGflops(double maxClockSpeed, double coresCount);

    QString DebugDescription() const;
   public:
    operator QString() const;
    operator std::string() const;
};

#endif // PROCESSORDB_H
