cmake_minimum_required(VERSION 3.20)

project(CChess VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SDL2_USER_PREFIX "$ENV{HOME}/.local/sdl2")
if(EXISTS "${SDL2_USER_PREFIX}/lib/cmake/SDL2/SDL2Config.cmake")
    list(PREPEND CMAKE_PREFIX_PATH "${SDL2_USER_PREFIX}")
endif()

find_package(SDL2 2.0 CONFIG REQUIRED)
find_package(SDL2_ttf 2.0 CONFIG REQUIRED)
find_package(SDL2_image 2.0 CONFIG REQUIRED)
find_package(SDL2_mixer 2.0 CONFIG REQUIRED)
find_package(SDL2_net 2.0 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp
        src/core/ChessBoard.cpp
        src/core/ChessBoard.h
        src/core/ChessField.cpp
        src/core/ChessField.h
        src/core/interfaces/ChessPiece.cpp
        src/core/interfaces/ChessPiece.h
        src/ChessGame.cpp
        src/ChessGame.h
        src/core/ChessTeam.cpp
        src/core/ChessTeam.h
        src/core/logic/ChessMoveSet.cpp
        src/core/logic/ChessMoveSet.h
        src/core/logic/ChessMove.cpp
        src/core/logic/ChessMove.h
        src/ChessPieces/Pawn.cpp
        src/ChessPieces/Pawn.h
        src/core/data/ChessGameSettings.cpp
        src/core/data/ChessGameSettings.h
        src/core/ui/GameScreen.cpp
        src/core/ui/GameScreen.h
        src/core/ui/CButton.cpp
        src/core/ui/CButton.h
        src/core/ui/Screens/TitleScreen.cpp
        src/core/ui/Screens/TitleScreen.h
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_net::SDL2_net)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        BUILD_RPATH "${SDL2_USER_PREFIX}/lib"
    )
endif()
