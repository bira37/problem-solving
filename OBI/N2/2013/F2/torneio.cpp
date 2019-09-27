#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9+7;
int H[(1LL<<16)+10];
int fat[(1LL<<16)+10];
int inv[(1LL<<16)+10];

inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}

int exp(int a,int n,int m){
	if(n==0)return 1;
	if(n==1)return a;
	int k = exp(a,n/2,m);
	if(n&1){
		return (a*((k*k)%m))%m;
	}
	return (k*k)%m;
}


int32_t main(){
	int n,k;
	cin>>n>>k;
	int pot = (1LL<<n);
	for(int i=1;i<=pot;i++)cin>>H[i];
	fat[0]=1;
	fat[1]=1;
	inv[0]=1;
	inv[1]=1;
	//tenho que pegar 2^(k-1) caras pra perder pra mim
	//os outros caras posso permutar
	for(int i=2;i<=pot;i++){
		fat[i] = (fat[i-1]*i)%M;
		inv[i] = exp(fat[i],M-2,M);
	}
	int menores=0;
	int maiores=0;
	for(int i=2;i<=pot;i++){
		if(H[1]>H[i])menores++;
		else maiores++;
	}
	//para escolher os menores é Cmenores,2^(k-1) - 1;
	int potk = (1LL<<(k-1));
	if(menores < potk - 1 || (maiores==0 && k!=n+1)){
		cout<<0<<endl;
		return 0;
	}
	int C1=mod(fat[menores]*inv[menores-potk+1],M);
	C1 = mod(C1*inv[potk-1],M);
    C1 = mod(C1*fat[potk],M);
    //posso escolher o bloco desse idiota tbm, q pode ser potn/potk;
    C1 = mod(C1*(pot/potk),M);
	//agr bastaria permutar os outros idiotas;
    vector<int> copia;
    for(int i=2;i<=pot;i++){
		copia.push_back(H[i]);
	}
	sort(copia.begin(),copia.end());

	int bloco = potk;
	
	int C2 = 0;
	for(int i=2;i<=pot;i++){
		if(H[i]>H[1]){
			int men_que_eu = lower_bound(copia.begin(),copia.end(),H[i]) - copia.begin() - potk+1;			
		
			//cout<<copia[lower_bound(copia.begin(),copia.end(),H[i])-copia.begin()]<<endl;
			if(men_que_eu<bloco-1)continue;
			
			int atual = mod(fat[men_que_eu]*inv[bloco-1],M);
			atual = mod(atual*inv[men_que_eu - bloco+1],M);
			atual = mod(atual*fat[bloco],M);
			atual = mod(atual*fat[pot - 2*bloco],M);
			C2=mod(C2+atual,M);
		}
	}
	C2= max(C2,1LL);
	C1 = mod(C1*C2,M);
	cout<<C1<<endl;
}