#define MOUNT_POINT_H
#ifndef MOUNT_POINT_H

#include <string>
#include <vector>
#include <buildit_ui/objects/mount_point_marker.h>


// A mount point has multiple markers associated with it, and is only created with a parent link name.
// Right now it only supports a 1 depth association of a list of markers (which are subclassed from the parent marker)
// the user has an option to change the marker name through other means.
class MountPoint
{
   public:
       MountPoint(std::string& parent_link);
       ~MountPoint();

        void addMarker();
        void getMarker(int index, MountPointMarker& marker);
        int getMarkerCount();

   private:
       std::string parent_link;
       std::vector<MountPointMarker> mount_point_markers;
};

#endif
