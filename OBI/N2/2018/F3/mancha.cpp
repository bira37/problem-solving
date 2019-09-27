#include <bits/stdc++.h>
using namespace std;

int n;
string s[1010];
int checkl(int l){
	//checar linha
	int first = n;
	int last = 0;
	for(int i=0;i<n;i++){
		if(s[l][i]=='*'){
			first = i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(s[l][i]=='*'){
			last = i;
			break;
		}
	}
	for(int i = first;i<last && i<n;i++){
		if(s[l][i]=='.')return false;
	}

	return true;
}

int checkc(int c){
	//checar coluna
	int first = n;
	int last = 0;
	for(int i=0;i<n;i++){
		if(s[i][c]=='*'){
			first = i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(s[i][c]=='*'){
			last = i;
			break;
		}
	}
	for(int i = first;i<last && i<n;i++){
		if(s[i][c]=='.')return false;
	}

	return true;
}

int main(){
    // A resposta é sim apenas se entre dois * nao tiver
    // nenhum '.';
    // Entao basta pegar as extremidades esquerda e direita de cada linha e coluna
    // e checar se entre eles tem algum '.' :)
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	int flag = true;

	for(int i=0;i<n;i++){
		if(!checkl(i)){
			flag = false;
		}
		if(!checkc(i)){
			flag = false;
		}

		}
		if(flag){
			cout<<"S"<<endl;
		}else cout<<"N"<<endl;
}
