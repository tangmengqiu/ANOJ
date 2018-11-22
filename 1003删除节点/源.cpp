#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int data, address, next;
}node[100005];

bool flag[100005] = { false };
int a[100005];
int main() {
	int n, first;
	scanf("%d %05d", &n, &first);
	if (first == -1) {
		printf("0 -1\n");
		return 0;
	}
	int add, data, next;
	for (int i = 0; i < n; i++) {
		scanf("%05d %d %05d", &add, &data, &next);
		node[add].address = add;
		node[add].data = data;
		node[add].next = next;
	}
	int p = first;
	int cnt = 0;
	while (p != -1) {
		int num = node[p].data;
		if (num < 0)
			num = -num;
		if (flag[num]) {
			p = node[p].next;
			continue;
		} else {
			flag[num] = true;
			a[cnt++] = node[p].address;
		}
	}
	printf("%d %05d\n", cnt, a[0]);
	for (int i = 0; i < cnt - 1; i++) {
		if (i == 0) {
			printf("%05d %d ", a[i], node[a[i]].data);
		} else {
			printf("%05d\n%05d %d ", a[i], a[i], node[a[i]].data);
		}
	}
	if (cnt == 1)
		printf("%05d %d -1", a[0], node[a[0]].data);
	else
		printf("%05d\n%05d %d -1", a[cnt - 1], a[cnt - 1], node[a[cnt - 1]].data);
	return 0;
}