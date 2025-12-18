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
void complemento2(int B[], int Bcomp[], int N){
    int i;
	for (i=0; i<N; i++){
	if (B[i]==0) {
    	Bcomp[i]=1;
	} 	
	else {
    	Bcomp[i]=0;
	}

    }
    int carry=1;
    for (i = N-1; i>=0; i--){
        int soma=Bcomp[i]+carry;
        Bcomp[i]=soma%2;
        carry=soma/2;
    }
}
int subBin(int A[], int B[], int C[], int N){
    int Bcomp[N];
    complemento2(B, Bcomp, N);
    return somaBin(A, Bcomp, C, N);
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
    int A[N], B[N], C[N], i;
    printf("Digite A (com complemento de 2):\n");
    lerBits(A, "A", N);
    printf("Digite B (com complemento de 2):\n");
    lerBits(B, "B", N);
    if (subBin(A, B, C, N) == -1){
        printf("Erro: Subtracao nao possivel em %d bits.\n", N);
    } else {
        printf("Resultado A - B:\n");
        for (i=0; i<N; i++) {
            printf("%d", C[i]);
        }
        printf("\n");
    }

    return 0;
}