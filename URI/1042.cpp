#include <stdio.h>

int sort(int numA,int numB,int numC,int posA,int posB,int posC) {
    if(numA<numB) {
        if(numA<numC) {
            posA=1;
            if(numB<numC) {
                posB=2;
                posC=3;
            }
            if(numC<numB) {
                posB=3;
                posC=2;
            }
        }
        if(numA>numC) {
            posA=2;
            posB=3;
            posC=1;
        }
    }
    if(numB<numA) {
        if(numB<numC) {
            posB=1;
            if(numA<numC) {
                posA=2;
                posC=3;
            }
            if(numC<numA) {
                posC=2;
                posA=3;
            }
        }
        if(numB>numC) {
            posC=1;
            posB=2;
            posA=3;
        }
    }
	if(posA==1)
		printf("%d\n",numA);
	if(posB==1)
	    printf("%d\n",numB);
	if(posC==1)
	    printf("%d\n",numC);
	if(posA==2)
	    printf("%d\n",numA);
	if(posB==2)
	    printf("%d\n",numB);
	if(posC==2)
	    printf("%d\n",numC);
	if(posA==3)
	    printf("%d\n",numA);
	if(posB==3)
	    printf("%d\n",numB);
	if(posC==3)
	    printf("%d\n",numC);
	return 0;
}
int main() {
    int numA,numB,numC,posA,posB,posC;
    scanf("%d %d %d",&numA,&numB,&numC);
    sort(numA,numB,numC,posA,posB,posC);
    printf("\n%d\n%d\n%d\n",numA,numB,numC);
    return 0;
}
