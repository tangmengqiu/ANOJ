#include<iostream>
#include<string>
using namespace std;

int strToint(string str) {
	if (str == "one")
		return 1;
	else if (str == "zero")
		return 0;
	else if (str == "two")
		return 2;
	else if (str == "three")
		return 3;
	else if (str == "four")
		return 4;
	else if (str == "five")
		return 5;
	else if (str == "six")
		return 6;
	else if (str == "seven")
		return 7;
	else if (str == "eight")
		return 8;
	else return 9;
}

bool canBe(int a, int b, int c) {
	bool flag = true;
	if (a+b<=c) {
		flag = false;
	}
	if (a+c<=b) {
		flag = false;
	}
	if (b+c<=a)
		flag = false;
	return flag;
}
int main() {
	string str[20];
	int num = 0;
	int a[3] = { 0 };
	int temp;
	for (int i = 0; i < 3; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> str[num];
			a[i] = a[i] * 10 + strToint(str[num]);
			num++;
		}
	}
	if (canBe(a[0], a[1], a[2]))
		printf("YES");
	else
		printf("NO");
	return 0;
}