cmake_minimum_required(VERSION 3.15)

project(locate VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ICU REQUIRED COMPONENTS uc i18n)

add_executable(locate src/main.cpp src/Node/Node.cpp src/AhoCorasick/AhoCorasick.cpp src/util/unicode_util.cpp src/util/io_file/io_file.cpp)

target_link_libraries(locate
    PRIVATE
    ICU::uc
    ICU::i18n
)
