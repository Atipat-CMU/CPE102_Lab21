#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
	double x_left = (R1.x < R2.x ? R2.x : R1.x);
	double x_right = ((R1.x + R1.w) < (R2.x + R2.w) ? (R1.x + R1.w) : (R2.x + R2.w));
	double y_top = (R1.y > R2.y ? R2.y : R1.y);
	double y_bottom = ((R1.y - R1.h) > (R2.y - R2.h) ? (R1.y - R1.h) : (R2.y - R2.h));
	double xL = (x_right > x_left ? x_right - x_left : 0);
	double yL = (y_top > y_bottom ? y_top - y_bottom : 0);

	return xL*yL;
}

int main(){
	Rect R2 = {1,1,5,5};
	Rect R1 = {2,2,5,5};
	cout << overlap(R1,R2);			
}
