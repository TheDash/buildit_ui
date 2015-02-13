#ifndef MOUNT_POINT_MARKER_MAP
#define MOUNT_POINT_MARKER_MAP

#include <buildit_ui/objects/mount_point.h>
#include <map>
#include <string>

class MountPointMap
{
     public:
         void insert(MountPoint & mp);
         void getMountPoint(std::string& link, MountPoint& mp);
         bool hasMountPoint(std::string& link);

     private:
         // Key: parent link name of the mount point
         // Value: all of the markers that are attached to that parent link. (which can in turn be a mount_point)
         std::map<std::string, MountPoint> mount_point_map;

};












#endif
