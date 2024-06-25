#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 100
int w[INT_MAX],n,x[INT_MAX],m;

void show(int a[],int n){
    printf("x = {");
    for(int i=0;i<n-1;i++){
        printf("%d, ", a[i]);
    }
    printf("%d}\n",x[n-1]);
}


void sumofsub(int s, int k, int r){

    x[k]=1;
    if((s+w[k])==m){
        show(x,n);
    }
    else if((s+w[k]+w[k+1])<=m){
        sumofsub(s+w[k],k+1,r-w[k]);
    }
    
    if((s+r-w[k])>=m && (s+w[k+1])<=m){
        x[k]=0;
        sumofsub(s,k+1,r-w[k]);
    }
}

int main(){
    int i,s,r;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the set of weights: ");
    for(i=0;i<n;i++){
        scanf("%d", &w[i]);
        x[i]=0;
    }
    printf("Enter the sum value: ");
    scanf("%d", &m);

    r=0;
    for(i=0;i<n;i++){
        r=r+w[i];
    }
    s=0;
    sumofsub(s,0,r);

}