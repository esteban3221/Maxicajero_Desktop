cmake_minimum_required(VERSION 3.25)
project(Backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpr REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)

set(SOURCES
    src/main.cpp
    src/view/login.cpp
    src/view/main_window.cpp
    src/view/header_bar.cpp
)

include_directories(include 
                    include/view/
                    include/model/
                    include/controller/)

add_executable(Maxicajero ${SOURCES})

target_link_libraries(Maxicajero PRIVATE 
    cpr::cpr 
    nlohmann_json::nlohmann_json 
    ${LIBNOTIFY_LIBRARIES} 
    ${GTKMM_LIBRARIES}
)

target_include_directories(Maxicajero PRIVATE ${GTKMM_INCLUDE_DIRS})
