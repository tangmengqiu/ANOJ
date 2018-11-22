#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10010;
struct Node {
	string data;
	vector<int> child;
}node[maxn];

int n, m;
int father[maxn];
bool isRoot[maxn];

int findfather(int x) {
	int a = x;
	while (father[x] != x)
		x = father[x];
	while (father[a] != a) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int faA = findfather(a);
	int faB = findfather(b);
	if (faA != faB) {
		if (faA > faB)
			father[faA] = faB;
		else
			father[faB] = faA;
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}

string removeLeadingZero(string str) {
	while (str.length() > 1 && str.back() == '0')
		str.pop_back();
	return str;
}

string sum = "0", tempSum = "";
string getSum(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string result = "";
	int carry = 0;
	for (int i = 0; i < a.length() || i < b.length() || carry; i++) {
		int num1 = i < a.length() ? (a[i] - '0') : 0;
		int num2 = i < b.length() ? (b[i] - '0') : 0;
		result += (num1 + num2 + carry) % 10 + '0';
		carry = (num1 + num2 + carry) / 10;
	}
	result = removeLeadingZero(result);
	reverse(result.begin(), result.end());
	return result;
}

void dfs(int v) {
	if (node[v].child.size() == 0) {
		sum = getSum(sum, tempSum);
		return;
	}
	for (int i = 0; i < node[v].child.size(); i++) {
		int u = node[v].child[i];
		tempSum += node[u].data;
		dfs(u);
		tempSum.pop_back();
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++) {
		char str[2];
		scanf("%s", str);
		node[i].data = string(str);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		Union(u, v);
		node[u].child.push_back(v);
	}
	for (int i = 0; i < n; i++) {
		int root = findfather(i);
		isRoot[root] = true;
	}
	int num = n - m;
	printf("%d\n", num);
	for (int i = 0; i < n; i++) {
		if (isRoot[i]) {
			sum = "0";
			tempSum = node[i].data;
			dfs(i);
			printf("%s", sum.c_str());
			if (--num)
				printf(" ");
		}
	}
	return 0;
}