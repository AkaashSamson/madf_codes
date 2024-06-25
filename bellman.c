#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 100000
int n,g;
struct edge{
    int s;
    int d;
    int cst;
};

int incoming(struct edge *E, int u){
    for(int i=0;i<g;i++){
        if(E[i].d==u)
            return 1;
    }
    return 0;
}

void bellman(struct edge *E, int **cost, int v, int *dist){
    int i,j,u;
    for(i=0;i<n;i++)
        dist[i]=cost[v][i];
    dist[v]=0;

    for(j=1;j<n;j++){
        for(u=0;u<n;u++){
            if(u!=v && (incoming(E,u))){
                for(i=0;i<n;i++){
                    if(cost[i][u]!=INT_MAX){
                        if(dist[u]>dist[i]+cost[i][u])
                            dist[u]=dist[i]+cost[i][u];
                    }
                }
            }
        }
    }
}

void showd(int *dist){
    for(int i=0;i<n;i++){
        printf("dist[%d] - %d\n", i+1,dist[i]);
    }
}
int main(){
    struct edge *E;
    int i,j,maxe, src, dst, prc,v,*dist;

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    
    maxe = (n*(n-1))/2;
    int **cost = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    cost[i]=malloc(n*sizeof(int));

    dist = malloc(n*sizeof(int));

    E = (struct edge*)malloc(n*sizeof(struct edge));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cost[i][j]=INT_MAX;
        }
    }
    g=0;
    printf("Enter the source dest and cost(-1 -1 to exit): \n");
    for(i=0;i<maxe;i++){
        scanf("%d %d %d", &src,&dst,&prc);
        if(src==-1 && dst==-1)
            break;
        cost[src-1][dst-1]=prc;
        E[i].s=src-1;
        E[i].d=dst-1;
        E[i].cst=prc;
        g++; //counter for number of edges
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    bellman(E,cost,v-1,dist);
    showd(dist);
}


