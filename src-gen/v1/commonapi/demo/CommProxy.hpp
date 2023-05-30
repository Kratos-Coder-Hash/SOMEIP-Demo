/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_DEMO_Comm_PROXY_HPP_
#define V1_COMMONAPI_DEMO_Comm_PROXY_HPP_

#include <v1/commonapi/demo/CommProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/AttributeExtension.hpp>
#include <CommonAPI/Factory.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {
namespace demo {

template <typename ... _AttributeExtensions>
class CommProxy
    : virtual public Comm,
      virtual public CommProxyBase,
      virtual public _AttributeExtensions... {
public:
    CommProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~CommProxy();

    typedef Comm InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Calls sendMessage with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void sendMessage(std::string _name, CommonAPI::CallStatus &_internalCallStatus, Comm::stdErrorTypeEnum &_error, std::string &_message, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls sendMessage with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> sendMessageAsync(const std::string &_name, SendMessageAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Returns the wrapper class that provides access to the attribute x.
     */
    virtual XAttribute& getXAttribute() {
        return delegate_->getXAttribute();
    }
    /**
     * Returns the wrapper class that provides access to the broadcast myStatus.
     */
    virtual MyStatusEvent& getMyStatusEvent() {
        return delegate_->getMyStatusEvent();
    }



 private:
    std::shared_ptr< CommProxyBase> delegate_;
};

typedef CommProxy<> CommProxyDefault;

namespace CommExtensions {
    template <template <typename > class _ExtensionType>
    class XAttributeExtension {
     public:
        typedef _ExtensionType< CommProxyBase::XAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension< CommProxyBase::XAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        XAttributeExtension(CommProxyBase& proxy): attributeExtension_(proxy.getXAttribute()) {
        }
    
        inline extension_type& getXAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

} // namespace CommExtensions

//
// CommProxy Implementation
//
template <typename ... _AttributeExtensions>
CommProxy<_AttributeExtensions...>::CommProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
      //  _AttributeExtensions(*(std::dynamic_pointer_cast< CommProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< CommProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
CommProxy<_AttributeExtensions...>::~CommProxy() {
}

template <typename ... _AttributeExtensions>
void CommProxy<_AttributeExtensions...>::sendMessage(std::string _name, CommonAPI::CallStatus &_internalCallStatus, Comm::stdErrorTypeEnum &_error, std::string &_message, const CommonAPI::CallInfo *_info) {
    delegate_->sendMessage(_name, _internalCallStatus, _error, _message, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> CommProxy<_AttributeExtensions...>::sendMessageAsync(const std::string &_name, SendMessageAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->sendMessageAsync(_name, _callback, _info);
}

template <typename ... _AttributeExtensions>
const CommonAPI::Address &CommProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool CommProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool CommProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& CommProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& CommProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> CommProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace demo
} // namespace commonapi
} // namespace v1

namespace CommonAPI {
template<template<typename > class _AttributeExtension>
struct DefaultAttributeProxyHelper< ::v1::commonapi::demo::CommProxy,
    _AttributeExtension> {
    typedef typename ::v1::commonapi::demo::CommProxy<
            ::v1::commonapi::demo::CommExtensions::XAttributeExtension<_AttributeExtension>
    > class_t;
};
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_DEMO_Comm_PROXY_HPP_