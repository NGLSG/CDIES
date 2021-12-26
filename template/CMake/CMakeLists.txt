cmake_minimum_required(VERSION 3.10) 

project(main)

set(CMAKE_CXX_STANDARD 11)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/Library)

set(INC_DIR ${CMAKE_SOURCE_DIR}/Include)

#编译选项
if(CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-pthread -w -time -O3 -g )
  message(STATUS "optional:-g -pthread -w -time -O3")   
endif(CMAKE_COMPILER_IS_GNUCXX)

aux_source_directory(${PROJECT_SOURCE_DIR} filename)
#静态 动态库生成
aux_source_directory(${LIB_DIR} library)

aux_source_directory(${INC_DIR} include)

add_library(MySharedLib SHARED ${library})#请自行设置链接库名 动态库

add_library(MyStaticLib STATIC ${library})#请自行设置链接库名 静态库

target_include_directories(MyStaticLib PUBLIC ${INC_DUR})

target_include_directories(MySharedLib PRIVATE ${INC_DIR})

#set_target_properties(MySharedLib PROPERTIES PUBLIC_HEADER ${INC_DIR}/lib.h)#需要时用

#生成可执行文件
add_executable(target ${filename})#设置生成文件
target_link_libraries(target MySharedLib)
target_include_directories(target PRIVATE ${INC_DIR})

#install 模块

install(TARGETS target MySharedLib MyStaticLib
  EXPORT test
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include

  )
