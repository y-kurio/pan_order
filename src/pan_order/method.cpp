#include<pan_order/Pan_Order.h>

void OrderClass::__angle_callback(const pan_order::SetAngle& msg)
{
    camera_angle_ = msg;
    // __manage();
}

void OrderClass::__pan_angle_callback(const std_msgs::Float64& msg)
{
    pan_angle_ = msg;
    // __manage();
}

void OrderClass::__tilt_angle_callback(const std_msgs::Float64& msg)
{
    tilt_angle_ = msg;
    // __manage();
}

void OrderClass::mainloop()
{
    ros::Rate loop_rate(1);
	while (ros::ok())
	{
        __riskobject();
        __pantilt_order();
        __publish();
		ros::spinOnce();
		loop_rate.sleep();
	}
}

void OrderClass::__manage()
{
    __riskobject();
    __pantilt_order();
    __publish();
}

void OrderClass::__riskobject()
{
    // most_Cluster_theta_ = (camera_angle_.angle)/M_PI*180;
    most_Cluster_theta_pan_ = (pan_angle_.data)/M_PI*180;
    most_Cluster_theta_tilt_ = (tilt_angle_.data)/M_PI*180;
}

void OrderClass::__pantilt_order()
{
    // pubPanData_.id = camera_angle_.id;
    // pubPanData_.position = int((most_Cluster_theta_*11.6) + 2048);
    pubtiltData_.id = 1;
    pubtiltData_.position = int((most_Cluster_theta_pan_*11.6) + 2048);
    pubPanData_.id = 2;
    pubPanData_.position = int((most_Cluster_theta_tilt_*11.6) + 2048);
}

void OrderClass::__publish()
{
    pub_pan_position_.publish(pubPanData_);
    pub_tilt_position_.publish(pubtiltData_);
}
