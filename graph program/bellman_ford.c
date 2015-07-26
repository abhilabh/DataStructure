#include<stdio.h>
#include<malloc.h>


struct adjlist
{

	int dest,cost;
	struct adjlist *next;
};
struct BFS
{
	int weight;
	int pie;
	struct adjlist *adj;
};

struct Graph
{
	int v;
	struct BFS *array;
};

int time;

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

void insert(struct Graph *g,int source,int dest,int cost)
{
	struct adjlist *temp;
	struct adjlist *node=(struct adjlist *)malloc(sizeof(struct adjlist));
	node->next=NULL;
	node->dest=dest;
	node->cost=cost;
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
		printf("\n\n%d adj list\n\n",i);
		//temp=&head[i];
		while(temp!=NULL)
		{
			printf("dest=%d \tcost=%d\n",temp->dest,temp->cost);
			//printf("%c \t",temp->cost);
			temp=temp->next;
		}

	}
}

int bellman_ford(struct Graph *G)
{
	int i;
	struct adjlist *v;
		G->array[i].pie=1000;
		G->array[i].weight=0;

	for(i=1;i<G->v;i++)
	{
		G->array[i].pie=1000;
		G->array[i].weight=1000;
	}
	
	for(i=0;i<G->v;i++)
	{
		struct adjlist *v;
		v=G->array[i].adj;
		while(v)
		{
			if(G->array[v->dest].weight > G->array[i].weight+v->cost)
			{
				G->array[v->dest].pie=i;
				G->array[v->dest].weight=G->array[i].weight+v->cost;

			}

			v=v->next;
		}
	}
	for(i=0;i<G->v;i++)
	{
		struct adjlist *v;
		v=G->array[i].adj;
		while(v)
		{
			if(G->array[v->dest].weight > G->array[i].weight+v->cost)
			{
				return 0;
			}
			v=v->next;
		}

	}

	return 1;
}

void printall(struct Graph *G )
{
	int i;
	for(i=0;i<G->v;i++)
	{
		printf("cost=%d\t\tpie=%d\n\n",G->array[i].weight,G->array[i].pie);
	}
}
int main()
{
	struct Graph *node;
	int num,i,j,naddj,adj,ret,cost;
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
		printf("enter the cost : ");
		scanf("%d",&cost);
		insert(node,i,adj,cost);
		}
	}
		display(node);
//	printf("enter the source vertx");
//	scanf("%d",&s);
//	bfs_search(node,s);
	ret=bellman_ford(node);
	printall(node);
	if(ret==0)
	{
		printf("graph contain negative edge\n");
	}

}

