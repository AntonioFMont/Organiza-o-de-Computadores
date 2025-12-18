#include <stdio.h>

int compara(int A[], int B[], int N){
    int i;
    for(i=0;i<N;i++){
        if(A[i]>B[i]) return 1;
        if(A[i]<B[i]) return -1;
    }
    return 0;
}
int subBinSemSinal(int A[], int B[], int C[], int N){
    int a=0;
    int i;
    if(compara(A,B,N)<0){
        return -1;
    }
    for(i=N-1;i>=0;i--){
        int x=A[i]-a;
        int y=B[i];
        if(x<y){
            C[i]=x+2-y;
            a=1;
        }else{
            C[i]=x-y;
            a=0;
        }
    }
    return 0;
}
void lerBits(int v[], const char *nome, int N){
    int bit;
    int i;
    for(i=0;i<N;i++){
        do{
            printf("%s[%d] (0 ou 1): ",nome,i);
            scanf("%d",&bit);
        }while(bit!=0 && bit!=1);
        v[i]=bit;
    }
}
int main(){
    int N;
    int i;
    printf("Digite o numero de bits:\n");
    scanf("%d",&N);
    if(N<=0){
        printf("Numero de bits invalido.\n");
        return 1;
    }
    int A[N],B[N],C[N];
    printf("Digite A (sem sinal):\n");
    lerBits(A,"A",N);
    printf("Digite B (sem sinal):\n");
    lerBits(B,"B",N);
    if(subBinSemSinal(A,B,C,N)==-1){
        printf("Erro: Subtracao nao possivel (A < B).\n");
    }else{
        printf("Resultado A - B:\n");
        for(i=0;i<N;i++){
            printf("%d",C[i]);
        }
        printf("\n");
    }
    return 0;
}