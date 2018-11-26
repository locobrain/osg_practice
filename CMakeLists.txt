CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
project(osg)
include_directories($ENV{OSG_ROOT}/include $ENV{OSG_ROOT}/build/include)
link_directories($ENV{OSG_ROOT}/build/lib)
link_libraries(osgViewerd osgd osgGAd)

add_subdirectory(axis)