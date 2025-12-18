#include <stdio.h>
void soma4Bits(int A[], int B[], int C[], int *carry){
    int i;
    int soma, c = 0;
    for(i = 3; i >= 0; i--){
        soma = A[i] + B[i] + c;
        C[i] = soma % 2;
        c = soma / 2;
    }
    *carry = c;
}
// verifica se os 4 bits > 9
int maiorQue9(int V[]){
    if(V[0] == 1) return 1;
    if(V[1] == 1 && V[2] == 1) return 1;
    return 0;
}
// soma BCD
void somaBCD(int A[], int B[], int C[], int n){
    int i, j;
    int carry = 0;
    int nibA[4], nibB[4], nibC[4];
    int seis[4] = {0,1,1,0};
    // zera C
    for(i = 0; i < 4*n + 4; i++){
        C[i] = 0;
    }
    // soma dígito a dígito (da direita para a esquerda)
    for(i = n - 1; i >= 0; i--){
        for(j = 0; j < 4; j++){
            nibA[j] = A[4*i + j];
            nibB[j] = B[4*i + j];
        }
        soma4Bits(nibA, nibB, nibC, &carry);
        // correção BCD
        if(carry == 1 || maiorQue9(nibC)){
            soma4Bits(nibC, seis, nibC, &carry);
        }
        for(j = 0; j < 4; j++){
            C[4*i + j + 4] = nibC[j];
        }
    }
    // carry final
    if(carry == 1){
        C[3] = 1;
    }
}
// leitura segura
void lerBits(int V[], int tam, char nome){
    int i, bit;
    for(i = 0; i < tam; i++){
        do{
            printf("%c[%d] (0 ou 1): ", nome, i);
            scanf("%d", &bit);
        }while(bit != 0 && bit != 1);
        V[i] = bit;
    }
}
int main(){
    int n, i;
    printf("Digite o numero de digitos BCD: ");
    scanf("%d", &n);
    int A[4*n], B[4*n], C[4*n + 4];
    printf("Digite A (BCD):\n");
    lerBits(A, 4*n, 'A');
    printf("Digite B (BCD):\n");
    lerBits(B, 4*n, 'B');
    somaBCD(A, B, C, n);
    printf("Resultado (BCD):\n");
    for(i = 0; i < 4*n + 4; i++){
        printf("%d", C[i]);
    }
    printf("\n");
    return 0;
}