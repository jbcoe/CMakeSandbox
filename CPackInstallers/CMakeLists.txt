cmake_minimum_required(VERSION 3.5)

set(HelloWorld_VERSION_MAJOR 0)
set(HelloWorld_VERSION_MINOR 1)
set(HelloWorld_VERSION_PATCH 0)

add_executable(HelloWorld hw.cpp)
add_executable(GoodbyeWorld gw.cpp)

install(TARGETS HelloWorld DESTINATION bin COMPONENT hi)
install(TARGETS GoodbyeWorld DESTINATION bin COMPONENT bye)

set(CPACK_PACKAGE_VENDOR "J.B.Coe")
set(CPACK_PACKAGE_VERSION_MAJOR ${HelloWorld_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${HelloWorld_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${HelloWorld_VERSION_PATCH})

set(CPACK_GENERATOR "ZIP")

set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

include(CPack)

