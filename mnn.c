#include<stdio.h>
#include<malloc.h>
struct Graph* creategraph();
struct node* createnode();
void addedge();
void bfs();
struct node
{
	int data;
	struct node* next;
};
struct Graph
{
	int numvertices;
	struct node** adjlists;
	int* visited;
};
void main()
{
	int numvertices=6;
	struct Graph* graph=creategraph(numvertices);
	addedge(graph,0,1);
	addedge(graph,0,2);
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,2,3);
	addedge(graph,3,4);
	addedge(graph,4,5);
	bfs(graph,0);
	free(graph->adjlists);
	free(graph->visited);
	free(graph);
}
struct Graph* creategraph(int n)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->numvertices=n;
	graph->adjlists=(struct node**)malloc(n* sizeof(struct node*));
	graph->visited=(int*)malloc(n* sizeof(int));
	for(int i=0;i<n;i++)
	{
		graph->adjlists[i]=NULL;
		graph->visited[i]=0;
	}
	return graph;
}
struct node * createnode(int key)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	return newnode;
}
void addedge(struct Graph* graph,int src,int dest)
{
	struct node* new=createnode(src);
	new->next=graph->adjlists[dest];
	graph->adjlists[dest]=new;
	
	new=createnode(dest);
	new->next=graph->adjlists[src];
	graph->adjlists[src]=new;
}
void bfs(struct Graph* graph,int start)
{
	int* queue=(int*)malloc(graph->numvertices* sizeof(int));
	int front=0,rear=0;
	queue[rear++]=start;
	graph->visited[start]=1;
	while(front<rear)
	{
		int v=queue[front++];
		printf("%d ",v);
		struct node* temp=graph->adjlists[v];
		while(temp!=NULL)
		{
			int adjvert=temp->data;
			if(graph->visited[adjvert]==0)
			{
				graph->visited[adjvert]=1;
				queue[rear++]=adjvert;
			}
			temp=temp->next;
		}
	}
	free(queue);
}
	
	
	
	
	
	
