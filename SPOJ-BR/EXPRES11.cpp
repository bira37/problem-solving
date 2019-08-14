#include <iostream>
#include <stack>
#include <string>

using namespace std;

void convert(char *x){
	if(*x == ')') *x = '(';
	if(*x == ']') *x = '[';
	if(*x == '}') *x = '{';
}

int main() {
	int t;
	cin >>t;
	for(int j=0; j < t; j++){
		int flag=1;
		string exp;
		stack<char> pil;
		cin >> exp;
		for(int i=0;i< exp.length() && flag;i++){
			//cout << exp[i]<< endl;
			if(exp[i]=='(' || exp[i]=='[' || exp[i]== '{') pil.push(exp[i]);
			else {
				convert(&exp[i]);
				if(pil.empty() || pil.top() != exp[i]) flag=0;
				else pil.pop();
			}
		}
		if(!flag || !pil.empty()) cout << "N" << endl;
		else cout << "S" << endl;
	}
	return 0;
}
