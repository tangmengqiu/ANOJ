#include<iostream>
#include <string>
using namespace std;

const int MAXN = 35;

int N;
bool isUsed[MAXN];
int root;

struct Node {
	int lchild, rchild;
	char op;
	int  num;
	bool flag;
}node[MAXN];



double calAndPrint(int root, int layer) {
	if (node[root].flag == false) {
		printf("%d", node[root].num);
		return node[root].num;
	}
	if (layer > 1)
		printf("(");
	double a = calAndPrint(node[root].lchild, layer + 1);
	printf("%c", node[root].op);
	double b = calAndPrint(node[root].rchild, layer + 1);
	if (layer > 1)
		printf(")");
	double ans = 0;
	if (node[root].op == '+')
		ans = a + b;
	else if (node[root].op == '-')
		ans = a - b;
	else if (node[root].op == '*')
		ans = a * b;
	else
		ans = a / b;
	return ans;
}

int strToNum(string str) {
	if (str[0] == '+' || str[0] == '-'
		|| str[0] == '*' || str[0] == '/')
		return -1;
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		ans = ans * 10 + str[i] - '0';
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int x = strToNum(str);
		if (x == -1) {
			node[i].op = str[0];
			node[i].flag = true;
		} else {
			node[i].num = x;
			node[i].flag = false;
		}
	}
	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		int a = strToNum(str1);
		int b = strToNum(str2);
		node[i].lchild = a;
		if (a != -1)
			isUsed[a] = true;
		node[i].rchild = b;
		if (b != -1)
			isUsed[b] = true;
	}
	for (int i = 0; i < N; i++) {
		if (isUsed[i] == false) {
			root = i;
			break;
		}
	}
	double ans = calAndPrint(root, 1);
	printf(" %.2f\n", ans);
	return 0;
}
