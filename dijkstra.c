#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 100
int n;

int getmin(int *s, int *dist){
    int min=INT_MAX,u;
    for(int i=0;i<n;i++){
        if(s[i]==0 && dist[i]<min){
            min = dist[i];
            u=i;
        }
    }
    return u;
}

void shortpath(int **cost, int *dist, int v){
    int i,j,s[n],u;
    for(i=0;i<n;i++){
        dist[i]=cost[v][i];
        s[i]=0;
    }
    s[v]=1;
    dist[v]=0;

    for(i=1;i<n;i++){
        u=getmin(s,dist);
        s[u]=1;
        for(j=0;j<n;j++){
            if(s[j]!=1 && dist[j]>dist[u]+cost[u][j]){
                dist[j]=dist[u]+cost[u][j];
            }
        }
    }
}

void showd(int *dist){
    for(int i=0;i<n;i++){
        printf("dist[%d]=%d\n",i+1,dist[i]);
    }
}

int main(){
    int i,j,s,d,c,v;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    int **cost = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        cost[i]=malloc(n*sizeof(int));
    int *dist = malloc(n*sizeof(int));

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
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    shortpath(cost,dist,v-1);
    showd(dist);

}