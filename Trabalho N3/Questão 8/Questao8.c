#include <stdio.h>

// converte 4 bits BCD para decimal
int bcdParaDec(int V[]){
    int val;
    val = V[0]*8 + V[1]*4 + V[2]*2 + V[3];
    if(val > 9) return -1; // BCD invalido
    return val;
}
// converte decimal (0 a 9) para BCD
void decParaBcd(int v, int V[]){
    V[0] = (v >> 3) & 1;
    V[1] = (v >> 2) & 1;
    V[2] = (v >> 1) & 1;
    V[3] = v & 1;
}
// subtração BCD sem sinal
int subBCD(int A[], int B[], int C[], int n){
    int i;
    int a = 0;
    int da, db, r;
    for(i = n - 1; i >= 0; i--){
        da = bcdParaDec(&A[4*i]);
        db = bcdParaDec(&B[4*i]);
        if(da == -1 || db == -1) return -1;
        r = da - db - a;
        if(r < 0){
            r += 10;
            a = 1;
        } else {
            a = 0;
        }
        decParaBcd(r, &C[4*i]);
    }
    if(a == 1) return -1; // A < B

    return 0;
}
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
    printf("Digite a quantidade de digitos decimais: ");
    scanf("%d", &n);
    int A[4*n], B[4*n], C[4*n];
    printf("Digite A em BCD (%d bits):\n", 4*n);
    lerBits(A, 4*n, 'A');
    printf("Digite B em BCD (%d bits):\n", 4*n);
    lerBits(B, 4*n, 'B');
    if(subBCD(A, B, C, n) == -1){
        printf("Erro: subtracao nao possivel ou BCD invalido.\n");
        return 0;
    }
    printf("Resultado A - B (BCD):\n");
    for(i = 0; i < 4*n; i++){
        printf("%d", C[i]);
    }
    printf("\n");
    return 0;
}