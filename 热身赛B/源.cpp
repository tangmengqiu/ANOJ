#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;

struct node {
	int data, height;
	node *lchild, *rchild;
};

void insert(node* &root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data)
		insert(root->lchild, x);
	else
		insert(root->rchild, x);
}


bool cmp(node* root1, node* root2) {
	bool flag;
	if (root1&&root2) {
		if (root1->data == root2->data)
			flag = true;
	} else if (root1 == NULL && root2 == NULL)
		return true;//zhi jie return
	else
		return false;
	bool f1 = cmp(root1->lchild, root2->lchild);
	bool f2 = cmp(root1->rchild, root2->rchild);
	return flag && f1&&f2;
}

int cnt = 0;
void post(node* root) {
	if (root == NULL)
		return;
	post(root->lchild);
	post(root->rchild);
	printf("%d", root->data);
	cnt++;
	if (cnt < n)
		printf(" ");
}

int num = 0;
queue<node*> q;
void level(node* root) {
	q.push(root);
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		printf("%d", top->data);
		num++;
		if (num < n)
			printf(" ");
		if (top->lchild)
			q.push(top->lchild);
		if (top->rchild)
			q.push(top->rchild);
	}
}

int main() {
	cin >> n;
	node *root1 = NULL, *root2 = NULL;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		insert(root1, temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		insert(root2, temp);
	}
	if (cmp(root1, root2)) {
		printf("YES\n");
	} else
		printf("NO\n");
	post(root1);
	cout << endl;
	level(root1);
	return 0;
}