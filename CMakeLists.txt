cmake_minimum_required(VERSION 3.28)
project(booking)

set(CMAKE_CXX_STANDARD 17)

add_executable(booking main.cpp
        src/Airplane.cpp
        src/ConfigFileParser.cpp
        src/Ticket.cpp
        src/UserInputParser.cpp
        include/BookingCli.h
        src/BookingCli.cpp
        src/AirplanesManager.cpp
        include/TicketsManager.h
        src/TicketsManager.cpp)