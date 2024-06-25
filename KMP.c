#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 100
int m,n;
int F[INT_MAX];

void Failurefunct(char *P){
    int i,j;
    F[0]=0;
    i=1;
    j=0;
    while(i<m){
        if(P[i]==P[j]){
            F[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=F[j-1];
        }

        else{
            F[i]=0;
            i++;
        }
    }
}

int KMP(char *T, char *P){
    int i=0,j=0;
    Failurefunct(P);
    while(i<n){
        if(T[i]==P[j]){
            if(j==m-1)
                return i-m+1;
            else{
                j++;
                i++;
            }
        }

        else if(j>0)
            j=F[j-1];

        else{
            i++;
        }
    }

    return -1;
}

int main(){
    char T[INT_MAX],P[INT_MAX];
    int i,k;
    char item;
    printf("Enter the Text: ");
    scanf("%s", T);
    printf("Enter the Pattern: ");
    scanf("%s", P);
    n=strlen(T);
    m=strlen(P);
    i=KMP(T,P);
    if(i!=-1)
        printf("Pattern found at index: %d\n", i);
    else
        printf("Pattern not found\n");

}