#include"Calculate.h"

double Calculate::Calculate_Fg()
{
	Calculate_Globle_Point();
	Fg = 1 - ((gi_x - Nearest_x)*(gi_x - Nearest_x) + ((gi_y - Nearest_y)*(gi_y - Nearest_y))) / Distance_max;
	cout << "c++ project" << endl;
	return Fg;
}
void Calculate::Calculate_Globle_Point()
{
	zi_x = zi_dis*cos(zi_p);
	zi_y = zi_dis*sin(zi_p);
	gi_x = cos(p)*zi_x - sin(p)*zi_y + x;
	gi_y = sin(p)*zi_x + cos(p)*zi_y + y;
}
double Calculate::Calculate_Vg()
{
	for (int i = 0; i < n; i++)
	{
		 V_x_y_p = V_x_y_p + Calculate_Fg();
	}
	return V_x_y_p;
}
void Calculate::Calculate_TiDu()
{
	int k = 1;
	step_max = 10, step_min = 2, MaxIterater = 10;
	double W;
	while (1)
	{
		int step = step_max;
		while (step >= step_min)
		{
			W = Calculate_Vg();
			x = xi + step*dx;
			y = yi + step*dy;
			p = pi + step*dp;
			if (Calculate_Vg() < W)
			{
				xj = x;
				yj = y;
				pj = p;
				break;
			}
			step = step / 2;
		}
		if (k = MaxIterater || step < step_min)
		{
			x = xi;
			y = yi;
			p = pi;
			break;
		}
		else
		{
			Calculate_d_x_y_p();
		}
	}

}

void  Calculate::Calculate_d_x_y_p()
{
	for (int i = 0; i < n; i++)
	{
		dx = dx + (2*(nearest_x + gi_x))/Distance_max;
		dy = dy + (2 * (nearest_y + gi_y)) / Distance_max;
		dp = dp + (2*((nearest_x - gi_x)*(-sin(zi_p)*zi_x - cos(zi_p)*zi_y) + (nearest_y - gi_y)*(cos(zi_p)*zi_x - sin(zi_p)*zi_y)))/Distance_max;
	}
}
