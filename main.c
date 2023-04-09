#include <stdio.h> 
#include <stdlib.h>
#include "input.h"

void func(int *p, int *v);

int main(){

    char str[] = "Ponteiros";
    char *p = str;

    /* PRINT ADDR ARRAY */
    printf("Endereço do array de caracteres: %p\n", p);
    
    /* PRINT ADDR 'n' */
    char n = 'n';
    char *ptrN = p;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if(ptrN[i] == n){
            ptrN += i;
            break;
        }
    }
    
    printf("Endereço do caracter: %p\n", ptrN);

    char charT_indexed = p[3];
    printf("Endereço do array de caracteres (indexação): %c\n", charT_indexed);

    char charT_arithmetic = *(p + 3);
    printf("Endereço do array de caracteres (aritmética de ponteiros): %c\n", charT_arithmetic);

    /* LOOP INDEXED */

    for (int i = 0; str[i] != '\0'; i++) //Também é possível usar strlen(p)
    {
        printf("%c", p[i]);
    }

    /* LOOP ARITHMETIC */
    
    printf("\n");
    for (p = str; *p != '\0'; p++) //Assumir p como o primeiro endereço de str
    {
        printf("%c", *p);
    }
    printf("\n");

    //Manipulação de ponteiros - 2

    int v[] = {23, 6, 24, 2};
    int k[4] = {0};
    int *ptr = k; //Endereço [0] de k

    func(v, ptr);
    for(ptr = k; ptr < k+4; ptr++)
    printf("%d\n", *ptr);
    //Output -> 6, 2, 24, 0
    return EXIT_SUCCESS;
}

//Manipulação de ponteiros - 2

void func(int *p, int *v){

    p++;
    *v = p[0];
    v++;
    *(v+1) = p[1];
    v[0] = *(p+2);

}