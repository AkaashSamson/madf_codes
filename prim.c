#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 100
int n;

void findmin(int *u, int *v, int **cost){
    int min = INT_MAX,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                *u=i;
                *v=j;
            }
        }
    }
}

int prims(int **cost, int **T){
    int mincost,k,l,j,near[n],min,u;
    findmin(&k,&l,cost);
    //printf("%d %d\n",k+1,l+1);
    for(j=0;j<n;j++){
        if(cost[j][k]<cost[j][l])
            near[j]=k;
        else
            near[j]=l;
    }
    //printf("test\n");
    T[0][0]=k;
    T[0][1]=l;
    printf("test\n");
    mincost=cost[k][l];
    near[k]=-1;
    near[l]=-1;

    for(j=1;j<n-1;j++){
        min = INT_MAX;
        for(l=0;l<n;l++){
            if(near[l]!=-1 && cost[l][near[l]]<min){
                min=cost[l][near[l]];
                u=l;
            }
        }

        mincost=mincost+cost[u][near[u]];
        T[j][0] = u;
        T[j][1] = near[u];
        near[u]= -1;

        for(k=0;k<n;k++){
            if(near[k]!= -1 && cost[k][near[k]]>cost[k][u])
                near[k]=u;
        }
    }
    return mincost;
}

void showt(int **T){
    for(int i=0;i<n-1;i++){
        printf("%d %d\n", T[i][0]+1, T[i][1]+1);
    }
}

int main(){
    int i,j,s,d,c,mincost;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    int **cost = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        cost[i]=malloc(n*sizeof(int));
    int **T = malloc((n-1)*sizeof(int*));
    for(i=0;i<n-1;i++)
        T[i]=malloc(2*sizeof(int));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cost[i][j]=INT_MAX;
        }
    }

    int maxe=(n*(n-1))/2;
    printf("Enter the edges(-1 -1 to exit): \n");
    for(i=0;i<maxe;i++){
        scanf("%d %d %d", &s, &d, &c);
        if(s==-1 && d==-1)
            break;
        cost[s-1][d-1]=c;
        cost[d-1][s-1]=c;
    }
    
   mincost=prims(cost,T);
   printf("Mincost=%d\n", mincost);
   showt(T);

}