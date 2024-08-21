cmake_minimum_required(VERSION 3.25)
project(Backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpr REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)
find_package(SQLite3 REQUIRED)
find_library(SQLITE3_LIBRARY sqlite3 REQUIRED)

set(SOURCES
    src/main.cpp
    src/view/main_window.cpp

    src/db/sqlite.cpp
    src/shared/global.cpp

    src/view/login.cpp
    src/model/login.cpp
    src/controller/login.cpp

    src/view/header_bar.cpp
    src/model/header_bar.cpp
    src/controller/header_bar.cpp

    src/view/menu/menu.cpp
    src/controller/menu/menu.cpp

    src/view/menu/pago.cpp
    src/controller/menu/pago.cpp


    #=============================
    src/view/component/nip.cpp
    src/view/component/tres_filas.cpp

    src/view/menu/consultaEfectivo.cpp
    src/controller/menu/consultaEfectivo.cpp    

)

include_directories(include
                    include/view/
                    include/model/
                    include/controller/
                    include/shared/
                    include/db/
                    include/view/menu
                    include/view/component
                    include/model/menu
                    include/controller/menu
                    )



add_executable(Maxicajero ${SOURCES})

target_link_libraries(Maxicajero PRIVATE 
    cpr::cpr 
    nlohmann_json::nlohmann_json 
    SQLite::SQLite3
    ${LIBNOTIFY_LIBRARIES} 
    ${GTKMM_LIBRARIES}
)

target_include_directories(Maxicajero PRIVATE ${GTKMM_INCLUDE_DIRS})
