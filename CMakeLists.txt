cmake_minimum_required(VERSION 3.15)
project(Searching_Algorithm_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Searching_Algorithm_Server main.cpp ClientHandler.cpp ClientHandler.h MySerialServer.cpp MySerialServer.h MyParallelServer.cpp MyParallelServer.h MyTestClientHandler.cpp MyTestClientHandler.h server_side.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Searchable.cpp Searchable.h Searcher.cpp Searcher.h Filecashmanager.cpp Filecashmanager.h)