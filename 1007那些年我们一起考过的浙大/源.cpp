#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int maxn = 305;
int N;


struct student {
	int a, b, c, d, total;
	string id;
}stu[maxn];
vector<student> ans;
bool cmp(student a, student b) {
	if (a.total != b.total)return a.total > b.total;
	else return a.id < b.id;
}
int main() {
	int a, b, c, d, l;
	cin >> a >> b >> c >> d>>l;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stu[i].id;
		scanf("%d %d %d %d",  &stu[i].a, &stu[i].b, &stu[i].c, &stu[i].d);
		stu[i].total = stu[i].a + stu[i].b + stu[i].c + stu[i].d;
		if (stu[i].total >= l && stu[i].a >= a && stu[i].b >= b && stu[i].d >= d && stu[i].c >= c) {
			ans.push_back(stu[i]);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].id << " " << ans[i].total << endl;
	}
	return 0;
}