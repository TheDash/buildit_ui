#ifndef MOUNT_POINT_MARKER
#define MOUNT_POINT_MARKER

#include <string>
#include <geometry_msgs/Pose.h>

class MountPointMarker
{
   public:
       MountPointMarker();
       ~MountPointMarker();

       // the link name is the link that the marker is relative to. 
       std::string link_name;
   
       // The marker name is the string that is shown on screen and a way to acces that specific marker.
       std::string marker_name;
       // The ID is the number after the marker name in the screen. 
       int marker_id;
       geometry_msgs::Pose pose;
       static int number_of_markers;
};

#endif
