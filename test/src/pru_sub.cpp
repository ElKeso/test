#include "ros/ros.h"
#include "test/tray.h"
#include "test/trayArray.h"


test::trayArray msg_2;
int f =0;

void chatterCallback(const test::trayArray &msg){
    msg_2=msg;
    f=1;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_array");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("/prueba", 1000, chatterCallback);
  float suma=0;
  int i=0;  
  while (ros::ok()){
    ros::spinOnce();
    if(f==1){
    for(i;i<11;i=i+1){
        suma=suma+msg_2.trayectoria[i].x;
    }
    ROS_INFO("suma es %f",suma);
    f=0;
    }  
  }  

  return 0;
}
