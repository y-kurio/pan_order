#include<pan_order/Pan_Order.h>

OrderClass::OrderClass()
{
	sub_angle_ =nh_.subscribe("set_angle",1,&OrderClass::__angle_callback,this);
    pub_pan_position_=nh_.advertise<dynamixel_sdk_examples::SetPosition>("set_position",1);
    pub_tilt_position_=nh_.advertise<dynamixel_sdk_examples::SetPosition>("set_position",1);
	sub_pan_angle_ =nh_.subscribe("pan/command",1,&OrderClass::__pan_angle_callback,this);
	sub_tilt_angle_ =nh_.subscribe("tilt/command",1,&OrderClass::__tilt_angle_callback,this);
	__setLaunchParam();
}
OrderClass::~OrderClass()
{

}