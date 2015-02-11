#include <buildit_ui/ui/start_screen_tab_widget.h>

StartScreenTabWidget::StartScreenTabWidget(QWidget * parent) : QTabWidget(parent)
{
    	this->setObjectName(QString::fromUtf8("startScreenTabWidget"));
        this->setEnabled(true);
        this->setLayoutDirection(Qt::LeftToRight);
        this->setTabPosition(QTabWidget::North);
        this->setTabShape(QTabWidget::Rounded);

        addMountPointsTabWidget();
        // Add the widgets to the tab widget
}
 
void StartScreenTabWidget::addMountPointsTabWidget()
{
      mount_points_widget = new MountPointsTabWidget();
      this->addTab(mount_points_widget, QString(QString::fromStdString("Step 1: Mount Points")));
}

StartScreenTabWidget::~StartScreenTabWidget()
{
    delete this;
}
