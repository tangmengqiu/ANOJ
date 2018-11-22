#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

const int maxn = 505;
const int INF = 1000000000;
int N, M, L, K, st, ed;//2<=N<=500, M<=N*(N-1)/2, 1<=L<=500, 2<=K<=100, S != T），
//分别代表城市个数、道路条数、辐能上升的层数、辐能吸收器的容量、起点城市编号、终点城市编号。
int blue[maxn], G[maxn][maxn],d[maxn];
vector<int> pre[maxn],path,tempPath;
bool vis[maxn];
bool inq[maxn] = { false };

struct node {
	int id, layer;
};

queue<node> q;
void bfs() {
	node start;
	start.id = st;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		int u = top.id;
		if(top.layer < L) {
			blue[u] += (int)(ceil(blue[u]*1.0*(L-top.layer)/L)+0.5);
		}
		for (int v = 0; v < N; v++) {
			if (!inq[v] && G[u][v] != INF) {
				node next;
				next.id = v;
				next.layer = top.layer + 1;
				q.push(next);
				inq[v] = true;
			}
		}
	}
}

void dijkstra(int s) {
	fill(d, d + maxn, INF);
	memset(vis, false, sizeof(vis));
	d[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (d[v] == d[u] + G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int maxLeft = -1,minLastHalf=INF;
int num = 0;
void dfs2(int v) {
	if (v == st) {
		num++;
		tempPath.push_back(v);
		int magic = 0,lasthalf=0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int s = tempPath[i];
			magic += blue[s];
			if (i < tempPath.size() / 2) {
				lasthalf += blue[s];
			}
		}
		magic %= K;
		if (magic > maxLeft) {
			maxLeft = magic;
			path = tempPath;
			minLastHalf = lasthalf;
		}
		else if (magic == maxLeft && lasthalf < minLastHalf) {
			minLastHalf = lasthalf;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) {
		dfs2(pre[v][i]);
	}
	tempPath.pop_back();
}


int main() {
	cin >> N >> M >> L >> K >> st >> ed;
	for (int i = 0; i < N; i++) {
		scanf("%d", &blue[i]);
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	memset(vis, false, sizeof(vis));
	bfs();
	dijkstra(st);
	dfs2(ed);
	if (inq[ed]==false) {
		printf("-1");
		return 0;
	}
	printf("%d %d %d %d\n", num, d[ed], maxLeft, minLastHalf);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i > 0)
			printf("->");
	}
	return 0;
}