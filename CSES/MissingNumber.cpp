#include <cstdio>
#include <set>
using namespace std;
int main(){
	int n;
	set<int> conj;
	int aux;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",&aux);
		conj.insert(aux);
	}
	int i;
	for(i=1;i<n;i++){
		if(conj.find(i)==conj.end())break;
	}
	printf("%d",i);
	
	
	return 0;
}