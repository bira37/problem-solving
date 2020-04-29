#include <stdio.h>
#define pi 3.14159

int main() {
    long long int raio;
    double soma;
    scanf("%lld",&raio);
    soma=(4.0/3)*pi*(raio*raio*raio);
    printf("VOLUME = %.3lf\n",soma);
    return 0;
}
