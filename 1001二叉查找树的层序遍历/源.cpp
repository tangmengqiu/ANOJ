#include<iostream>
#include <queue>
using namespace std;

const int MAXN = 100005;

int pre[MAXN];
int N;


struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

void insert(Node* &root, int x) {
	if (root == NULL) {
		root = new Node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
	}
	else {
		insert(root->rchild, x);
	}
}

queue<Node*> q;
int cnt = 0;
void layerOrder(Node* root) {
	q.push(root);
	while (!q.empty()) {
		Node* top = q.front();
		q.pop();
		cout << top->data;
		cnt++;
		if (cnt < N )
			cout << " ";
		if (top->lchild)
			q.push(top->lchild);
		if (top->rchild)
			q.push(top->rchild);
	}
	return;
}


int main() {
	scanf("%d", &N);
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &pre[i]);
		insert(root, pre[i]);
	}
	layerOrder(root);
	return 0;
}