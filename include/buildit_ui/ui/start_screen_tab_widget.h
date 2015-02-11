#ifndef START_SCREEN_TAB_WIDGET_H
#define START_SCREEN_TAB_WIDGET_H

#include <QTabWidget>
#include <QString>
#include <buildit_ui/ui/mount_points_tab_widget.h>

class StartScreenTabWidget : public QTabWidget
{
   Q_OBJECT
   public:
   	StartScreenTabWidget(QWidget * parent = 0);
   	~StartScreenTabWidget();
   private:

        MountPointsTabWidget * mount_points_widget;

        void addMountPointsTabWidget();

};

#endif
