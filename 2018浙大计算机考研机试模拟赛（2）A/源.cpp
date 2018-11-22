#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1001;
string str;
int ans = 0;
bool vis[128];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int num = 0;
		memset(vis, false, sizeof(vis));
		for (int j = 0; j < str.length(); j++) {
			if ((str[j] >= 'a'&&str[j] <= 'z') || (str[j] >= 'A'&&str[j] <= 'Z')) {
				if (vis[str[j] - '0'] == false) {
					num++;
					vis[str[j] - '0'] = true;
				}
			}
		}
		ans += num;
	}
	printf("%d\n", ans);
}