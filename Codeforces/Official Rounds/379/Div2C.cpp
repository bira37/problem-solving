#include <bits/stdc++.h>
 
using namespace std;
 
struct spell{
	unsigned long long mana,att;
};
 
bool cmp(const spell & a, const spell & b){
	return a.mana < b.mana;
}
 
int main(){
	long long n,limite,tempo,f,s;
	cin >> n >> f >> s;
	cin >> tempo >> limite;
	spell first[f];
	spell second[s];
	for(long long i=0; i<f; i++){
		cin >> first[i].att;
	}
	for(long long i=0; i<f; i++){
		cin >> first[i].mana;
	}
	for(long long i=0; i<s; i++){
		cin >> second[i].att;
	}
	for(long long i=0; i<s; i++){
		cin >> second[i].mana;
	}
	sort(first, first+f, cmp);
	long long c2 = s-1;
	unsigned long long menor = n*tempo;
	for(int i=0; i<f; i++){
		while(c2>=0 && first[i].mana + second[c2].mana > limite){
			c2--;
		}
		if(c2>=0){
			unsigned long long aux = (n-second[c2].att)*first[i].att;
			if(aux < menor) menor = aux;
		}
	}
	for(int i=0; i<f; i++){
		if(first[i].mana > limite) break;
		unsigned long long aux = n*first[i].att;
		if(aux < menor) menor = aux;
	}
	for(int i=0; i<s; i++){
		if(second[i].mana > limite) break;
		unsigned long long aux = (n-second[i].att)*tempo;
		if(aux < menor) menor = aux;
	}
	cout << menor << endl;
}
