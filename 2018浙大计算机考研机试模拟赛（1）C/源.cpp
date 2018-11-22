#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn = 1001;
const int INF = 1000000000;
int N, M;
int degree[maxn];
vector<int> tosave[maxn];
int ve[maxn], vl[maxn];//事件
int e[maxn], l[maxn];//活动
vector<int> ans[maxn];

struct edge {
	int v, w;
}G[maxn][maxn];

priority_queue<int, vector<int>, greater<int> > q;
stack<int> topOrder;

bool topologicalSort() {
	for (int i = 0; i < N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}
	while (q.empty()) {
		int u = q.top();
		q.pop();
		topOrder.push(u);
		for (int i = 0; i < tosave[u].size(); i++) {
			int v = tosave[u][i];
			degree[v]--;
			if (degree[v] == 0)
				q.push(v);
			if (ve[u] + G[u][v].w > ve[v])
				ve[v] = ve[u] + G[u][v].w;
		}
	}
	if (topOrder.size() == N)
		return true;
	else
		return false;
}

int CrititalPath() {
	memset(ve, 0, sizeof(ve));
	if (topologicalSort() == false)
		return -1;
	fill(vl, vl + N, ve[N - 1]);
	while (!topOrder.empty()) {
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < tosave[u].size(); i++) {
			int v = tosave[u][i];
			if (vl[v] - G[u][v].w < vl[u])
				vl[u] = vl[v] - G[u][v].w;
		}
	}
	for (int u = 0; u < N; u++) {
		for (int i = 0; i < tosave[u].size(); i++) {
			int v = tosave[u][i];
			int w = G[u][v].w;
			int e = ve[u], l = vl[v] - w;
			if (e == l)
				ans[u].push_back(v);
		}
	}
}
int main() {
	cin >> N >> M;
	fill(G[0], G[0] + maxn * maxn, INF);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		degree[b]++;
		tosave[a].push_back(b);
		G[a][b].w = c;
		G[a][b].v = b;
	}
	int cnt = CrititalPath();
	if (cnt == -1) {
		printf("NO %d",)
	}
	return 0;
}