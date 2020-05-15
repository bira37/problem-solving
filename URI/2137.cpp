#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int n;
     while(cin>>n){
         string vet[n];
         for(int i=0; i<n;++i){
             cin >> vet[i];
         }
         sort(vet,vet+n);
         for(int i=0;i<n;++i) cout<< vet[i]<<endl;
     }
 
    return 0;
}
