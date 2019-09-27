#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
vector<int> pilha;
 
int lis(){
	
//	vector<int> pilha;
	vector<int>::iterator it;
	for(int i=0;i<(int)v.size();i++){
		it = lower_bound(pilha.begin(),pilha.end(),v[i]);
		if(it==pilha.end()) pilha.push_back(v[i]);
		else *it = v[i];
	}
	
	return pilha.size();
}
 
 
int main() {
    int n, soma=0;
    cin >> n;
//    vector<int> v;
    for (int i = 0; i < n; i++){
		cin>>soma;
		v.push_back(soma);
	}
    cout<<lis()<<endl;
}