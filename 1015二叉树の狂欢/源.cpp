#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>	
#include<queue>
using namespace std;
const int maxn = 34;
bool isRoot[maxn];
struct Node {
	int data;
	int lchild, rchild;
}node[maxn];

int Heap[maxn];

int input() {
	char id[3];
	scanf("%s", id);
	if (id[0] == '-')
		return -1;
	else {
		if (strlen(id) == 1)return id[0] - '0';
		else
			return (id[0] - '0')*10 + id[1]-'0';
	}
}

int finRoot(int n) {
	for (int i = 1; i <= n; i++) {
		if (isRoot[i]) {
			return i;
		}
	}
}

int numNotBanlanced = 0;
bool isAvl(int root,int &height) {
	if (root == -1) {
		height = 0;
		return true;
	}
	int leftH, rightH;
	bool f1 = isAvl(node[root].lchild, leftH);
	bool f2 = isAvl(node[root].rchild, rightH);
	height = max(leftH, rightH) + 1;
	bool isBalanced = abs(leftH - rightH) <= 1;
	if (!isBalanced)numNotBanlanced++;
	return isBalanced && f1&&f2;
}

int lastFull = 0;
bool isCpt(int root,int n) {
	queue<int> q;
	q.push(root);
	int indexHeap = 1;
	while (n) {
		int size = q.size();//当前层节点个数
		for (int i = 0;  n&&i < size; i++) {
			int front = q.front();
			q.pop();
			if (front == -1)return false;
			Heap[indexHeap++] = node[front].data;
			n--;
			q.push(node[front].lchild);
			q.push(node[front].rchild);
		}
		lastFull++;
	}
	return true;
}

int downAdjust(int low, int high) {
	int swapNum = 0;
	int i = low, j = 2 * i;
	while (j <= high) {
		if (j + 1 <= high && Heap[j + 1] > Heap[j])
			j++;
		if (Heap[i] < Heap[j]) {
			swap(Heap[i], Heap[j]);
			i = j;
			j = 2 * i;
			swapNum++;
		} else
			break;
	}
	return swapNum;
}

int makeheap(int n) {
	int numSwap = 0;
	for (int i = n / 2; i >= 1; i--) {
		numSwap+=downAdjust(i,n);
	}
	return numSwap;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &node[i].data);
	}
	memset(isRoot, true, sizeof(isRoot));
	for (int i = 1; i <= n; i++) {
		int left = input(), right = input();
		if (left != -1)
			isRoot[left] = false;
		if (right != -1)isRoot[right] = false;//?
		node[i].lchild = left;
		node[i].rchild = right;
	}
	int root = finRoot(n),height;
	if (!isAvl(root, height))
		printf("NOT AVL TREE!!!\n%d", numNotBanlanced);
	else if (!isCpt(root, n)) {
		printf("NOT COMPLETE TREE!!!\n%d", lastFull);
	} else
		printf("OHHHHH HEAP!!!\n%d", makeheap(n));
	return 0;
}