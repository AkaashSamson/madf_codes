#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 50

char str1[MAX_LENGTH],str2[MAX_LENGTH],LCS_seq[MAX_LENGTH][MAX_LENGTH];
int LCS_length[MAX_LENGTH][MAX_LENGTH],LCS_path[MAX_LENGTH];


int maxi(int a, int b){
    if(a>=b)
        return a;
    else  
        return b;
}



void LCS(){
    int len1=strlen(str1), len2=strlen(str2);

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0||j==0){
                LCS_length[i][j]=0;
                
                }
            else if(str1[i-1]==str2[j-1]){
                 //printf(" %c %c\n", LCS_seq[n][m], n, m, str1[n-1], str2[m-1]);
                LCS_length[i][j]=LCS_length[i-1][j-1]+1;
                LCS_seq[i][j]='D';
            }
            else{
                LCS_length[i][j]=maxi(LCS_length[i-1][j],LCS_length[i][j-1]);
                if(LCS_length[i-1][j]>=LCS_length[i][j-1])
                LCS_seq[i][j]='U';
                else  
                LCS_seq[i][j]='L';                
            }
            
            
        }
    }

}

void traceback(int n, int m){
    if(n==0||m==0)
        return;
    //printf("%c %d %d %c %c\n", LCS_seq[n][m], n, m, str1[n-1], str2[m-1]);
    switch(LCS_seq[n][m]){
        case 'D': LCS_path[n-1]=1;
                  traceback(n-1,m-1);
                  break;

        case 'U':traceback(n-1,m);
                break;

        case 'L': traceback(n,m-1);
                  break;
    }
}

int main(){
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    LCS();
    printf("Length of lcs: %d\n", LCS_length[strlen(str1)][strlen(str2)]);
    printf("LCS: ");
    traceback(strlen(str1),strlen(str2));
    
    for(int i=0;i<strlen(str1);i++){
        if(LCS_path[i]==1)
            printf("%c ", str1[i]);
    }
    printf("\n");
}