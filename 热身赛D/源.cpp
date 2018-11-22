#include<iostream>
#include<vector>
using namespace std;
vector<int> level, in;
int N;

struct node {
	int data;
	node *lchild, *rchild;
};

node* Creat(vector<int> level,int inL,int  inR) {
	if (inL > inR)
		return NULL;
	node* root = new node;
	root->data = level[0];
	vector<int> left, right;
	int k ;
	for (k = inL; k <= inR; k++) {
		if (level[0] == in[k]) break;
	}
	for (int i = 1; i < level.size(); i++) {
		bool isLeft = false;
		for (int j = inL; j < k; j++) {
			if (level[i] == in[j])
				isLeft = true;
		}
		if (isLeft)
			left.push_back(level[i]);
		else
			right.push_back(level[i]);
	}
	root->lchild = Creat(left, inL, k - 1);
	root->rchild = Creat(right, k + 1, inR);
	return root;
}

int cnt = 0;
void preOrder(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d", root->data);
	cnt++;
	if (cnt < N)
		printf(" ");
	preOrder(root->lchild);
	preOrder(root->rchild);
}

int num = 0;
void postOrder(node* root) {
	if (root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
	num++;
	if (num < N)
		printf(" ");
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		level.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		in.push_back(a);
	}
	node* root = Creat(level, 0, N - 1);
	preOrder(root);
	cout << endl;
	postOrder(root);
	return 0;
}