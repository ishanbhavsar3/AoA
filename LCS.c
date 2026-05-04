#include <stdio.h>
#include <string.h>

int max(int a,int b){ return a>b?a:b; }

int main(){
    char x[100],y[100];
    int i,j,m,n,L[100][100];

    printf("Enter strings:\n");
    scanf("%s%s",x,y);

    m=strlen(x); n=strlen(y);

    for(i=0;i<=m;i++)
    for(j=0;j<=n;j++){
        if(i==0||j==0) L[i][j]=0;
        else if(x[i-1]==y[j-1])
            L[i][j]=1+L[i-1][j-1];
        else
            L[i][j]=max(L[i-1][j],L[i][j-1]);
    }

    printf("LCS length = %d",L[m][n]);
}