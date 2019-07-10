#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	deque<char> q;
	int n;
	string x;
	cin >> n;
	cin >> x;
 
	if(x.size()%2){	
		for(int i=0; i<x.size(); i+=2){
			q.push_back(x[i]);
			if(i+1 < x.size()) q.push_front(x[i+1]);
		}
	}
	else {
		for(int i=0; i<x.size(); i+=2){
			q.push_front(x[i]);
			if(i+1 < x.size()) q.push_back(x[i+1]);
		}
	}
 
	while(!q.empty()){
		cout << q.front();
		q.pop_front();
	}
	cout << endl;	 
}
