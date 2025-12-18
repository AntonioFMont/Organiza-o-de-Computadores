#include <stdio.h>
#include <stdlib.h>

void somaBin(int A[], int B[], int C[], int tam){
    int i;
    int carry=0;
    for(i=tam-1;i>=0;i--){
        C[i]=A[i]+B[i]+carry;
        carry=C[i]/2;
        C[i]=C[i]%2;
    }
}
void comp2(int V[], int R[], int tam){
    int i;
    int carry=1;
    for(i=0;i<tam;i++){
        R[i]=(V[i]==0)?1:0;
    }
    for(i=tam-1;i>=0;i--){
        R[i]=R[i]+carry;
        carry=R[i]/2;
        R[i]=R[i]%2;
    }
}
void multBin(int A[], int B[], int C[], int n){
    int i,j;
    int tam=2*n;
    int Aext[tam];
    int temp[tam];
    int neg[tam];
    for(i=0;i<tam;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        Aext[i]=A[0];
    }
    for(i=n;i<tam;i++){
        Aext[i]=A[i-n];
    }
    for(i=n-1;i>=0;i--){
        if(B[i]==1){
            for(j=0;j<tam;j++){
                temp[j]=0;
            }
            for(j=0;j<tam-(n-1-i);j++){
                temp[j]=Aext[j+(n-1-i)];
            }
            if(i==0){
                comp2(temp,neg,tam);
                somaBin(C,neg,C,tam);
            }else{
                somaBin(C,temp,C,tam);
            }
        }
    }
}

void lerBits(int V[], int tam, char nome){
    int i,bit;
    for(i=0;i<tam;i++){
        do{
            printf("%c[%d] (0 ou 1): ",nome,i);
            scanf("%d",&bit);
        }while(bit!=0 && bit!=1);
        V[i]=bit;
    }
}
int main(){
    int n,i;
    printf("Digite o numero de bits: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Numero de bits invalido.\n");
        return 1;
    }
    int A[n],B[n],C[2*n];
    printf("Digite A (complemento de 2):\n");
    lerBits(A,n,'A');
    printf("Digite B (complemento de 2):\n");
    lerBits(B,n,'B');
    multBin(A,B,C,n);
    printf("Resultado (2n bits):\n");
    for(i=0;i<2*n;i++){
        printf("%d",C[i]);
    }
    printf("\n");
    return 0;
}
