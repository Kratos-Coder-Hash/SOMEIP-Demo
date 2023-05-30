
#include <iostream>
#include <thread>

#include <CommonAPI/CommonAPI.hpp>
#include "CommStubImpl.hpp"

using namespace v1::commonapi::demo;

int main() {
    CommonAPI::Runtime::setProperty("LogContext", "AcefService");
    CommonAPI::Runtime::setProperty("LogApplication", "AcefService");
    CommonAPI::Runtime::setProperty("LibraryBase", "AcefService");
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    const static std::string managerInstanceName = "commonapi.demo.Comm";
    const std::string connectionIdService = "AcefService";

    std::shared_ptr<CommStubImpl> myService = std::make_shared < CommStubImpl > ();

    bool successfullyRegistered = runtime->registerService("local", managerInstanceName, myService, connectionIdService);

    while (!successfullyRegistered) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtime->registerService("local", managerInstanceName, myService, connectionIdService);
    }

    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
        
}
