cmake_minimum_required(VERSION 2.8.3)
project(buildit_ui)

find_package(catkin REQUIRED COMPONENTS std_msgs moveit_ros_visualization rviz roscpp pluginlib visualization_marker_tutorials buildit_msgs )

catkin_package(
   LIBRARIES buildit_objects
   INCLUDE_DIRS include 
)

include_directories(${catkin_INCLUDE_DIRS} include)
link_directories(${catkin_LIBRARY_DIRS})

find_package(Qt4 COMPONENTS QtCore QtGui QtWebKit QtOpenGL QtUiTools REQUIRED)
include(${QT_USE_FILE})

add_definitions(-DQT_NO_KEYWORDS)

qt4_wrap_cpp(UI_FILES
    include/${PROJECT_NAME}/ui/start_screen.h
    include/${PROJECT_NAME}/ui/myviz.h
    include/${PROJECT_NAME}/ui/start_screen_tab_widget.h
    include/${PROJECT_NAME}/ui/mount_points_tab_widget.h
)

qt4_wrap_cpp(OBJECT_FILES
   include/${PROJECT_NAME}/objects/buildit_config.h
   include/${PROJECT_NAME}/objects/mount_point.h
   include/${PROJECT_NAME}/objects/mount_points.h
   include/${PROJECT_NAME}/objects/mount_point_marker.h
)

set(OBJECT_SRC_FILES
   src/objects/buildit_config.cpp
   src/objects/mount_point.cpp
   src/objects/mount_points.cpp
   src/objects/mount_point_marker.cpp
   ${OBJECT_FILES}
)

set(UI_SRC_FILES
    src/main.cpp
    src/ui/start_screen.cpp
    src/ui/myviz.cpp
    src/ui/start_screen_tab_widget.cpp
    src/ui/mount_points_tab_widget.cpp
    ${UI_FILES}
)

add_library(buildit_objects ${OBJECT_SRC_FILES})
target_link_libraries(buildit_objects ${catkin_LIBRARIES} yaml-cpp ${QT_LIBRARIES})
add_dependencies(buildit_objects buildit_msgs_generate_messages_cpp buildit_msgs_gencpp ${catkin_EXPORTED_TARGETS})

add_executable(${PROJECT_NAME} ${UI_SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${catkin_LIBRARIES} buildit_objects default_plugin yaml-cpp)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS} )

install(TARGETS
	${PROJECT_NAME} buildit_objects
	ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/ DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY launch/  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
