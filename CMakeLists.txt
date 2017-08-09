cmake_minimum_required(VERSION 2.8.11)
INCLUDE(FindPkgConfig)

project(agl-hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC ")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

include_directories(
  ${WEBWIDGETS_INCLUDE_DIRS}
)

QT5_add_resources(agl_hello_QRC )
add_executable(agl-hello main.cpp ${agl_hello_SRC} ${agl_hello_QRC})

target_link_libraries(agl-hello Qt5::Core Qt5::Widgets)

install (TARGETS agl-hello DESTINATION bin)

##########################################################################
# AGL binding
configure_file(config.xml.in config.xml)

add_custom_command(
	OUTPUT agl-hello.wgt
	DEPENDS agl-hello
	COMMAND rm -rf package
	COMMAND mkdir -p package/root
	COMMAND cp config.xml package/root/
	COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/icon.png package/root/icon.png
	COMMAND cp agl-hello package/root/agl-hello
	COMMAND wgtpkg-pack -f -o package/agl-hello.wgt package/root
)
add_custom_target(widget ALL DEPENDS agl-hello.wgt)

