#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
const int INF = 1000000000;
int n, m, p, k;
set<int> Start;
set<int> evil;
int G[maxn][maxn];

int main() {
	cin >> n >> m >> p >> k;
	for (int i = 0; i < p; i++) {
		int temp;
		scanf("%d", &temp);
		Start.insert(temp);
	}
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		evil.insert(temp);
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u][v] = w;
	}

	return 0;
}