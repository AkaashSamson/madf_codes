#include<stdio.h>
#include<stdlib.h>
#define CHAR_MAX '{'
int n;

void interchange(int i, int j, char *arr){
    char tmp;
    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

void display(char *arr, int n){
    printf("Elements-{");
    for(int i=0;i<n-1;i++){
        printf("%c, ", arr[i]);
    }
    printf("%c}\n", arr[n-1]);
}

int partition(int p, int q, char *arr){
    int i=p,j=q;
    char v=arr[p];

    do{
        do{
            i++;
        }while(arr[i]<v);

        do{
            j--;
        }while(arr[j]>v);

        if(i<j){
            interchange(i,j,arr);
            i++;
            j--;
        }

    }while(i<=j);

    arr[p]=arr[j];
    arr[j]=v;
    return j;
}

void quicksort(int p, int q, char *arr){
    if(p<q){
        int j=partition(p,q,arr);
        printf("%d %d %d", p,q,j);
        display(arr,n);
        quicksort(p,j-1,arr);
        quicksort(j+1,q,arr);
    }
    return;
}



int main(){
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char *arr = malloc((n+1)*sizeof(char));
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf(" %c", &arr[i]);
    }
    display(arr,n);
    arr[n]=CHAR_MAX;
    quicksort(0,n,arr);
    display(arr,n);
}