#include<stdio.h>

int palindroma(char cad[], int n, int i);

int main(){
    char cad[10]; int len;
    printf("Ingrese cadena");
    scanf("%s",&cad);
    len=strlen(cad);
    if(palindroma(cad,len-1,0))
        printf("SIIIIII");
    return 0;
}

int palindroma(char cad[], int n, int i){
    if(i>n)
        return 1;
    else
        if(cad[i] == cad [n - i])
            return palindroma(cad,n,i+1);
        else
            return 0;
}
