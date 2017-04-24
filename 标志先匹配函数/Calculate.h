#pragma once
#include<iostream>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include <vector>
#include <math.h>

using namespace cv;
using namespace std;
class Calculate {
	private:
		double x = 100, y = 100, p = 45,xi,yi,pi,xj,yj,pj;//������ȫ������x,y��
		double zi_p = 3, zi_dis = 15;//�������ĽǶȺ;���
		double zi_x, zi_y;//������ľֲ�����
		double gi_x, gi_y;//�������ȫ������

		double Distance_min = 100, Distance_max = 150; //���������С����
		double nearest_x = 110, nearest_y = 120;//ÿһ������c��g���������
		double Nearest_x = 110, Nearest_y = 120;//���������꣬ȫ������
		double Fg = 0;//����F(g)
		double dx, dy, dp;
		double  V_x_y_p=0;//����V��x,y,p);
		double W_x_y_p = 0;//����W(x,y,p);
		double step_max, step_min;
		int MaxIterater,n=2;
	public:
		void Calculate_Globle_Point();
		double Calculate_Fg();
		double Calculate_Vg();
		void Calculate_TiDu();
	    void Calculate_d_x_y_p();
};