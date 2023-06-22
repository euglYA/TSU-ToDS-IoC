
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QString>

enum ProcessorType {
    x86,
    x64
};

class IProcessor {
public:
    virtual ~IProcessor() {};
    virtual void setProcessor(double speed, ProcessorType type, QString version) = 0;
    virtual QString getProcessorInfo() = 0;
};

class IntelProcessor : public IProcessor {
public:
    ~IntelProcessor() {};

    void setProcessor(double speed, ProcessorType type, QString version) {
        m_speed = speed;
        m_type = type;
        m_version = version;
    }

    QString getProcessorType() const {
        return (m_type == ProcessorType::x64 ? "x64" : "x86");
    }

    QString getProcessorInfo() {
        return "Intel " + getProcessorType() + " | model: " + m_version + " | speed: " + QString::number(m_speed) + " GHz \n";
    }

private:
    double m_speed;
    ProcessorType m_type;
    QString m_version;
};

class AMDProcessor : public IProcessor {
public:
    ~AMDProcessor() {};

    void setProcessor(double speed, ProcessorType type, QString version) {
        m_speed = speed;
        m_type = type;
        m_version = version;
    }

    QString getProcessorType() const {
        return (m_type == ProcessorType::x64 ? "x64" : "x86");
    }

    QString getProcessorInfo() {
        return "AMD " + getProcessorType() + " | model: " + m_version + " | speed: " + QString::number(m_speed) + " GHz \n";
    }

private:
    double m_speed;
    ProcessorType m_type;
    QString m_version;
};

#endif // PROCESSOR_H
