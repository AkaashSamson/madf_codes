#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 100
int L[256]={-1};
int m,n;

int lastindex(char *A, char c){
    int i;
    for(i=m-1;i>=0;i--){
        if(A[i]==c){
            return i;
        }
            
    }
    return -1;
}

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void lastoccurence(char *P, char *E){
    int i;
    for(i=0;i<strlen(E);i++){
        L[(int)E[i]]=lastindex(P,E[i]);
    }
    
}

int BMP(char *T,char *P, char *E){
    lastoccurence(P,E);
    int i=m-1,j=m-1,l;
    do{
        if(T[i]==P[j]){
            if(j==0)
                return i;
            else{
                i--;
                j--;
            }
        }

        else{
            l=L[(int)T[i]];
            i=i+m-min(l+1,j);
            j=m-1;
        }
        
    }while(i<n);

    return -1;
}

int main(){
    char T[INT_MAX],P[INT_MAX],E[INT_MAX];
    int i,k;
    char item;
    printf("Enter the Text: ");
    scanf("%s", T);
    printf("Enter the Pattern: ");
    scanf("%s", P);
    printf("Enter the number of alphabets: ");
    scanf("%d", &k);
    printf("Enter the alphabets:\n");
    for(i=0;i<k;i++){
        printf("Enter the alphabet: ");
        scanf(" %c", &item);
        E[i]=item;
    }
    // for(i=0;i<k;i++){
    //     printf("%c ", E[i]);
    // }

    n=strlen(T);
    m=strlen(P);
    i=BMP(T,P,E);
    if(i!=-1)
        printf("Pattern found at index: %d\n", i);
    else
        printf("Pattern not found\n");

}