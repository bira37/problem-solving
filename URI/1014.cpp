#include <stdio.h>
 
int main() {
    int km;
    double gas;
    scanf("%d\n%lf",&km,&gas);
    printf("%.3f km/l\n",km/gas);
    return 0;
}
