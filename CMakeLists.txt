cmake_minimum_required(VERSION 3.10.0)
project(Super_Cerveja VERSION 0.1.0 LANGUAGES CXX)

add_executable(Super_Cerveja main.cpp cards.cpp deck.cpp jogador.cpp jogo.cpp)
set_property(TARGET Super_Cerveja PROPERTY CXX_STANDARD 17)
target_compile_options(Super_Cerveja PRIVATE -std=c++17 -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wnull-dereference)
