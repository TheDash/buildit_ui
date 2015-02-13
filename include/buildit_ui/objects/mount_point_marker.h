#ifndef MOUNT_POINT_MARKER_H
#define MOUNT_POINT_MARKER_H

#include <string>
#include <geometry_msgs/Pose.h>

class MountPointMarker
{
   public:

       MountPointMarker(const std::string& parent_link, const std::string& marker_name);
       ~MountPointMarker();

       void getParentLink(std::string& parent_link);
       void getMeshFile(std::string& mesh_file);
       void getURDFBlock(std::string& urdf_block);
       int getMarkerID();
       void getMarkerName(std::string& marker_name);
       void getPose(geometry_msgs::Pose &pose);
       
       void setMarkerID(const int id);
       void setMarkerName(const std::string& marker_name);
       void setParentLink(const std::string& parent_link);
       void setPose(const geometry_msgs::Pose &pose);
       void setMeshFile(const std::string& mesh_file);
       void setUDFBlock(const std::string& urdf_block);
       void setSpawned(const bool& spawned);

       void spawnMarker();
       void updateMarkerPose(const geometry_msgs::Pose &pose);
       void changeMarkerMesh(const std::string& mesh_file);
       void removeMarker();
       bool isSpawned();

       
   private:

       std::string parent_link;
       std::string marker_name;
       int marker_id;

       std::string mesh_file;
       std::string urdfxacro_file;
       std::string urdf_block;

       geometry_msgs::Pose pose;

       bool is_spawned;
};

#endif
// What do I need from the mount_points declaration in the YAML? Really just need a list of all of the mount_point_markers.

// Each mount_point_marker can have its parent link, its own name, and its pose. 
// Then there needs to be a structure that knows about all of the mount_point_markers. I think the marker_server knows about them? what about adding 
