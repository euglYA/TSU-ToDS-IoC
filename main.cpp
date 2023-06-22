#include <iostream>
#include "IOC_Contaner.h"
#include "computer.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    IOCContainer injector;

    injector.RegisterInstance<IProcessor, IntelProcessor>();
    auto instance = injector.GetObject<IProcessor>();
    instance->setProcessor(4.2, ProcessorType::x64, "i5 12400");
    Computer intelPC(instance);
    std::cout << (intelPC.getComputerInfo()).toStdString();

    injector.RegisterInstance<IProcessor, AMDProcessor>();
    instance = injector.GetObject<IProcessor>();
    instance->setProcessor(3.7, ProcessorType::x64, "Ryzen 5 3550H");
    Computer amdPC(instance);
    std::cout << (amdPC.getComputerInfo()).toStdString();

    return a.exec();
}
