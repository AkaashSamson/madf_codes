//kruskals minimum cost spanning tree

#include<stdio.h>
#include<stdlib.h>

struct edge{
    int src;
    int dest;
    int cost;
};

void bubblesort(struct edge *E, int n){
    int i,j,xch;
    struct edge tmp;

    for(i=n-1;i>=0;i--){
        xch = 0;
        for(j=0;j<i+1;j++){
            if(E[j].cost>E[j+1].cost){
                tmp.cost = E[j].cost;
                tmp.src = E[j].src;
                tmp.dest = E[j].dest;

                E[j].cost = E[j+1].cost;
                E[j].src = E[j+1].src;
                E[j].dest = E[j+1].dest;

                E[j+1].cost = tmp.cost;
                E[j+1].src = tmp.src;
                E[j+1].dest = tmp.dest;

                xch++;
            }
        }
        if(xch==0)
            break;
    }
}

void enter(struct edge *E, int s, int d, int c, int i){
    E[i].cost = c;
    E[i].src= s-1;
    E[i].dest= d-1;
}

void display(struct edge *E, int n){
    for(int j=0;j<n;j++){
        printf("%d %d %d\n",E[j].src+1, E[j].dest+1, E[j].cost);
    }
    printf("\n");
}

int find(int i, int *p){
    while(p[i]!=-1){
        i=p[i];
    }
    return i;
}

void unionn(int i, int j, int *p){
    p[i]=j;
}

void kruskal(struct edge *E, int n, int g, int **t){
int a,i,j,k,u,v,parent[n],mincost=0;
for(int i=0;i<n;i++){
    parent[i]=-1;
}
i=0;
a=0;
while(i<g && a<n-1){
u=E[i].src;
v=E[i].dest;
j=find(u,parent);
k=find(v,parent);
if(j!=k){
    mincost = mincost+E[i].cost;
    t[a][0] = u;
    t[a++][1] = v;
    unionn(j,k,parent);
}
i++;
}
for(i=0;i<n-1;i++){
    printf("%d %d\n", t[i][0]+1, t[i][1]+1);
}
printf("Mincost: %d", mincost);
}

int main(){
    int i,j,n,g;
    struct edge *E;
    // printf("Enter the no. of vertices: ");
    // scanf("%d", &n);
    // printf("Enter the no. of edges: ");
    // scanf("%d", &g);
    n=8;
    g=15;
    E = (struct edge*)malloc(g*sizeof(struct edge));
    i=0;
   // printf("Enter the edges as source dest and cost seperated by space");
    // for(j=0;j<g;j++){
    //     scanf("%d %d %d",&E[j].src, &E[j].dest, &E[j].cost);
    // }

    int **t = malloc((n-1)*sizeof(int*));
    for(j=0;j<n-1;j++)
        t[j] = malloc(2*sizeof(int));
    

    enter(E,1,2,2,i++);
    enter(E,1,4,2,i++);
    enter(E,1,5,3,i++);
    enter(E,2,3,4,i++);
    enter(E,2,4,1,i++);
    enter(E,2,5,2,i++);
    enter(E,3,5,3,i++);
    enter(E,3,6,1,i++);
    enter(E,4,5,1,i++);
    enter(E,4,7,2,i++);
    enter(E,5,6,3,i++);
    enter(E,5,7,1,i++);
    enter(E,5,8,2,i++);
    enter(E,6,8,1,i++);
    enter(E,7,8,1,i++);

    
    bubblesort(E,g);
    display(E,g);
    kruskal(E,n,g,t);
}