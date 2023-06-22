
#ifndef COMPUTER_H
#define COMPUTER_H

#include "cpu.h"

class Computer {
public:
    Computer() = default;
    Computer(std::shared_ptr<IProcessor> cpu) : m_cpu(cpu) {}

    void setProcessor(std::shared_ptr<IProcessor> cpu) {
        m_cpu = cpu;
    }

    QString getComputerInfo() {
        return m_cpu != nullptr ? m_cpu->getProcessorInfo() : "No CPU in PC";
    }

private:
    std::shared_ptr<IProcessor> m_cpu;
};


#endif // COMPUTER_H
