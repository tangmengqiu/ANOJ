#include<iostream>
#include<vector>	
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
const int maxn = 1010;
int N, M, inDegree[maxn];
vector<int> ans;
vector<int> toSave[maxn];
priority_queue<int, vector<int>, greater<int> > q;

void topoLogic() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int top = q.top();
		q.pop();
		ans.push_back(top);
		num++;
		if (num == N)
			break;
		for (int i = 0; i < toSave[top].size(); i++) {
			int id = toSave[top][i];
			inDegree[id]--;
			if (inDegree[id] == 0)
				q.push(id);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		inDegree[b]++;
		toSave[a].push_back(b);
	}
	topoLogic();
	if (ans.size() == N) {
		printf("YES\n");
		for (int i = 0; i < N; i++) {
			printf("%d", ans[i]);
			if (i < N - 1)
				printf(" ");
		}
	} else {
		printf("NO\n");
		printf("%d", N - ans.size());
	}
	return 0;
}