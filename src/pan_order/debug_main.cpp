#include<pan_order/Pan_Order.h>

//このプログラムは受け取ったデータを外部に送信します。
int main(int argc,char **argv){
	ros::init(argc,argv,"pan_order_po");

    OrderClass po;
    ros::spin();
    // po.mainloop();

	return 0;
}