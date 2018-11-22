#include<iostream>
#include<vector>
using namespace std;
vector<int > path[31];
int st, ed;
int n, m, l, k;
int num;
void  dfs(int v,int cris) {
	if (v == ed) {
		if (cris == l) {
			num++;
			return;
		} else if (cris < l) {
			for (int i = 0; i < path[ed].size(); i++) {
				dfs(path[ed][i],  cris + 1);
			}
		} else//´óÓÚl
			return;
	}
	else {
		if (cris >= l)//¶àÓàl
			return;
		for (int i = 0; i < path[v].size(); i++) {
			dfs(path[v][i], cris + 1);
		}
	}
	
}
int main() {
	scanf("%d %d %d",&n,&m,&l);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		path[u].push_back(v);
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++) {
		scanf("%d %d", &st, &ed);
		dfs(st, 0);
		printf("%d\n", num% 1000000007);
		num = 0;
	}
	return 0;
}