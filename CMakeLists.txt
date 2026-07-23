cmake_minimum_required(VERSION 3.15)
project(TerrariaClone CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependencies ---------------------------------------------------------
# raylib is already installed system-wide (matches your old Makefile's -lraylib),
# so we just ask CMake to find it instead of building it from source.
find_package(raylib REQUIRED)

# Dear ImGui (raw source, no CMakeLists.txt of its own — we add its .cpp files by hand)
include(FetchContent)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        docking
)
FetchContent_MakeAvailable(imgui)

# rlImGui: the raylib <-> ImGui backend/glue (also raw source)
FetchContent_Declare(
    rlimgui
    GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(rlimgui)

# --- Source files ----------------------------------------------------------
# List every .cpp file here. Add new lines as your project grows.
set(SOURCES
    main.cpp
    # ImGui core source files (it ships as loose .cpp, not a prebuilt lib)
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    # rlImGui glue code
    ${rlimgui_SOURCE_DIR}/rlImGui.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# --- Include directories ----------------------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${imgui_SOURCE_DIR}
    ${rlimgui_SOURCE_DIR}
)

# --- Link libraries ----------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    # add more libraries here as needed
)

# raylib's own CMake config usually pulls in m/pthread/dl/rt/X11 automatically.
# If linking fails with "undefined reference" errors on Linux, uncomment this:
# if(UNIX AND NOT APPLE)
#     target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
# endif()
