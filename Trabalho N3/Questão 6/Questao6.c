#include <stdio.h>

// verifica se A >= B (sem sinal)
int maiorOuIgual(int A[], int B[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(A[i] > B[i]) return 1;
        if(A[i] < B[i]) return 0;
    }
    return 1;
}

// subtração binária sem sinal: A - B
int subBin(int A[], int B[], int C[], int n){
    int i;
    int a = 0;   // a = borrow
    for(i = n - 1; i >= 0; i--){
        C[i] = A[i] - B[i] - a;
        if(C[i] < 0){
            C[i] += 2;
            a = 1;
        } else {
            a = 0;
        }
    }

    if(a == 1) return -1;
    return 0;
}
// desloca vetor uma posição para a esquerda
void shiftLeft(int V[], int n){
    int i;
    for(i = 0; i < n - 1; i++){
        V[i] = V[i + 1];
    }
    V[n - 1] = 0;
}
// divisão binária sem sinal
int divBin(int A[], int B[], int C[], int R[], int n){
    int i, j;
    int temp[n];
    // verifica divisão por zero
    for(i = 0; i < n; i++){
        if(B[i] == 1) break;
    }
    if(i == n) return -1;
    // inicializa quociente e resto
    for(i = 0; i < n; i++){
        C[i] = 0;
        R[i] = 0;
    }
    // algoritmo da divisão
    for(i = 0; i < n; i++){
        shiftLeft(R, n);
        R[n - 1] = A[i];
        if(maiorOuIgual(R, B, n)){
            subBin(R, B, temp, n);
            for(j = 0; j < n; j++){
                R[j] = temp[j];
            }
            C[i] = 1;
        }
    }
    return 0;
}
// leitura segura dos bits
void lerBits(int V[], int n, char nome){
    int i, bit;
    for(i = 0; i < n; i++){
        do{
            printf("%c[%d] (0 ou 1): ", nome, i);
            scanf("%d", &bit);
        }while(bit != 0 && bit != 1);
        V[i] = bit;
    }
}
int main(){
    int n, i;
    printf("Digite o numero de bits: ");
    scanf("%d", &n);
    int A[n], B[n], C[n], R[n];
    printf("Digite A (sem sinal):\n");
    lerBits(A, n, 'A');
    printf("Digite B (sem sinal):\n");
    lerBits(B, n, 'B');
    if(divBin(A, B, C, R, n) == -1){
        printf("Erro: divisao por zero!\n");
        return 0;
    }

    printf("Quociente:\n");
    for(i = 0; i < n; i++){
        printf("%d", C[i]);
    }
    printf("\n");

    printf("Resto:\n");
    for(i = 0; i < n; i++){
        printf("%d", R[i]);
    }
    printf("\n");
    return 0;
}