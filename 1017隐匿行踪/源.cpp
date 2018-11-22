#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1011;
double INF = 1e20;
double eps = 1e-8;
#define LessEqu(a,b) ((a)-(b)<eps)
struct point { double x, y, r; }pt[maxn];
int n, x, y, r;
int st, ed;
int father[maxn];

int findfather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b) {
	int faA = findfather(a);
	int faB = findfather(b);
	if (faA != faB)
		father[faA] = faB;
}

void init() {
	for (int i = 0; i <= n + 1; i++) {
		father[i] = i;
	}
}

double G[maxn][maxn], d[maxn];
bool vis[maxn];

void dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i <= n + 1; i++) {
		int u = -1;
		double MIN = INF;
		for (int j = 0; j < n + 2; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v <= n + 1; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf %lf", &pt[i].x, &pt[i].y, &pt[i].r);
	}
	scanf("%lf %lf", &pt[0].x, &pt[0].y);
	scanf("%lf %lf", &pt[n + 1].x, &pt[n + 1].y);
	pt[0].r = pt[n + 1].r = 0;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = i+1; j <= n + 1; j++) {
			double disij = dis(pt[i].x, pt[i].y, pt[j].x, pt[j].y);
			if (LessEqu(disij, pt[i].r + pt[j].r)) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		G[i][i] = INF;
		for (int j = i + 1; j <= n + 1; j++) {
			double disij = dis(pt[i].x, pt[i].y, pt[j].x, pt[j].y);
			if (findfather(i) == findfather(j))
				G[i][j] = 0;
			else
				G[i][j] = G[j][i] = disij - pt[i].r - pt[j].r;
		}
	}
	dijkstra(0);
	printf("%.2f\n", d[n + 1]);
	return 0;
}