cmake_minimum_required(VERSION 3.20)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(print_ip VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)

add_executable(print_ip main.cpp sfinae_templ.h)

set_target_properties(
        print_ip PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)