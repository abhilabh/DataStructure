#include<stdio.h>
#include<malloc.h>


struct adjlist
{

	int dest;
	struct adjlist *next;
};
struct BFS
{
	int cost;
	char color;
	char pie;
	struct adjlist *adj;
};

struct Graph
{
	int v;
	struct BFS *array;
};

struct Graph *create(int v)
{
	int i;
	struct Graph *cg=(struct Graph*)malloc(sizeof(struct Graph));
	cg->v=v;
	cg->array=(struct BFS *)malloc(v*sizeof(struct BFS));
	for(i=0;i<v;i++)
	{
		cg->array[i].adj=NULL;
	}
	return cg;
}

typedef struct BFS bfs;

void insert(struct Graph *g,int source,int dest)
{
	struct adjlist *temp;
	struct adjlist *node=(struct adjlist *)malloc(sizeof(struct adjlist));
	node->next=NULL;
	node->dest=dest;
	if(g->array[source].adj==NULL)
	{
		g->array[source].adj=node;
	}
	else
	{
		temp=g->array[source].adj;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=node;
	}
}
void display(struct Graph *g)
{
	int i;
	for(i=0;i<g->v;i++)
	{
		struct  adjlist *temp=g->array[i].adj;
		printf("\n%d adj list\n",i);
		//temp=&head[i];
		while(temp!=NULL)
		{
			printf("%d \t",temp->dest);
			//printf("%c \t",temp->cost);
			temp=temp->next;
		}

	}
}

int bfs_search(struct Graph *G,int S)
{
	int i;
	for(i=0;i<G->v;i++)
	{
		G->array[i].color='w';
		G->array[i].pie='n';
		G->array[i].cost=1000;
	}
	G->array[S].color='g';
		G->array[S].cost=0;
		G->array[S].pie='n';
		enqueue(S);
	while(isempity())
	{
		int u;
		struct adjlist *v;
		u=dequeue();
		v=G->array[u].adj;
		printf("*******%d \t%d\n*****",u,v);

		while(v)
		{
			if(G->array[v->dest].color=='w')
			{
				G->array[v->dest].color='g';
				printf("&&&&&&&&&&&&&");
				G->array[v->dest].cost=G->array[u].cost+1;
				G->array[v->dest].pie='u';

				enqueue(v->dest);

			}
			v=v->next;
		}
		G->array[u].color='b';
	}

}

void printall(struct Graph *G )
{
	int i;
	for(i=0;i<G->v;i++)
	{
		printf("color=%c\tcost=%d\tpie=%c\n\n",G->array[i].color,G->array[i].cost,G->array[i].pie);
	}
}
int main()
{
	struct Graph *node;
	int num,i,j,naddj,adj,s;
	printf("enter total number of node : ");
	scanf("%d",&num);
	node=create(num);
	for(i=0;i<num;i++)
	{
		printf("enter the no of adj for %d node",i);
		scanf("%d",&naddj);
		for(j=0;j<naddj;j++){
		printf("enter the  adj node as num: ");
		scanf("%d",&adj);
		insert(node,i,adj);
		}
	}
		display(node);
	printf("enter the source vertx");
	scanf("%d",&s);
	bfs_search(node,s);
	printall(node);

}

