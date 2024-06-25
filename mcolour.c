
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 100
int G[INT_MAX][INT_MAX],x[INT_MAX],n,m,sol=0;

void show(int a[],int n){
    for(int i=1;i<=n;i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void nextvalue(int k){
    int j;
    do{
    x[k]=(x[k]+1)%(m+1);
    if(x[k]==0)
        return;
    for(j=1;j<=n;j++){
        if(G[j][k]!=0 && x[j]==x[k]){
        //printf("%d %d %d %d\n", j, k, x[j], x[k]);
            break;
        }
    }
    if(j==n+1)
        return;

    }while(1);
}

void mcolour(int k){
    
    do{
    nextvalue(k);
    if(x[k]==0)
        return;
    if(k==n){
        sol=1;
        show(x,n);
    }
    else 
        mcolour(k+1);
    }while(1);
    
}





int dege(){
    int max=0,cnt=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(G[i][j])
                cnt++;
        }
        if(cnt>max)
            max=cnt;
    }
    return max;
}

int main(){
    int i,j,maxe,s,d,maxclr;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
        G[i][j]=0;
        x[i]=0;
    }
    }

    maxe = (n*(n-1))/2;
    printf("Enter the Edge(-1 -1 to exit): \n");
    for(i=0;i<maxe;i++){
        scanf("%d %d", &s,&d);
        if(s==-1 && d==-1)
            break;
        G[s][d]=1;
        G[d][s]=1;
    }

    maxclr=dege()+1;
    sol=0;
    for(m=2;m<=maxclr;m++){
        mcolour(1);
        if(sol==1){
            printf("Chromatic number: %d", m);
            break;
            }
    }
}