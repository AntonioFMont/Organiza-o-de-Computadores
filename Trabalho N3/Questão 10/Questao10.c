#include <stdio.h>
// soma binaria (complemento de 2)
int somaBin(int A[], int B[], int C[], int tam){
    int i;
    int carry = 0;
    int s;
    for(i = tam - 1; i >= 0; i--){
        s = A[i] + B[i] + carry;
        C[i] = s % 2;
        carry = s / 2;
    }
    if(A[0] == B[0] && C[0] != A[0]){
        return -1;
    }
    return 0;
}
// complemento de 2
void comp2(int B[], int Bc[], int tam){
    int i;
    int carry = 1;
    for(i = 0; i < tam; i++){
        Bc[i] = (B[i] == 0) ? 1 : 0;
    }
    for(i = tam - 1; i >= 0; i--){
        if(carry == 0) break;
        if(Bc[i] == 0){
            Bc[i] = 1;
            carry = 0;
        } else {
            Bc[i] = 0;
        }
    }
}
// converte 4 bits para hexadecimal
char binParaHex(int V[]){
    int val;
    val = V[0]*8 + V[1]*4 + V[2]*2 + V[3];
    if(val < 10) return '0' + val;
    return 'A' + (val - 10);
}
// subtracao binaria -> hexadecimal com sinal
int subBin(int A[], int B[], int C[], int tam){
    int Bc[tam];
    comp2(B, Bc, tam);
    return somaBin(A, Bc, C, tam);
}
// leitura de bits
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
    printf("Digite o numero de digitos hexadecimais: ");
    scanf("%d", &n);
    int A[4*n], B[4*n], C[4*n];
    printf("Digite A em binario (%d bits):\n", 4*n);
    lerBits(A, 4*n, 'A');
    printf("Digite B em binario (%d bits):\n", 4*n);
    lerBits(B, 4*n, 'B');
    if(subBin(A, B, C, 4*n) == -1){
        printf("Erro na subtracao.\n");
        return 0;
    }
    printf("Resultado em hexadecimal:\n");
    for(i = 0; i < 4*n; i += 4){
        printf("%c", binParaHex(&C[i]));
    }
    printf("\n");
    return 0;
}