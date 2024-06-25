//implementing knapsack problem using dynamic programming

#include<stdio.h>
#include<stdlib.h>

struct record{
    int p;
    int w;
} *pair;

int largest(struct record *pair,int low, int up, int i, int m, int *w){
    int mid;
    while(low <=  up){
        mid = (low + up) / 2;
        if(pair[mid].w+w[i] <= m)
            low = mid+1;
        else 
            up = mid-1;
    }
    return up;
}

int search(struct record *pair, int low, int up, int fl, int fu, int px){

    if(low > up || low<fl || up>fu)
        return 0;

    else{
        int mid = (low + up) / 2;
        if(pair[mid].p < px)
            return search(pair,mid+1,up,fl,fu,px);
        else if(pair[mid].p > px)
            return search(pair,low,mid-1,fl,fu,px);
        else
            return 1;
    }
        
}

void traceback(int *p, int *w, struct record *pair, int *x, int *b, int n, int m, int px){
    int low, up;

    low  = b[n-1];
    up = b[n];

    if(search(pair,low,up,low,up,px)){
        x[n] = 0;
        printf("%d ",x[n]);
    }
    else if(search(pair,low,up,low,up,px-p[n])){
        x[n] = 1;
        px = px - p[n];
        printf("%d ",x[n]);
    }

    if(n!=0)
        traceback(p,w,pair,x,b,n-1,m,px);
    else
        return;
 }

void dknap(struct record *pair, int *p, int *w, int n, int m, int *x){
    int t,h,b[n+1],next,pp,ww,i,j,k,u;
    b[0] = 1;
    t = 1;
    h = 1;
    pair[1].p = 0;
    pair[1].w = 0;
    b[1] = 2;
    next = 2;
    for(i=1;i<n+1;i++){
        u = largest(pair,t,h,i,m,w);
        //printf("%d\n",u);
        k = t;
        for(j=t;j<=u;j++){
            pp = pair[j].p + p[i];
            ww = pair[j].w + w[i];

            while(k<=h && pair[k].w < ww){
                pair[next].p = pair[k].p;
                pair[next++].w = pair[k++].w;
        }

        while(k<=h && pair[k].w == ww){
            if(pair[k].p > pp)
             pp =pair[k].p;
            k++;
        }

        if(pair[next-1].p<pp){
            pair[next].p =pp;
            pair[next++].w = ww;
        }

        while(k<=h && pair[k].p <= pair[next-1].p){
            k++;
        }

        }

        while(k<=h){
            pair[next].p = pair[k].p;
            pair[next++].w = pair[k++].w;
        }
        b[i+1] = next;
        t = h+1;
        h = next-1;
   }
    t = pair[b[n+1]-1].p;
    traceback(p,w,pair,x,b,n,m,t);
    // for(int i = 1; i <= n; i++)
    // printf("%d ",x[i]);
    printf("\nmaximum profit: %d\n", pair[b[n+1]-1].p);
    printf("maxmum weight: %d\n", pair[b[n+1]-1].w);
   }

int main(){
int p[] = {-1,28,34,12,17,23,45,35}, w[] = {-1,6,2,8,5,6,4,7},n = 7, m = 20, *x;
pair =  (struct record*)malloc(n*sizeof(struct record));
x = (int*)malloc((n)*sizeof(int));
dknap(pair,p,w,n,m,x);

return 0;
}
