#include <stdio.h>
int somaBin(int A[], int B[], int C[], int N){
    int carry=0;
    int i;
    for (i = N-1; i>=0; i--){
        int soma=A[i]+B[i]+carry;
        C[i]=soma%2;
        carry=soma/2;
    }
    if ((A[0]==B[0]) && (C[0]!=A[0])){
        return -1;
    }
    return 0;
}
void lerBits(int v[], const char *nome, int N){
    int bit;
    int i;
    for (i= 0; i<N; i++) {
        do {
            printf("%s[%d] (0 ou 1): ", nome, i);
            scanf("%d", &bit);
            if (bit!=0 && bit!=1)
                printf("Erro: digite apenas 0 ou 1.\n");
        } while (bit!=0 && bit!=1);
        v[i]=bit;
    }
}
int main(){
    int N;
    printf("Digite o numero de bits:\n");
	scanf("%d", &N);
	if (N<=0){
    	printf("Numero de bits invalido.\n");
    	return 1;
	}
	int A[N], B[N], C[N], i;
    printf("Digite os bits de A (com complemento de 2):\n");
    lerBits(A, "A", N);
    printf("Digite os bits de B (com complemento de 2):\n");
    lerBits(B, "B", N);
    int resultado=somaBin(A, B, C, N);
    if (resultado == -1) {
        printf("Erro: A soma nao e possivel em %d bits.\n", N);
    } else {
        printf("Resultado da soma:\n");
        for (i=0; i<N; i++) {
            printf("%d", C[i]);
        }
        printf("\n");
    }
    return 0;
}