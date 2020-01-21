cmake_minimum_required(VERSION 3.15)
project(Searching_Algorithm_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Searching_Algorithm_Server main.cpp ClientHandler.cpp ClientHandler.h MySerialServer.cpp MySerialServer.h MyParallelServer.cpp MyParallelServer.h MyTestClientHandler.cpp MyTestClientHandler.h server_side.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Searchable.cpp Searchable.h Searcher.cpp Searcher.h OA.cpp OA.h Matrix.cpp Matrix.h Cell.cpp Cell.h State.cpp State.h BFS.cpp BFS.h DFS.cpp DFS.h BestFS.cpp BestFS.h AStar.cpp AStar.h MyClientHandler.cpp MyClientHandler.h PriorityQueueState.cpp PriorityQueueState.h StateCompare.cpp StateCompare.h compar.cpp compar.h comparforset.cpp comparforset.h)