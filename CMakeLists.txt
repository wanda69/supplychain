cmake_minimum_required(VERSION 3.30)
project(supplychain C)

set(CMAKE_C_STANDARD 23)

add_executable(supplychain main.c)

# Specify the path to the curl include directory
set(CURL_INCLUDE_DIR "C:/Users/Lenovo/Downloads/curl-8.12.0_1-win64-mingw/curl-8.12.0_1-win64-mingw/include")

# Specify the path to the curl library directory
set(CURL_LIBRARY "C:/Users/Lenovo/Downloads/curl-8.12.0_1-win64-mingw/curl-8.12.0_1-win64-mingw/lib/libcurl.dll.a")

# Now try to find CURL
find_package(CURL REQUIRED)

# Include the curl headers in your target
target_include_directories(supplychain PRIVATE ${CURL_INCLUDE_DIR})

# Link the curl library to your target
target_link_libraries(supplychain PRIVATE ${CURL_LIBRARY})
