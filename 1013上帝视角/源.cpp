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

node* creat(vector<int> level, int inL, int inR) {
	if (level.size() == 0)
		return NULL;
	node *root = new node;
	root->data = level[0];
	root->lchild = root->rchild = NULL;
	int k = inL;
	vector<int> left, right;
	for (; k < inR; k++) {
		if (in[k] == level[0])
			break;
	}
	for (int i = 1; i < level.size(); i++) {
		bool isleft = false;
		for (int j = inL; j < k; j++) {
			if (in[j] == level[i]) {
				isleft = true;
				break;
			}
		}
		if (isleft) {
			left.push_back(level[i]);
		} else
			right.push_back(level[i]);
	}
	root->lchild = creat(left, inL, k - 1);
	root->rchild = creat(right, k + 1, inR);
	return root;
}

int maxH = 0;
void dfs(node* root, int depth) {//you wang zuo kan
	if (root == NULL)return;
	if (depth > maxH)
		maxH = depth;
	dfs(root->lchild, depth + 1);
	dfs(root->rchild, depth + 1);
}

int maxRU = 0;
void inOrder1(node* root, int num) {//you shang wang zuo xia
	if (root == NULL)return;
	if (num > maxRU)
		maxRU = num;
	inOrder1(root->lchild, num);
	inOrder1(root->rchild, num + 1);
}

int maxleft = 0, maxRight = 0;
void inOrder2(node* root, int left, int right) {
	if (root == NULL)return;
	if (left > maxleft)
		maxleft = left;
	if (right > maxRight)
		maxRight = right;
	inOrder2(root->lchild, left + 1, right - 1);
	inOrder2(root->rchild, left - 1, right + 1);
}
int cnt1 = 0;
void pre(node* root) {
	if (root == NULL)
		return;
	printf("%d", root->data);
	cnt1++;
	if (cnt1 < n)
		printf(" ");
	else
		printf("\n");
	pre(root->lchild);
	pre(root->rchild);

}
int cnt2 = 0;
void post(node* root) {
	if (root == NULL)
		return;
	post(root->lchild);
	post(root->rchild);
	printf("%d", root->data);
	cnt2++;
	if (cnt2 < n)
		printf(" ");
	else
		printf("\n");
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		level.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	node* root = creat(level, 0, n - 1);
	dfs(root, 1);
	inOrder1(root, 1);
	inOrder2(root, 0, 0);
	pre(root);
	post(root);
	cout << maxH << endl;
	cout << maxRU << endl;
	cout << maxleft + maxRight + 1 << endl;

	return 0;
}