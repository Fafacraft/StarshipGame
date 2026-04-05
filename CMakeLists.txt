cmake_minimum_required(VERSION 3.16)
project(StarshipGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# -------------------------
# SDL2
# -------------------------
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.0
)

FetchContent_MakeAvailable(SDL2)

# -------------------------
# EnTT (header-only)
# -------------------------
FetchContent_Declare(
    entt
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.13.0
)

FetchContent_MakeAvailable(entt)

# -------------------------
# Your executable
# -------------------------
add_executable(StarshipGame
    src/main.cpp
)

# Link SDL2
target_link_libraries(StarshipGame PRIVATE SDL2::SDL2)

# Include EnTT
target_include_directories(StarshipGame PRIVATE
    ${entt_SOURCE_DIR}/src
)

# Copy SDL2 DLLs to the output directory on Windows
add_custom_command(TARGET StarshipGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:StarshipGame>
)