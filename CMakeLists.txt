cmake_minimum_required(VERSION 3.25)
project(Backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
include_directories(
    find_package(cpr REQUIRED)
)
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
                    include/controller/
)


add_executable(Maxicajero ${SOURCES})

target_link_libraries(Maxicajero PRIVATE 
cpr::cpr 
nlohmann_json::nlohmann_json 
${LIBNOTIFY_LIBRARIES} 
${GTKMM_LIBRARIES})

target_include_directories(Maxicajero PRIVATE ${GTKMM_INCLUDE_DIRS} )