#include <stdio.h>

int set[100],x[100],n,target;

void subset(int sum,int k){
    if(sum==target){
        for(int i=0;i<k;i++)
            if(x[i]) printf("%d ",set[i]);
        printf("\n"); return;
    }
    if(sum>target||k==n) return;

    x[k]=1; subset(sum+set[k],k+1);
    x[k]=0; subset(sum,k+1);
}

int main(){
    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&set[i]);

    printf("Enter target: ");
    scanf("%d",&target);

    subset(0,0);
}