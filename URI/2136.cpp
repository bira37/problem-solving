#include <bits/stdc++.h>
 
using namespace std;

struct times{
	string nome;
	int id;
};

bool cmp(const times & a, const times & b){
	if(a.nome.size() > b.nome.size()) return true;
	else if(a.nome.size() == b.nome.size() && a.id < b.id) return true;
	else return false;
}
 
int main(){
	set<string> v;
	set<string> f;
	vector<times> candidatos;
	int k = 0;
	string nome;
	while(cin >> nome, nome != "FIM"){
		//cout << nome << endl;
		string resposta;
		cin >> resposta;
		if(resposta == "NO"){
			f.insert(nome);
		}
		else if(resposta == "YES"){
			times aux;
			aux.id = k;
			aux.nome = nome;
			v.insert(nome);
			candidatos.push_back(aux);
		}
		k++;
	}
	sort(candidatos.begin(), candidatos.end(),cmp);
	for(set<string>::iterator it = v.begin(); it != v.end(); it++){
		cout << (*it) << endl;
	}
	for(set<string>::iterator it = f.begin(); it != f.end(); it++){
		cout << (*it) << endl;
	}
	cout << endl;
	cout << "Amigo do Habay:" << endl;
	cout << candidatos[0].nome << endl;	

}
