#include<stdio.h>
#include<stdlib.h>
#define CHAR_MAX '{'
int n;

// void interchange(int i, int j, char *arr){
//     char tmp;
//     tmp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=tmp;
// }

void display(char *arr, int n){
    printf("Elements-{");
    for(int i=0;i<n-1;i++){
        printf("%c, ", arr[i]);
    }
    printf("%c}\n", arr[n-1]);
}

void merge(int low, int mid,int up, char *arr){
    int i=low,j=mid+1,k=low,e;
    char temp[n];
    while(i<=mid && j<=up){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }

    if(i>mid){
        for(e=j;e<=up;e++)
            temp[k++]=arr[e];
    }

    else{
        for(e=i;e<=mid;e++)
            temp[k++]=arr[e];
    }

    for(e=low;e<=up;e++)
        arr[e]=temp[e];
}

void mergesort(int low, int up, char *arr){
    if(low<up){
        int mid = (low+up)/2;
        mergesort(low,mid,arr);
        
        mergesort(mid+1,up,arr);
        merge(low,mid,up,arr);
        printf("%d %d %d", low, mid, up);
        display(arr,n);
    }
}




int main(){
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char *arr = malloc((n+1)*sizeof(char));
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf(" %c", &arr[i]); //space should be given to take one vaalue at a time for characters
    }
    display(arr,n);
    mergesort(0,n-1,arr);
    display(arr,n);
}