#include <stdio.h>
#include <string.h>
#define d 256
#define q 101

int main(){
    char txt[100],pat[100];
    int i,j,n,m,p=0,t=0,h=1;

    printf("Enter text and pattern:\n");
    scanf("%s%s",txt,pat);

    n=strlen(txt); m=strlen(pat);

    for(i=0;i<m-1;i++) h=(h*d)%q;

    for(i=0;i<m;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }

    for(i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++)
                if(txt[i+j]!=pat[j]) break;
            if(j==m) printf("Match at %d\n",i);
        }
        if(i<n-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0) t+=q;
        }
    }
}