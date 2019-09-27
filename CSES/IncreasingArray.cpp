#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	vector<int> vet;
	int aux;
	long long somaIni=0;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>aux;
		somaIni+=aux;
		vet.push_back(aux);
	}
	long long somaF=0;
	for(int i=1;i<n;i++){
		if(vet[i]<vet[i-1]){
			vet[i]=vet[i-1];
		}
		somaF+=vet[i];
	}
//	for(int i=0;i<n;i++) cout<<vet[i]<<" ";
//	cout<<endl;
	somaF+=vet[0];
	long long a = somaF-somaIni;
	cout<<a<<endl;
	return 0;
}