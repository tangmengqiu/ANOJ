#include<iostream>
#include<cmath>
using namespace std;
//小恐龙的起跳横坐标a、横向跳跃距离x、纵向跳跃高度y、仙人掌根部横坐标b、仙人掌高度h
int main() {
	double a,x,y,b,h;
	cin >> a >> x >> y >> b >> h;
	
	double  mid = (a+a + x) / 2;
	if (b > a&&b <= mid) {
		double height = y - 4 * y / (x*x)*(mid - b)*(mid - b);
		if (height <= h)
			printf("NO\n");
		else {
			printf("YES\n");
		}
	} else if (b > mid&&b < a + x) {
		double height = y - 4 * y / (x*x)*(b - mid)*(b - mid);
		if (height <= h)
			printf("NO\n");
		else {
			printf("YES\n");
		}
	} else if (a > b)
		printf("YES");
	else if (a + x < b)
		printf("YES\n");
	else
		printf("NO");
	return 0;
}