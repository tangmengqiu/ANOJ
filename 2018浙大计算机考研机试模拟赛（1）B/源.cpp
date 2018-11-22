#include<iostream>
using namespace std;
const int MAXN = 1010;
int F, N;

long long Catalan[MAXN];
long long CatalanCalc()
{
	Catalan[0] = 1;
	Catalan[1] = 1;
	for (long long i = 2; i < MAXN; i++)
	{
		Catalan[i] = 0;
		for (long long j = 0; j < i; j++)
			Catalan[i] += (Catalan[j] * Catalan[i - 1 - j]);
	}
}


int main() {
	cin >> F >> N;
	if (N > 1000000007)
		N %= 1000000007;
	CatalanCalc();
	long long num = Catalan[N];
	printf("%d", num % 1000000007);
	return 0;
}