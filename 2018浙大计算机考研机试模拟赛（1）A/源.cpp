#include<iostream>
#include<cmath>
using namespace std;
//С����������������a��������Ծ����x��������Ծ�߶�y�������Ƹ���������b�������Ƹ߶�h
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