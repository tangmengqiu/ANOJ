#include<iostream>
#include<algorithm>
using namespace std;
long long a[1001];
int main() {
	int N;
	cin >> N;
	long long  sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		sum2 += a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N / 2; i++) {
		sum1 += a[i];
	}
	if (a[N / 2] < 0 && N % 2 == 1)//ÕâÊÇ¾Þ¿Ó
		sum1 += a[N / 2];
	printf("%d %lld\n", N % 2, abs(sum2-sum1-sum1));
	return 0;
}