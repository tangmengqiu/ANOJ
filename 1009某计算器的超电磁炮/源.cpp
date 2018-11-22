#include<iostream>
#include<stack>	
#include<queue>
#include<map>
#include<string>
using namespace std;

struct node {
	double num;
	char op;
	bool flag;
};
string str;
queue<node> q;
stack<node> s;
map<char, int> op;

void change() {
	double num;
	node temp;
	for (int i = 0; i < str.length(); ) {
		if (str[i] >= '0'&&str[i] <= '9') {
			num = 0;
			while (i<str.length() && str[i] >= '0'&&str[i] <= '9') {
				num = num * 10 + str[i] - '0';
				i++;
			}
			temp.num = num;
			temp.flag = true;
			q.push(temp);
		}
		else if (str[i] == '(') {
			temp.op = str[i]; 
			temp.flag = false;
			s.push(temp);
			i++; 
		}
		else if (str[i] == ')') {
			while (!s.empty() && s.top().op!='(') {
				q.push(s.top());
				s.pop();
			}
			s.pop();
			i++;
		
		} else {
			temp.flag = false;
			temp.op = str[i];
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());
				s.pop();
			}
			s.push(temp);
			i++;
		}
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

double cal() {
	double temp1, temp2;
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) {
			s.push(cur);
		} else {
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			if (cur.op == '+') {
				temp.num = temp1 + temp2;
			} else if (cur.op == '-') {
				temp.num = temp1 - temp2;
			}
			else if (cur.op == '*') {
				temp.num = temp1 * temp2;
			}
			else {
				temp.num = temp1 / temp2;
			}
			s.push(temp);
		}
	}
	return s.top().num;
}
int main() {
	op['('] = op[')'] = 0;
	op['+'] = op['-'] = 1;  //�趨�����������ȼ�
	op['*'] = op['/'] = 2;
	getline(cin, str);
	change();   //����׺���ʽת��Ϊ��׺���ʽ
	printf("%.2f\n", cal());    //�����׺���ʽ
	return 0;
	return 0;
}