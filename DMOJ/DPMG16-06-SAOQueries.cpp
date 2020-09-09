#include <stdio.h>
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#define min(a,b) (a < b ? a : b)
#define sqr 524



int f[521][262144] = {0};
int ans[520][520] = {0};
int cnt[262144] = {0};
int v[262144] = {0};
int lastq[262144] = {0};
int sum[262144];

long long acc;

int main(){
	int n,q;
	scanf("%d%d", &n,&q);
	sum[0] = 0;
	for(int i=0; i<n; ++i){
	  scanf("%d", v+i);
	  sum[i+1] = (i+1)*(i+1) - i*i;
	}
	int nb = (n+sqr-1)/sqr;
	for(int i=0; i<nb; i++){
	  int lim4 = min(n, (i+1)*sqr);
	  acc = 0;
	  for(int j=lim4-1; j>=0; --j){
	    f[i+1][v[j]]++;
	    int lb = j/sqr;
	    cnt[v[j]]++;
	    acc += sum[cnt[v[j]]];
	    ans[lb][i] = acc;
	  }
	  for(int j=lim4-1; j>=0; --j){
	    cnt[v[j]] = 0;
	  }
	}
	
  int last = 0;
  while(q--){
    int l,r;
    scanf("%d%d", &l,&r);
	  
    l = l^last;
    r = r^last;
    
    int lb = l/sqr + 1;
    int rb = r/sqr - 1;
    
    lb -= (l % sqr == 0);
    rb += (r % sqr == sqr-1);
    
    acc = 0;
    
    int mul = 0;
    int rhs = 1;
    
    if(lb-1 == rb+1) rhs = -1; 
    
    if(lb <= rb){
      acc = ans[lb][rb];
      mul = 1;
    }
    
    int lim1 = min(lb*sqr-1, min(r, n-1));
    int lim2 = rhs*min(r, n-1);
    
    for(int i=lim1; i >= l; --i){
      cnt[v[i]]++;
	    acc += sum[cnt[v[i]] + mul*(f[rb+1][v[i]] - f[lb][v[i]])];
    }
    for(int i = lim2, fim =(rb+1)*sqr; i >= fim; --i){
      cnt[v[i]]++;
	    acc += sum[cnt[v[i]] + mul*(f[rb+1][v[i]] - f[lb][v[i]])];
    }
    
    for(int i=lim1; i >= l; --i){
      cnt[v[i]] = 0;
    }
    for(int i = lim2, fim =(rb+1)*sqr; i >= fim; --i){
      cnt[v[i]] = 0;
    }
    
    acc %= 262144;
	  printf("%lld\n", acc);
	  last = acc;
	}
}
