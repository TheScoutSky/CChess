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

add_executable(${PROJECT_NAME}
        src/main.cpp

        src/app/ChessGame.cpp
        src/app/ChessGame.h

        src/chess/board/ChessBoard.cpp
        src/chess/board/ChessBoard.h
        src/chess/board/ChessField.cpp
        src/chess/board/ChessField.h

        src/chess/model/ChessGameSettings.cpp
        src/chess/model/ChessGameSettings.h
        src/chess/model/ChessTeam.cpp
        src/chess/model/ChessTeam.h

        src/chess/moves/ChessMove.cpp
        src/chess/moves/ChessMove.h
        src/chess/moves/ChessMoveSet.cpp
        src/chess/moves/ChessMoveSet.h

        src/chess/pieces/ChessPiece.cpp
        src/chess/pieces/ChessPiece.h
        src/chess/pieces/Pawn.cpp
        src/chess/pieces/Pawn.h

        src/ui/CButton.cpp
        src/ui/CButton.h
        src/ui/GameScreen.cpp
        src/ui/GameScreen.h
        src/ui/screens/TitleScreen.cpp
        src/ui/screens/TitleScreen.h
        src/ui/screens/PlayingScreen.cpp
        src/ui/screens/PlayingScreen.h
        src/chess/pieces/Rook.cpp
        src/chess/pieces/Rook.h
        src/chess/pieces/Knight.cpp
        src/chess/pieces/Knight.h
)
target_include_directories(${PROJECT_NAME} PRIVATE src)
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
