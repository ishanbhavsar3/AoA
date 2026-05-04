#include <stdio.h>
int parent[100];

int find(int i){
	while(parent[i]!=i)
		i=parent[i];
	
	return i;
}

void main(){
	int n, e, i, j, t, a, b, u[100], v[100], w[100], cost=0;
	printf("Input number of vertices and edges: ");
	scanf("%d %d", &n, &e);
	printf("Input u, v, w: ");
	for(i=0; i<e; i++)
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		
	for(i=0; i<e-1; i++)
	{
		for(j=i+1; j<e; j++)
		{
			if(w[i]>w[j])
			{
				t=w[i]; w[i]=w[j]; w[j]=t;
				t=u[i]; u[i]=u[j]; u[j]=t;
				t=v[i]; v[i]=v[j]; v[j]=t;
			}
		}
	}
	for(i=0; i<e; i++)
	{
		a=find(u[i]); b=find(v[i]);
		if(a!=b)
		{
			cost+=w[i];
			parent[a]=b;
			printf("%d-%d\n",u[i],v[i]);
		}
	}
	   printf("Cost=%d",cost);
}
