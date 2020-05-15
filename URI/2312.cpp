#include <bits/stdc++.h>
 
using namespace std;

struct times{
	string nome;
	int ouro,prata,bronze;
};

bool cmp(const times & a, const times & b){
	if(a.ouro > b.ouro) return true;
	else if(a.ouro == b.ouro && a.prata > b.prata) return true;
	else if(a.ouro == b.ouro && a.prata == b.prata && a.bronze > b.bronze) return true;
	else if(a.ouro == b.ouro && a.prata == b.prata && a.bronze == b.bronze && a.nome < b.nome) return true;
	else return false;
}
 
int main(){
	int n;
	cin >> n;
	times time[n];
	for(int i=0; i<n; i++){
		cin >> time[i].nome >> time[i].ouro >> time[i].prata >> time[i].bronze;
	}
	
	sort(time, time+n, cmp);
	for(int i=0; i<n; i++){
		cout << time[i].nome << " " << time[i].ouro <<  " " <<  time[i].prata << " " << time[i].bronze << endl;
	}

}
