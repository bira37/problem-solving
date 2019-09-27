//se der pra levar x, a capacidade maxima passa a ser 8+x;
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int vet[n];
	int pos0=-1;
	int pos5=-1;
	int ult5=-1;
	for(int i=0;i<n;i++){
		cin>>vet[i];
		if(vet[i]==0 && pos0==-1){
			pos0=i;
		}
		if(vet[i]==5 && pos5==-1){
			pos5=i;
		
		}
		if(vet[i]==5) ult5=i;
	}
	if(pos0==-1 && pos5==-1){
		cout<<-1<<endl;
		return 0;
	}
	if(vet[n-1]>5){
		if(pos0<pos5 && pos0!=-1){
			int aux = vet[n-1];
	vet[n-1] = vet[pos0];
	vet[pos0] = aux;	
		for(int i=0;i<n;i++)cout<<vet[i]<<" ";
		return 0;
		} else if(pos5!=-1){
			int aux = vet[n-1];
	vet[n-1] = vet[pos5];
	vet[pos5] = aux;	
		for(int i=0;i<n;i++)cout<<vet[i]<<" ";
		}
	} else if(pos0!=-1){
	int aux = vet[n-1];
	vet[n-1] = vet[pos0];
	vet[pos0] = aux;	
		for(int i=0;i<n;i++)cout<<vet[i]<<" ";
	} else {
	int aux = vet[n-1];
	vet[n-1] = vet[ult5];
	vet[ult5] = aux;
	for(int i=0;i<n;i++)cout<<vet[i]<<" ";		
	}
	 
	cout<<endl;;
	
	
}