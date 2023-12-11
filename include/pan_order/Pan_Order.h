#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>

#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>
#include <vector>
#include <cmath>

// pantilt
#include <dynamixel_sdk_examples/GetPosition.h>
#include <dynamixel_sdk_examples/SetPosition.h>
#include <dynamixel_sdk/dynamixel_sdk.h>

//msg
#include <pan_order/ClassificationData.h>
//データ型
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <pcl_ros/point_cloud.h>

#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>
#include <vector>
#include <cmath>

//msg
// #include <pan_order/ClassificationData.h>
#include <pan_order/pointData.h>
#include <pan_order/SetAngle.h>




//クラスの定義
class OrderClass{
    private:
        ros::NodeHandle pnh_;
		ros::NodeHandle nh_;
        ros::Subscriber sub_angle_, sub_pan_angle_, sub_tilt_angle_;
        ros::Publisher pub_pan_position_, pub_tilt_position_;
        dynamixel_sdk_examples::SetPosition pubPanData_, pubtiltData_;
        double most_Cluster_theta_, most_Cluster_theta_pan_, most_Cluster_theta_tilt_;
        pan_order::SetAngle camera_angle_;
        std_msgs::Float64 pan_angle_, tilt_angle_;

        void __angle_callback(const pan_order::SetAngle& msg);
        void __pan_angle_callback(const std_msgs::Float64& msg);
        void __tilt_angle_callback(const std_msgs::Float64& msg);
        void __manage();
        void __setLaunchParam();
        void __riskobject();
        void __pantilt_order();
        void __publish();//データ送信

    public:
        OrderClass();
        ~OrderClass();
        void mainloop();
        
};