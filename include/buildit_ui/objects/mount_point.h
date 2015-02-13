#define MOUNT_POINT_H
#ifndef MOUNT_POINT_H

#include <string>
#include <vector>
#include <buildit_ui/objects/mount_point_marker.h>

class MountPoint
{
   public:
       MountPoint();
       ~MountPoint();
       std::string link_location;
       std::vector<MountPointMarker::MountPointMarker> mount_point_markers;
};

#endif
