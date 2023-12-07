cmake_minimum_required(VERSION 3.24)
project(labwork_10_scanerist)

set(CMAKE_CXX_STANDARD 17)



set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})



add_executable(labwork_10_scanerist
        main.cpp weatherdata.h weatherdata.cpp weather_controller.h weather_controller.cpp coordinates_data.h  coordinates_data.cpp wearherView.cpp wearherView.h Run.cpp Run.h Run.h Run.cpp)



include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(labwork_10_scanerist PRIVATE cpr::cpr)


FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(labwork_10_scanerist PRIVATE nlohmann_json::nlohmann_json)


set(CMAKE_EXE_LINKER_FLAGS "-static")

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(ftxui GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui GIT_TAG v4.0.0)

FetchContent_MakeAvailable(ftxui)

target_link_libraries(${PROJECT_NAME} PRIVATE ftxui::screen PRIVATE ftxui::dom PRIVATE ftxui::component)



