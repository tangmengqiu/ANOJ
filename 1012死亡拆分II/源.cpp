#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 10000010;
int n;
LL a[maxn];
int main() {
	LL sum = 0, sum1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	nth_element(a, a + n / 2, a + n);
	for(int i = 0; i < n / 2; i++) {
		sum1 += a[i];
	}
	if (n % 2 == 1 && a[n / 2] < 0)
		sum1 += a[n / 2];
	printf("%d %lld", n % 2, sum - sum1 - sum1);
	return 0;
}