#include<iostream>
#include<vector>
using namespace std;
const int maxn = 35;
vector<int> level, in;
int n;

struct node {
	int data;
	node *lchild, *rchild;
};

node* Creat(vector<int> level, int inL, int inR) {
	if (level.size() == 0)return NULL;
	node* root = new node;
	root->data = level[0];
	root->lchild = root->rchild = NULL;
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == level[0])break;
	}
	vector<int> left, right;
	for (int i = 1; i < level.size(); i++) {
		bool isleft = false;
		for (int j = 0; j < k; j++) {
			if (in[j] == level[i]) {
				isleft = true;
			}
		}
		if (isleft)left.push_back(level[i]);
		else
			right.push_back(level[i]);
	}
	root->lchild = Creat(left, inL, k - 1);
	root->rchild = Creat(right, k + 1, inR);
	return root;
}

int num1 = 0;
void pre(node* root) {
	if (root == NULL)return;
	printf("%d", root->data);
	num1++;
	if (num1 < n)
		printf(" ");
	else
		printf("\n");
	pre(root->lchild);
	pre(root->rchild);
}

int num2 = 0;
void post(node* root) {
	if (root == NULL)return;
	post(root->lchild);
	post(root->rchild);
	printf("%d", root->data);
	num2++;
	if (num2 < n)printf(" ");
	else printf("\n");
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		level.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		in.push_back(temp);
	}
	node* root = Creat(level, 0, n - 1);
	pre(root);
	post(root);
	return 0;
}