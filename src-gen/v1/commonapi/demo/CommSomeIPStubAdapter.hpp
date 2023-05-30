/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_DEMO_COMM_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_DEMO_COMM_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/demo/CommStub.hpp>
#include <v1/commonapi/demo/CommSomeIPDeployment.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {
namespace demo {

template <typename _Stub = ::v1::commonapi::demo::CommStub, typename... _Stubs>
class CommSomeIPStubAdapterInternal
    : public virtual CommStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< CommSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> CommSomeIPStubAdapterHelper;

    ~CommSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        CommSomeIPStubAdapterHelper::deinit();
    }

    void fireXAttributeChanged(const int32_t &_value);
    
    void fireMyStatusEvent(const int32_t &_myCurrentValue);

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::demo::CommStub,
        CommonAPI::Version
    > getCommInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::demo::CommStub,
        int32_t,
        CommonAPI::SomeIP::IntegerDeployment<int32_t>
    > getXAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::demo::CommStub,
        int32_t,
        CommonAPI::SomeIP::IntegerDeployment<int32_t>
    > setXAttributeStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::demo::CommStub,
        std::tuple< std::string>,
        std::tuple< Comm::stdErrorTypeEnum, std::string>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>,
        std::tuple< ::v1::commonapi::demo::Comm_::stdErrorTypeEnumDeployment_t, CommonAPI::SomeIP::StringDeployment>
    > sendMessageStubDispatcher;
    
    CommSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        CommSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< CommStub>(_stub)),
        getCommInterfaceVersionStubDispatcher(&CommStub::lockInterfaceVersionAttribute, &CommStub::getInterfaceVersion, false, true),
        getXAttributeStubDispatcher(
            &::v1::commonapi::demo::CommStub::lockXAttribute,
            &::v1::commonapi::demo::CommStub::getXAttribute,
            false,
            _stub->hasElement(1)),
        setXAttributeStubDispatcher(
            &::v1::commonapi::demo::CommStub::lockXAttribute,
            &::v1::commonapi::demo::CommStub::getXAttribute,
            &CommStubRemoteEvent::onRemoteSetXAttribute,
            &CommStubRemoteEvent::onRemoteXAttributeChanged,
            &CommStubAdapter::fireXAttributeChanged,
            false,
            _stub->hasElement(1))
        ,
        sendMessageStubDispatcher(
            &CommStub::sendMessage,
            false,
            _stub->hasElement(0),
            std::make_tuple(&::v1::commonapi::demo::Comm_::sendMessage_nameDeployment),
            std::make_tuple(static_cast< ::v1::commonapi::demo::Comm_::stdErrorTypeEnumDeployment_t * >(nullptr), static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)))
        
    {
        CommSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbb8) }, &getXAttributeStubDispatcher );
        CommSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbb9) }, &setXAttributeStubDispatcher );
        CommSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7530) }, &sendMessageStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(0x80f4));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80f4), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_EVENT, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
        }
        if (_stub->hasElement(1)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x80f2)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80f2), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireXAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::demo::CommStub>(_stub)->getXAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void CommSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireXAttributeChanged(const int32_t &_value) {
    CommonAPI::Deployable< int32_t, CommonAPI::SomeIP::IntegerDeployment<int32_t>> deployedValue(_value, static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                int32_t,
                CommonAPI::SomeIP::IntegerDeployment<int32_t>
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x80f2),
        false,
        deployedValue
    );
}

template <typename _Stub, typename... _Stubs>
void CommSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireMyStatusEvent(const int32_t &_myCurrentValue) {
    CommonAPI::Deployable< int32_t, CommonAPI::SomeIP::IntegerDeployment<int32_t>> deployed_myCurrentValue(_myCurrentValue, static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<CommonAPI::SomeIP::SerializableArguments<  CommonAPI::Deployable< int32_t, CommonAPI::SomeIP::IntegerDeployment<int32_t> > 
    >>
        ::sendEvent(
            *this,
            CommonAPI::SomeIP::event_id_t(0x80f4),
            false,
             deployed_myCurrentValue 
    );
}


template <typename _Stub, typename... _Stubs>
void CommSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void CommSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::demo::CommStub, typename... _Stubs>
class CommSomeIPStubAdapter
    : public CommSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    CommSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          CommSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace demo
} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_DEMO_Comm_SOMEIP_STUB_ADAPTER_HPP_
