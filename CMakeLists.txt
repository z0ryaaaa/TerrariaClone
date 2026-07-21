cmake_minimum_required(VERSION 3.15)
project(TerrariaClone CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependencies ---------------------------------------------------------
# raylib is already installed system-wide (matches your old Makefile's -lraylib),
# so we just ask CMake to find it instead of building it from source.
find_package(raylib REQUIRED)

# Example of adding a second library later (dear imgui), commented out for now:
# include(FetchContent)
# FetchContent_Declare(
#     imgui
#     GIT_REPOSITORY https://github.com/ocornut/imgui.git
#     GIT_TAG        v1.91.0
# )
# FetchContent_MakeAvailable(imgui)

# --- Source files ----------------------------------------------------------
# List every .cpp file here. Add new lines as your project grows.
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# --- Include directories ----------------------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    # add more include paths here, e.g. ${imgui_SOURCE_DIR}
)

# --- Link libraries ----------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    # add more libraries here, e.g. imgui
)

# raylib's own CMake config usually pulls in m/pthread/dl/rt/X11 automatically.
# If linking fails with "undefined reference" errors on Linux, uncomment this:
# if(UNIX AND NOT APPLE)
#     target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
# endif()
