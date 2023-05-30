#include "CommStubImpl.hpp"

using namespace std;

using namespace v1::commonapi::demo;
CommStubImpl::CommStubImpl() {
}

CommStubImpl::~CommStubImpl() {
    }

 int32_t iNum = 0;
 void CommStubImpl::sendMessage(const  shared_ptr < CommonAPI :: ClientId > _client, 
    std :: string _name, sendMessageReply_t _reply)
{
    std::cout << "[COMM::sendMessage] _name:" << _name << std::endl;
    
    v1::commonapi::demo::Comm::stdErrorTypeEnum error;
    error = v1::commonapi::demo::Comm::stdErrorTypeEnum::NO_FAULT;
     
     std::string message = "out message";
    _reply(error, message);

    fireMyStatusEvent(iNum++);
    return;
}