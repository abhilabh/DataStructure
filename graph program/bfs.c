#include<stdio.h>

#define MAX 20

int queue[MAX];
int rear,front;

void enqueue(int num)
{

	if(front==0 && rear==MAX-1)
   	printf("\n Queue OverFlow Occured");
    	else if(front==-1&&rear==-1)
  	 {
         front=rear=0;
          queue[rear]=num;
	 
	  }
     else if(rear==MAX-1 && front!=0)
  	{
      rear=0;
     queue[rear]=num;
  }
    else
      {
      rear++;
      queue[rear]=num;
     }
	/*if(isfull()){
	if(front==-1)
		{
			front=rear=0;
			que[rear++]=num;
		}
	else
	que[rear++]=num;
	}
	printf("***%d***%d***%d\n ",front,rear,que[rear-1]);*/
}

int dequeue()
{
	int element;
  	if(front==-1)
  	{
     	 printf("\n Underflow");
  	}
  	element=queue[front];
  	if(front==rear)
     front=rear=-1;
  	else
 	 {
    	if(front==MAX-1)
      front=0;
   	 else
      front++;
       printf("\n The deleted element is: %d",element);
  }
/*	if(isempity())
	{
		if(rear==1)
		{
			front=rear=-1;
		}
		else
		rear--;
	}
	return que[rear];
	*/
	return element;

}
int isempity()
{
	if(front==-1)
	{
		printf("queue is empity\n");
		return 0;
	}
	else return 1;
}

int isfull()
{
	if(rear==MAX)
	{
		printf("queue is full\n");
		return 0;
	}
	else return 1;
}

/*int main()
{
int i;
 front=rear=-1;
	enqueue(10);
	enqueue(20);
	enqueue(40);
	enqueue(20);
	for(i=0;i<rear;i++)
	{
		printf("%d \t",que[i]);
	}
	putchar('\n');
	dequeue();
	dequeue();
	for(i=0;i<rear;i++)
	{
		printf("%d \t",que[i]);
	}
	putchar('\n');
	dequeue();
	dequeue();
	for(i=0;i<rear;i++)
	{
		printf("%d \t",que[i]);
	}
	putchar('\n');
	dequeue();
	enqueue(20);
	for(i=0;i<rear;i++)
	{
		printf("%d \t",que[i]);
	}

}*/
