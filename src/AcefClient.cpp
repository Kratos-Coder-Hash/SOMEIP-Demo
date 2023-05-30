#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/demo/CommProxy.hpp>

using namespace v1::commonapi::demo;

void Test_SubScribe_Event_CB(const int32_t& status ) {
    std::cout << "Test_SubScribe_Event_CB :" << status << std::endl;
}

int i = 0;
void Test_Method(std::shared_ptr<CommProxy<>> proxy) {
    while (true) {

        CommonAPI::CallStatus internalCallStatus;
        std::string strInput = "Test_Method";
        //strInput += itoa(i);
        std::string strRet;
        Comm::stdErrorTypeEnum error;
        CommonAPI::CallInfo info;
        info.timeout_ = 100;
        info.sender_ = 1111;
        proxy->sendMessage(strInput, internalCallStatus, error, strRet, &info);
        std::cout << "input:" << strInput << " internalCallStatus:"<< (int)internalCallStatus 
         <<  " error:" << (int)error << " output:" << strRet << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
int main() {
    CommonAPI::Runtime::setProperty("LogContext", "AcefClient");
    CommonAPI::Runtime::setProperty("LogApplication", "AcefClient");
    CommonAPI::Runtime::setProperty("LibraryBase", "AcefClient");

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    const std::string &domain = "local";
    const std::string &instance = "commonapi.demo.Comm";
    const std::string connectionIdClient = "AcefClient";

    std::shared_ptr<CommProxy<>> myProxy = runtime->buildProxy<CommProxy>(domain, instance, connectionIdClient);
    while (!myProxy->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    std::cout << "Proxy available." << std::endl;

    std::thread  th(Test_Method, myProxy);
    myProxy->getMyStatusEvent().subscribe(Test_SubScribe_Event_CB);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}
