
#include<stdio.h>
#include<stdlib.h>

#define max 5

int adj[max][max];
int stack[max];
int visited[max]={0};
int top=-1;

void addEdge(int src,int dest)
{
	adj[src][dest]=1;
	adj[dest][src]=1;
}

void dfs(int start)
{
    int v;
    stack[++top]=start;
    while(top>=0)
    {
        v=stack[top--];
        if(visited[v]==0)
        {
            printf("%d ",v);
            visited[v]=1;
        
            for(int i=0;i<max;i++)
            {
         
                if(adj[v][i]==1 && !visited[i])
                {
                     stack[++top]=i;
                }
            }
        }
    }

}

int main() {
int source,destination;
    
    for(int i=0;i<max;i++)
    {
    	for(int j=0;j<max;j++)
    	{
            adj[i][j]=0;
    	}
    	
    }

     for(int i=0;i<max;i++)
    {
      printf("enter source and destination ");
      scanf("%d%d",&source,&destination);
      addEdge(source,destination);
     }

    printf("DFS \n");
    dfs(0);
    printf("\n");
    printf("Matrix Representation is:\n");
    for(int i=0;i<max;i++)
    {
   	 for(int j=0;j<max;j++)
    	 {
            printf("%d ",adj[i][j]);
    	 }
    	 printf("\n");
    }
}
