#include <buildit_ros/mount_points_tab_widget.h>
#include <buildit_ros/start_screen.h>	
using namespace visualization_msgs;


MountPointsTabWidget::MountPointsTabWidget(QWidget * parent)
{

    QString text_string(QString::fromStdString("Load your robot's URDF and select the mount points by moving the links you wish to set as mount points to the right side box"));
    QLabel * text_block = new QLabel(text_string, this);
    text_block->setGeometry(QRect(-25, 0, 900, 30));
    text_block->setAlignment(Qt::AlignCenter);
 
    // Advertise orientation service
    this->or_srv = this->nh.advertiseService("set_marker_orientation_editor", &MountPointsTabWidget::set_marker_orientation_editor, this);
    ROS_INFO("Ready to orientate markers.");

    // Advertise position service
    this->pos_srv = this->nh.advertiseService("set_marker_position_editor", &MountPointsTabWidget::set_marker_position_editor, this);
    ROS_INFO("Ready to position markers.");

    // Advertise attach service

    // Advertise unattach service 

    this->clear_marker_server();
    this->load_robot_links();
    this->create_load_base_urdf_button();
    this->create_create_mount_points_button();
    this->create_mount_points_table_widget();
    this->create_save_model_button();

     if (!this->links.empty())
    {
	ROS_INFO("Populating links table!");
        this->populate_links_table();
    }
    this->create_selected_mount_points_table_widget();
    this->create_mount_button();
    this->create_unmount_button();
    this->create_hide_mount_points_button();
    this->create_marker_orientation_editor();
    this->create_marker_position_editor();
    this->buildit_config = new BuilditConfig();
}


MountPointsTabWidget::~MountPointsTabWidget()
{

}


void MountPointsTabWidget::save_model_button_clicked()
{
    // Get the output resultant file from save(). Then dialog editor to put it in place
    //this->buildit_config->save();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Model"), "", tr("Mount point config files (*.yaml);;All Files (*)"));

   if (fileName.isEmpty())
   {
       ROS_WARN("%s is not opening.", fileName.toStdString().c_str());
       return;
   }
   else 
   {
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
      {
             QMessageBox::information(this, tr("Unable to open file"),
             file.errorString());
             return;
      }

         QTextStream out(&file);
         std::string contents;
         buildit_config->save(contents);
         out << contents.c_str();
         file.close();

    }
}

void MountPointsTabWidget::create_save_model_button()
{
      save_model_button = new QPushButton(QString(QString::fromStdString("Save Model")), this);
      save_model_button->setGeometry(QRect(700, 85, 120, 50));
      save_model_button->setVisible(true);
      connect(this->save_model_button, SIGNAL(clicked()), this, SLOT(save_model_button_clicked()));
}


void MountPointsTabWidget::clear_marker_server()
{
   ROS_INFO("Clearing marker server");
    ros::ServiceClient clear_markers = this->nh.serviceClient<buildit_msgs::InteractiveMountPoint>("clear_all_markers");
   buildit_msgs::InteractiveMountPoint mp_msg;

   if (clear_markers.call(mp_msg))
   {
      ROS_INFO("Markers erased from server");
   } 
   else 
   {
      ROS_INFO("Failed to erase markers on server.");
   }
   
}

void MountPointsTabWidget::set_position_button_clicked()
{
   // on click parse what's inside the text box.
   this->xpos = pos_x_tb->text().toDouble();
   this->ypos = pos_y_tb->text().toDouble();
   this->zpos = pos_z_tb->text().toDouble();

   ros::ServiceClient remove_marker = this->nh.serviceClient<buildit_msgs::UpdateInteractiveMountPoint>("update_mount_point_marker");
   buildit_msgs::UpdateInteractiveMountPoint mp_msg;
   mp_msg.request.marker_name = edited_marker.marker_name;
   geometry_msgs::Pose p;
   p.position.x = this->xpos;
   p.position.y = this->ypos;
   p.position.z = this->zpos;
   mp_msg.request.new_pose = p; 

   if (remove_marker.call(mp_msg))
   {
      ROS_INFO("Updating marker on server %s", edited_marker.marker_name.c_str());
   } 
   else 
   {
      ROS_INFO("Failed to update marker on server.");
   }
   
}

void MountPointsTabWidget::set_orientation_button_clicked()
{
      // on click parse what's inside the text box.
   this->orr = or_r_tb->text().toDouble();
   this->orp = or_p_tb->text().toDouble();
   this->ory = or_y_tb->text().toDouble();

   ros::ServiceClient remove_marker = this->nh.serviceClient<buildit_msgs::UpdateInteractiveMountPoint>("update_mount_point_marker");
   buildit_msgs::UpdateInteractiveMountPoint mp_msg;
   mp_msg.request.marker_name = edited_marker.marker_name;
   geometry_msgs::Pose p;
   
   p.orientation.w = 1;
   p.orientation.x = this->orr;
   p.orientation.y = this->orp;
   p.orientation.z = this->ory;
   mp_msg.request.new_pose = p; 

   if (remove_marker.call(mp_msg))
   {
      ROS_INFO("Updating marker on server %s", edited_marker.marker_name.c_str());
   } 
   else 
   {
      ROS_INFO("Failed to update marker on server.");
   }

}

void MountPointsTabWidget::create_marker_position_editor()
{
   position_editor = new QWidget();
   position_editor->setWindowTitle("Mount point editor");
   position_editor->setGeometry(500, 500, 400, 200);

   QGridLayout * layout = new QGridLayout(position_editor);

   set_position_button = new QPushButton("Set Position");

   pos_x_tb = new QLineEdit(position_editor);
   pos_x_tb->setValidator(new QDoubleValidator(-100, 100, 3, position_editor));

   pos_y_tb = new QLineEdit(position_editor);
   pos_y_tb->setValidator(new QDoubleValidator(-100, 100, 3, position_editor));

   pos_z_tb = new QLineEdit(position_editor);
   pos_z_tb->setValidator(new QDoubleValidator(-100, 100, 3, position_editor));

   QLabel * x = new QLabel("x:");
   QLabel * y = new QLabel("y:");
   QLabel * z = new QLabel("z:");

   // Add widget to grid. ROW then COL.
   layout->addWidget(x, 0, 0);
   layout->addWidget(y, 1, 0);
   layout->addWidget(z, 2, 0);

   layout->addWidget(pos_x_tb, 0, 1);
   layout->addWidget(pos_y_tb, 1, 1);
   layout->addWidget(pos_z_tb, 2, 1);
   // Position the editors and labels

   layout->addWidget(set_position_button, 3, 1);

   // Forogt to connect..
   connect(this->set_position_button, SIGNAL(clicked()), this, SLOT(set_position_button_clicked()));


}

void MountPointsTabWidget::create_marker_orientation_editor()
{
   orientation_editor = new QWidget();
   orientation_editor->setWindowTitle("Mount point editor");
   orientation_editor->setGeometry(500, 500, 400, 200);

   QGridLayout * layout = new QGridLayout(orientation_editor);

   set_orientation_button = new QPushButton("Set Orientation");

   or_r_tb = new QLineEdit(orientation_editor);
   or_p_tb = new QLineEdit(orientation_editor);
   or_y_tb = new QLineEdit(orientation_editor);

   QLabel * r = new QLabel("r:");
   QLabel * p = new QLabel("p:");
   QLabel * y = new QLabel("y:");

   // Add widget to grid. ROW then COL.
   layout->addWidget(r, 0, 0);
   layout->addWidget(p, 1, 0);
   layout->addWidget(y, 2, 0);

   layout->addWidget(or_r_tb, 0, 1);
   layout->addWidget(or_p_tb, 1, 1);
   layout->addWidget(or_y_tb, 2, 1);
   // Position the editors and labels

   layout->addWidget(set_orientation_button, 3, 1);

   connect(this->set_orientation_button, SIGNAL(clicked()), this, SLOT(set_orientation_button_clicked()));
}

bool MountPointsTabWidget::set_marker_orientation_editor(buildit_msgs::SetOrientation::Request &req, buildit_msgs::SetOrientation::Response &res)
{
   orientation_editor->show();
   // Thread that waits until button is clicked from that editor, and then sets the values for the message and sends. 
   	
 
   return true;
}

bool MountPointsTabWidget::set_marker_position_editor(buildit_msgs::SetPosition::Request &req, buildit_msgs::SetPosition::Response &res)
{
   edited_marker = req.marker_info;
   position_editor->show();
   return true;
}

void MountPointsTabWidget::hide_mount_points_button_clicked()
{
       rviz::VisualizationManager * vm = StartScreen::visualizationDisplay->manager_;
       rviz::ToolManager * tm = vm->getToolManager();

   if (this->hide_mount_points_button->text().toStdString() == "Hide Markers")
   {
       // It is in hide marker state. Hide the markers, and set the button to be the show markers button
       this->hide_mount_points_button->setText(QString("Show Markers"));

       // As well, change the current tool to be just MoveCamera.
       rviz::Tool * t = tm->getTool(0);
       tm->setCurrentTool(t);
   } else
   {
       rviz::Tool * t = tm->getTool(1);
       tm->setCurrentTool(t);
       this->hide_mount_points_button->setText(QString("Hide Markers"));
   }

}

void MountPointsTabWidget::create_hide_mount_points_button()
{
    hide_mount_points_button = new QPushButton(QString(QString::fromStdString("Hide Markers")), this);
    hide_mount_points_button->setGeometry(QRect(150, 80, 180, 50));
    hide_mount_points_button->setVisible(true);

     connect(this->hide_mount_points_button, SIGNAL(clicked()), this, SLOT(hide_mount_points_button_clicked()));

}

void MountPointsTabWidget::create_mount_point_marker_from_yaml(std::string parent_name, std::string link_name, geometry_msgs::Pose pose)
{
   // Make service call
         ros::ServiceClient client = this->nh.serviceClient<buildit_msgs::InteractiveMountPoint>("load_mount_point_marker");
         buildit_msgs::InteractiveMountPoint mp_msg;
         mp_msg.request.link_name = link_name;
         mp_msg.request.parent_name = link_name;
         mp_msg.request.parent_position.x = pose.position.x;
         mp_msg.request.parent_position.y = pose.position.y;
         mp_msg.request.parent_position.z = pose.position.z;

         ROS_INFO("Requesting to create marker %s at X: %i Y: %i Z: %i", link_name.c_str(), pose.position.x, pose.position.y, pose.position.z);

         // Send the call 
         if (client.call(mp_msg))
         {

         }
         else
         {
            ROS_INFO("Failed to send markers to server (Marker name: %s)", link_name.c_str());
         }
}


void MountPointsTabWidget::create_mount_point_marker(std::string link_name, geometry_msgs::Pose pose)
{
         // Make service call
         ros::ServiceClient client = this->nh.serviceClient<buildit_msgs::InteractiveMountPoint>("spawn_mount_point_marker");
         buildit_msgs::InteractiveMountPoint mp_msg;
         mp_msg.request.link_name = link_name;
         mp_msg.request.parent_name = link_name;
         mp_msg.request.parent_position.x = pose.position.x;
         mp_msg.request.parent_position.y = pose.position.y;
         mp_msg.request.parent_position.z = pose.position.z;

         ROS_INFO("Requesting to create marker %s at X: %i Y: %i Z: %i", link_name.c_str(), pose.position.x, pose.position.y, pose.position.z);

         // Send the call 
         if (client.call(mp_msg))
         {

         }
         else
         {
            ROS_INFO("Failed to send markers to server (Marker name: %s)", link_name.c_str());
         }
}

// This will take all of the links selected in the selected table
// and create interactive markers at those link points
void MountPointsTabWidget::create_mount_points_button_clicked()
{
     // get selected mount points and create markers for them.
     for (int i = 0; i < this->selected_links_table->rowCount(); i++)
     {
         QTableWidgetItem* item = this->selected_links_table->item(i, 0);

         // get link name
         QString link = item->text();
         std::string link_name = link.toStdString();

         // get link position
        Ogre::Vector3 position = StartScreen::visualizationDisplay->robot_state_display_->robot_->getRobot().getLink(link_name)->getPosition();
        
         // Make service call
         ros::ServiceClient client = this->nh.serviceClient<buildit_msgs::InteractiveMountPoint>("spawn_mount_point_marker");
         buildit_msgs::InteractiveMountPoint mp_msg;
         mp_msg.request.link_name = link_name;
         mp_msg.request.parent_name = link_name;
         mp_msg.request.parent_position.x = position.x;
         mp_msg.request.parent_position.y = position.y;
         mp_msg.request.parent_position.z = position.z;

         // Send the call 
         if (client.call(mp_msg))
         {
            ROS_INFO("Attempting to create marker %s", mp_msg.request.link_name.c_str());
         }
         else
         {
            ROS_INFO("Failed to send markers to server");
         }
     }
}

void MountPointsTabWidget::create_create_mount_points_button()
{
    create_mount_points_button = new QPushButton(QString(QString::fromStdString("Create Mount Points")), this);
    create_mount_points_button->setGeometry(QRect(150, 30, 180, 50));
    create_mount_points_button->setVisible(true);

     connect(this->create_mount_points_button, SIGNAL(clicked()), this, SLOT(create_mount_points_button_clicked()));

}

void MountPointsTabWidget::populate_links_table_after_button()
{
  // Get the current tables
  int rowcount;
  rowcount = this->links_table->rowCount();
  for (int i =0; i < rowcount; i++)
  {
      this->links_table->removeRow(0);
  }

  // Now repopulate it.

  int newrowcount;
  newrowcount = this->links.size();

  for (int i = 0; i < newrowcount; i++)
  {
      this->links_table->insertRow(0);
      const robot_model::LinkModel* link_model = this->links.at(i);

      std::string link_name = link_model->getName(); 
      ROS_INFO("Found link: %s ... Loading ... ", link_name.c_str());
		
      // Create the table item. 
      QTableWidgetItem * entry = new QTableWidgetItem(QString(QString::fromStdString(link_name)));
      this->links_table->setItem(0, 0, entry);
  }

}

void MountPointsTabWidget::create_mount_point_markers()
{

     ROS_INFO("Doc name %s", buildit_config->getName().c_str());
     MountPoints mount_points = buildit_config->getMountPoints();
     std::map<std::string, MountPoint> point_map = mount_points.mount_points;

     typedef std::map<std::string, MountPoint>::iterator it_type;
     for (it_type iterator = point_map.begin(); iterator != point_map.end(); iterator++)
     { 
          geometry_msgs::Pose pose;
          MountPoint mp = iterator->second;
          for (int i = 0; i < mp.mount_point_markers.size(); i++)
          {
               MountPointMarker marker = mp.mount_point_markers.at(i);
               ROS_INFO("Creating marker %s", marker.marker_name.c_str());
               this->create_mount_point_marker_from_yaml(marker.link_name, marker.marker_name, marker.pose);
          }
     }
     
}

// Load the URDF and set the robot description to be whatever is inside the urdf 
void MountPointsTabWidget::load_urdf_base_button_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"), "/home/");
    
    if (fileNames.size() == 1)
    {
      ROS_INFO("Selected file.");
      QString qFileName = fileNames.value(0);
      std::string fileName = qFileName.toStdString();
      if (!fileName.empty())
      {
        // Check if .urdf or .xacro
        if (qFileName.endsWith(".urdf"))
        {
           std::ifstream ifs(fileName.c_str());
           std::string content( (std::istreambuf_iterator<char>(ifs) ),
                                (std::istreambuf_iterator<char>()    )  );

           ros::param::set("robot_description", content);
           ROS_INFO("Set the robot description to %s ", fileName.c_str());
        }
        else if (qFileName.endsWith(".xacro"))
        {
           // This chunk of code just gets the output of rosrun xacro xacro.py and sets it to robot_description
           std::string cmd("rosrun xacro xacro.py ");
           cmd += fileName;
           QProcess process;
           process.start(cmd.c_str());
           process.waitForReadyRead();
           process.waitForFinished();
           QString output(process.readAllStandardOutput());
           std::string robot_desc = output.toStdString();
           ros::param::set("robot_description", robot_desc);
           ROS_INFO("Set the robot description to %s", fileName.c_str());
        }
        else if (qFileName.endsWith(".yaml"))
        {
           buildit_config->load(fileName);
           buildit_config->load_robot_description();
           ROS_INFO("Loading model %s", buildit_config->getModelPath().c_str());
           // Spawn markers
           this->clear_marker_server();
           this->create_mount_point_markers();
        }
        else 
        {
          ROS_WARN("URDF or XACRO file not selected. Try again.");
        }
 
      } else 
      {
         ROS_WARN("Something is wrong with the file name. Please file a bug report with what file you used.");
      } 
      
    } else if (fileNames.size() > 1)
    {
      ROS_WARN("Please select only one URDF/XACRO file. You may add parts later on.");

    } else if (fileNames.size() < 1)
    {
      ROS_WARN("Please select a URDF/XACRO file to be the robot base model.");
    }

    //QFileDialog dialog(this);
    //dialog.setFileMode(QFileDialog::AnyFile);

    // Spawn the RViz Model in visualization. (E.g create visualization display)
    StartScreen::visualizationDisplay->robot_state_display_->subProp("Robot Description")->setValue(QString::fromStdString( "robot_description" ));
    
    std::string robot_description = StartScreen::visualizationDisplay->robot_state_display_->subProp("Robot Description")->getValue().toString().toStdString();

    // Check param server for wherever robot_description is set. 
    std::string urdf_description;
    ros::param::get(robot_description, urdf_description);

    // Check if robot description exists
    if (!urdf_description.empty())
    {
       ROS_INFO("Robot description found. Loading robot model.");
       ROS_INFO("Desc: %s", robot_description.c_str());
       StartScreen::visualizationDisplay->robot_state_display_->reset();
       
    } else
    {
       ROS_INFO("Robot description not found. Please set robot model.");
    }

    this->load_robot_links();
    this->populate_links_table_after_button();
}

void MountPointsTabWidget::create_load_base_urdf_button()
{
    load_urdf_base_button = new QPushButton(QString(QString::fromStdString("Load Model")), this);
    load_urdf_base_button->setGeometry(QRect(700, 35, 120, 50));
    load_urdf_base_button->setVisible(true);

     connect(this->load_urdf_base_button, SIGNAL(clicked()), this, SLOT(load_urdf_base_button_clicked()));
}

void MountPointsTabWidget::create_mount_points_table_widget()
{
    this->links_table = new QTableWidget(0, 1, this);
    this->links_table->setGeometry(QRect(20, 150, 400, 400));
    this->links_table->horizontalHeader()->setStretchLastSection(true);
    this->links_table->setHorizontalHeaderLabels(QString("Robot links;").split(";"));

}

void MountPointsTabWidget::create_selected_mount_points_table_widget()
{
    this->selected_links_table = new QTableWidget(0, 1, this);
    ROS_INFO("Creating selection table..");
    this->selected_links_table->setGeometry(QRect(520, 150, 400, 400));
    this->selected_links_table->horizontalHeader()->setStretchLastSection(true);

    this->selected_links_table->setHorizontalHeaderLabels(QString("Mount points;").split(";"));
}

void MountPointsTabWidget::create_mount_button()
{
  this->mount_button = new QPushButton(">", this);
  this->mount_button->setGeometry(QRect(450, 300, 70, 40));

  // Associate button with function call
  connect(this->mount_button, SIGNAL(clicked()), this, SLOT(mount_button_clicked()));

}

// Takes selected links from list and adds it to selected table.
void MountPointsTabWidget::mount_button_clicked()
{
    QList<QTableWidgetItem*> selected_links = this->links_table->selectedItems();

    for (int i = 0; i < selected_links.size(); i++)
    {
        // Check if the string already exists in table. If it does, don't add
        if (this->selected_links_table->findItems(selected_links[i]->text(), Qt::MatchContains).empty())
        {
		// Add to mount points table if not already in it.
		this->selected_links_table->insertRow(0);
		QTableWidgetItem * newItem = selected_links[i]->clone();
		this->selected_links_table->setItem(0, 0, newItem);
		//links_to_be_added[i] = found_link;
		//this->links_table->removeRow(i);
		//this->selected_links_table->setItem(0, 0, found_link);

                // highlight the link in the display 
                StartScreen::visualizationDisplay->robot_state_display_->setLinkColor(newItem->text().toStdString(), QColor(0, 0, 240));

        } 
        else
        {
                ROS_WARN("%s is already in the mounted points table.", selected_links[i]->text().toStdString().c_str());
        }
    }


}

void MountPointsTabWidget::unmount_button_clicked()
{
     // Remove item from selected_links_table. Essentially inverse of above..
     QList<QTableWidgetItem*> selected_links = this->selected_links_table->selectedItems();

    for (int i = 0; i < selected_links.size(); i++)
    {
		// Add to mount points table if not already in it.
                StartScreen::visualizationDisplay->robot_state_display_->unsetLinkColor(selected_links[i]->text().toStdString());
                ROS_INFO("%s is no longer selected to be a mount point", selected_links[i]->text().toStdString().c_str());
		this->selected_links_table->removeRow(selected_links[i]->row());
    }

}

void MountPointsTabWidget::create_unmount_button()
{
  this->unmount_button = new QPushButton("<", this);
  this->unmount_button->setGeometry(QRect(450, 350, 70, 40));

   connect(this->unmount_button, SIGNAL(clicked()), this, SLOT(unmount_button_clicked()));

}

void MountPointsTabWidget::populate_links_table()
{

    int row_count;
    row_count = this->links.size();
    ROS_INFO("Row count %d", row_count);
    this->links_table = new QTableWidget(row_count, 1, this);
    this->links_table->setSortingEnabled(false);    
    this->links_table->setGeometry(QRect(20, 150, 400, 400));
    this->links_table->horizontalHeader()->setStretchLastSection(true);
    this->links_table->setHorizontalHeaderLabels(QString("Robot links;").split(";"));
    ROS_INFO("Current row count %d", this->links_table->rowCount());

    if (!this->links.empty())
    {

	    // Insert new data
	    for (int i = 0; i < row_count; i++)
	    {
		const robot_model::LinkModel* link_model = this->links.at(i);

		std::string link_name = link_model->getName();
		ROS_INFO("Found link: %s ... Loading ... ", link_name.c_str());
		
		// Create the table item. 
		QTableWidgetItem * entry = new QTableWidgetItem(QString(QString::fromStdString(link_name)));
		this->links_table->setItem(i, 0, entry);
           }
    }
    else
    {
       ROS_WARN("No robot model loaded.. Please load a robot model.");
    }

    ROS_INFO("Current row count %d", this->links_table->rowCount());
}

void MountPointsTabWidget::load_robot_links()
{
   // Get the kinematic model from the display
   if (StartScreen::visualizationDisplay != NULL)
   {
	   robot_model::RobotModelConstPtr display_model = 	StartScreen::visualizationDisplay->robot_state_display_->getRobotModel();

           if (display_model)
           {
	           this->links = display_model->getLinkModels();
		   ROS_INFO("Got link models from display..");
           } 
   } 
   else
   {
       ROS_WARN("The display has not been initialized yet...");
   }

}

