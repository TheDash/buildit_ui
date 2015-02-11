#define MOUNT_POINTS_H
#ifndef MOUNT_POINTS_H

#include <map>
#include <buildit_ui/objects/mount_point.h>
#include <string>

class MountPoints
{
    public:
        MountPoints();
        ~MountPoints();
        std::map<std::string, MountPoint> mount_points;
        inline void add_mount_point(std::string link_location, MountPoint& p) { mount_points.insert(std::pair<std::string, MountPoint>(link_location, p)); }
        //inline void has_mount_point(MountPoint & p)

};

#endif
