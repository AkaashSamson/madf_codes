#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 100

struct node{
    int freq;
    char key;
    struct node *left,*next,*right;
};

struct node *start = NULL;

void insert(struct node *tmp){
    struct node *ptr,*prev;
    ptr = start;
    prev = NULL;

    while((ptr!=NULL)&&((ptr->freq<=tmp->freq))){ //||((ptr->freq==tmp->freq)&&(ptr->key<tmp->key)))){
        prev = ptr;
        ptr = ptr->next;
    }

    // while((ptr->freq==tmp->freq)&&(tmp->key=='#')){
    //     prev = ptr;
    //     ptr = ptr->next;
    // }

    if(prev==NULL){
        tmp->next=start;
        start = tmp;
    }
    else{
        tmp->next=ptr;
        prev->next=tmp;
    }

    return;

}

void initialise(char character[], int frequencies[], int n){
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    for(int i=0;i<n;i++){

       struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->key = character[i];
        tmp->freq = frequencies[i];
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->next = NULL;
       
       
        insert(tmp);
    }
}

struct node * popfront(){
    if(start==NULL)
        return NULL;
    else{
    struct node *tmp = start;
    start = tmp->next;
    return tmp;
    }
}

int empty(){
    if(start->next==NULL)
        return 1;
    else
        return 0;
}

// void show(char characters[], int frequencies[], int n){
//     for(int i = 0; i<n;i++){
//         printf("%c %d, ", characters[i], frequencies[i]);
//     }
//     printf("\n");
// }

void getinput(){
    char input[N],character[N];
    int frequencies[N],i,size=0,j=0;
    printf("Enter the string: ");
   //scanf("%s", input);
   fgets(input, sizeof(input) ,stdin);
    input[strcspn(input,"\n")]='\0';

    int freq[256] = {0};
    for(i=0;input[i]!='\0';i++){
        freq[(int)input[i]]++;
    }
    j=0;
    for(i=0;i<256;i++){
        if(freq[i]!=0){
            size++;
            character[j]=(char)i;
            frequencies[j]=freq[i];
            j++;
        }
    }
     
    //show(character,frequencies,size);
    initialise(character,frequencies,size);
}

void display(){
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL){
       printf("(%c,%d),", ptr->key, ptr->freq);
        ptr=ptr->next;
    }
    printf("\n");
}

void huffman(){
    struct node *a,*b;
    
    //priority queue already initialised
    while(!empty()){
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        display();
        a = popfront();
        b = popfront();
        tmp->key = '#';
        tmp->freq = a->freq+b->freq;
        tmp->left = a;
        tmp->right = b;
        tmp->next=NULL;
        //printf("test2\n");
        insert(tmp);
    }
}

void showpaths(struct node *root,int path[], int len){
    int i;
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL){
        printf("%c -\t", root->key);
        for(i=0;i<len;i++)
            printf("%d", path[i]);
        printf("\n");
    }

    path[len] = 0;
   // printf("test1%d ", len);
    showpaths(root->left,path,len+1);

    path[len] = 1;
    //printf("test2%d ", len);
    if(root->right!=NULL)
    
    showpaths(root->right,path,len+1);
    
}

int main(){
    int path[N];
    getinput();
    display();
    huffman();
    display();
    showpaths(start,path,0);
   
}