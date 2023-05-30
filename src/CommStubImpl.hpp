#ifndef __COMM_HPP__
#define __COMM_HPP__

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/demo/CommStubDefault.hpp>

class CommStubImpl: public v1_0::commonapi::demo::CommStubDefault
{
public:
    CommStubImpl();
    virtual ~CommStubImpl();

    virtual void sendMessage(const std::shared_ptr<CommonAPI::ClientId> _client, 
        std::string _name, sendMessageReply_t _reply) ;
    
};
#endif
