cmake_minimum_required(VERSION 2.8)
project(Acef)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    src
    inc
)

# link_directories(
#     ../lib
# )

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
add_executable(AcefClient
        src/AcefClient.cpp
        src-gen/v1/commonapi/demo/CommSomeIPProxy.cpp
        src-gen/v1/commonapi/demo/CommSomeIPDeployment.cpp
)

target_link_libraries(AcefClient CommonAPI CommonAPI-SomeIP vsomeip3)
add_executable(AcefService
        src/AcefService.cpp
        src/CommStubImpl.cpp
        src-gen/v1/commonapi/demo/CommSomeIPStubAdapter.cpp
        src-gen/v1/commonapi/demo/CommSomeIPDeployment.cpp
)

target_link_libraries(AcefService CommonAPI CommonAPI-SomeIP vsomeip3)

add_library(CommShared SHARED  
        src/CommStubImpl.cpp
        src-gen/v1/commonapi/demo/CommSomeIPStubAdapter.cpp
        src-gen/v1/commonapi/demo/CommSomeIPDeployment.cpp
)

target_link_libraries(CommShared CommonAPI CommonAPI-SomeIP vsomeip3)
