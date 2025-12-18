#include <stdio.h>
#include <stdlib.h>

int soma(int n1, int n2){
    int carry = 0;
    int resultado = 0;
    int base = 1;

    while(n1 > 0 || n2 > 0 || carry > 0){
        int bit1 = n1 % 10;
        int bit2 = n2 % 10;

        int soma = bit1 + bit2 + carry;

        int bit_result = soma % 2;
        carry = soma / 2;

        resultado += bit_result * base;
        base *= 10;

        n1 /= 10;
        n2 /= 10;
    }

    return resultado;
}




int main(){
    int n1=0;
    int n2=0;
    int aux = 0, aux2;
    printf("escreva o primeiro numero binario\n");
    scanf("%d", &n1);
    printf("escreva o segundo numero binario\n");
    scanf("%d", &n2);
        aux = n1+n2;
    for(int i = 0; i < 10; i++){
        aux2 = aux % 10;
        if(aux2 < 0 || aux2 > 2){
            printf("Por favor escreva um numero binario");
            return 1;
        }
        aux /= 10;
    }
    printf("o resultado em binario e %d", soma(n1, n2));

}




