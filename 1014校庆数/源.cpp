#include<iostream>
#include<string>
using namespace std;
string str;
int main() {
	cin >> str;
	int sum = 0, sqrSum = 0;
	for (int i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
		sqrSum += (str[i] - '0')*((str[i] - '0'));
		if (sum > 120) {
			printf("NO\n");
			return 0;
		}
	}
	if ((str=="120")||sum == 120 || sqrSum == 120)
		printf("YES\n");

	return 0;
}