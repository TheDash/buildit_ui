#ifndef MOUNT_POINT_H
#define MOUNT_POINT_H

#include <buildit_ui/mount_point_marker.h>
#include <string>
#include <vector>

class MountPoint
{
   public:
       MountPoint();
       ~MountPoint();
       std::string link_location;
       std::vector<MountPointMarker> mount_point_markers;
};

#endif








