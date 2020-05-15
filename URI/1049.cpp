#include <stdio.h>
#include <string.h>
 
int main() {
    char str[15];
    scanf(" %s",str);
    if(strcmp(str,"vertebrado")==0) {
        scanf(" %s",str);
        if(strcmp(str,"ave")==0) {
            scanf(" %s",str);
            if(strcmp(str,"onivoro")==0) printf("pomba\n");
            else printf("aguia\n");
        }
        else {
            scanf(" %s",str);
            if(strcmp(str,"onivoro")==0) printf("homem\n");
            else printf("vaca\n");
        }
    }
    else {
        scanf(" %s",str);
        if(strcmp(str,"inseto")==0) {
            scanf(" %s",str);
            if(strcmp(str,"herbivoro")==0) printf("lagarta\n");
            else printf("pulga\n");
        }
        else {
            scanf(" %s",str);
            if(strcmp(str,"onivoro")==0) printf("minhoca\n");
            else printf("sanguessuga\n");
        }
    }
    return 0;
}
