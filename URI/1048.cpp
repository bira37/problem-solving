#include <stdio.h>
 
int main() {
    float x;
    scanf("%f",&x);
    if(x<=400.00) {
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 15 %%\n",x+x*(15/100.0),x*(15/100.0));
    }
    else if(x<=800.00) {
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 12 %%\n",x+x*(12/100.0),x*(12/100.0));
    }
    else if(x<=1200.00) {
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 10 %%\n",x+x*(10/100.0),x*(10/100.0));
    }
    else if(x<=2000.00) {
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 7 %%\n",x+x*(7/100.0),x*(7/100.0));
    }
    else {
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 4 %%\n",x+x*(4/100.0),x*(4/100.0));
    }
    return 0;
}
