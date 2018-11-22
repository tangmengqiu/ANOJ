#include<iostream>
#include<vector>
#include<algorithm>	
using namespace std;
typedef long long LL;
LL a[10000010];
int n;

int findMinLost() {
	for (int i = 1; i <= n; i++) {
		while (a[i] >= 1 && a[i] <= n && a[i] != a[a[i]]) {
			swap(a[i], a[a[i]]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != i)
			return i;
	}
	return n + 1;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	printf("%d", findMinLost());
	return 0;
}