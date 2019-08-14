#include <iostream>

using namespace std;

int bsearch(int *A, int x, int ini, int fim){
	int meio = (ini+fim)/2;
	if(fim < ini ) return 1;
	if(A[meio]==x) return 0;
	else if(x < A[meio]) return bsearch(A,x,ini,meio-1);
	else return bsearch(A,x,meio+1,fim);
}
	
int main(){
	int a,b;
	while(cin >> a >> b, a+b!=0){
		int A[a],B[b];
		int countA=0, countB=0,ant=0;
		for(int i=0; i < a; i++) cin >> A[i];
		for(int i=0; i < b; i++) cin >> B[i];
		for(int i=0; i < a; i++){
			if(ant!=A[i]){
				countA+= bsearch(B,A[i],0,b-1);
				ant=A[i];
			}
		}
		ant=0;
		for(int i=0; i < b; i++){
			if(ant!=B[i]){
				countB += bsearch(A,B[i],0,a-1);
				ant=B[i];
			}
		}
		if(countA < countB) cout << countA << endl;
		else cout << countB << endl;
	}
}

