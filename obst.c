//code for obst given p and q

#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 1000000



int findmin(int **c, int **r, int i, int j){
    int min = INT_MAX,l;
    for(int m=r[i][j-1]; m<=r[i+1][j];m++){
        if((c[i][m-1]+c[m][j])<min){
            min = c[i][m-1] + c[m][j];
            l = m;
        }
    }
    return l;
}

void label(int i){
    switch(i){
        case 1: printf("char ");
                break;
        case 2: printf("float ");
                break;
        case 3: printf("for ");
                break;
        case 4: printf("struct ");
                break;
        case 5: printf("union ");
                break;
    }
}

void preorder(int **r, int i, int j){
    int k;
    if(i<j){
        k = r[i][j];
        label(k);
        preorder(r,i,k-1);
        preorder(r,k,j);
    }
}

void obst(int *p, int *q, int n){
    int i,m,j,k;
    int **c = malloc((n+1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        c[i] = malloc((n+1) * sizeof(int));
    int **w = malloc((n+1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        w[i] = malloc((n+1) * sizeof(int));
    int **r = malloc((n+1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        r[i] = malloc((n+1) * sizeof(int));
    
    for(i=0;i<n;i++){
        c[i][i] = 0;
        w[i][i] = q[i];
        r[i][i] = 0;
        printf("c[%d][%d] = %d\n",i,i,c[i][i]);
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] = i+1;
        printf("c[%d][%d] = %d\n",i,i+1,c[i][i+1]);
    }

    c[n][n] = 0;
    w[n][n] = q[n];
    r[n][n] = 0;

    for(m=2;m<=n;m++){
        for(i=0;i<=n-m;i++){
            j = i+m;
            w[i][j] = w[i][j-1] + p[j]+q[j];
            k = findmin(c,r,i,j);
            c[i][j]=c[i][k-1] + c[k][j] + w[i][j];
            printf("c[%d][%d] = %d\n",i,j,c[i][j]);
            r[i][j] = k;
            }
   
    }
    printf("total cost = %d\n",c[0][n]);
    printf("root = %d\n",r[0][n]);
    printf("Total weight = %d\n",w[0][n]);
    preorder(r,0,n);

}

int main(){
    int n=5, p[]={-1,5,6,3,5,4}, q[]={6,4,5,6,5,4};
    obst(p,q,n);
    return 0;
}