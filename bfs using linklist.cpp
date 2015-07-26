#include<iostream>
#include<cstring>

using namespace std;

class Queue
{
    class node
    {
        public:
        int info;
        class node *next;

    };
    node *front,*rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

void   enQueue(int n)
    {
        node *p=getnode(n);

            if(isempty())
            {
                front=rear=p;


            }
            else
            {
                rear->next=p;
                rear=p;
            }


    }

node* getnode(int k)
{

    node* ptr=new node;
    ptr->next=NULL;
    ptr->info=k;
    return ptr;


}
void display();
bool isempty();
int dequeue();


};
int Queue::dequeue()
{
    int x;
    node *p=front;
    if(p==NULL)
    {
        cout<<"queue is empty";
    }
    else if(front->next==NULL)
    front=rear=NULL;
    else
    front=front->next;
    x=p->info;
    delete p;
    return x;

}

bool Queue::isempty()
{
    if(front==NULL && rear==NULL)
    return true;
    else
    return false;
}
void Queue::display()
{
   node *p=front;
    while(p!=NULL)
    {
        cout<<" "<<p->info;
        p=p->next;
    }
}


class bfs
{
    class node
    {
        public:
        int info;
        node *next;
    };
    //node **headnode;
    class hnode
    {
        public:
        int info,dis;
        char color[10];
        node *next;             //store the adress of class node not hnode
    };
    hnode **headnode;
    public:
   // char c[10];
    node* getnode(int n)           //for node
    {
        node *ptr;
        if((ptr=new node)==NULL)
        {
        cout<<"node not created";
        return NULL;
        }
        else
        {
            ptr->info=n;
            ptr->next=NULL;
            return ptr;
        }
    }
    hnode* gethnode(int n)                  //for headnode
    {
        hnode *ptr;
        if((ptr=new hnode)==NULL)
        {
            cout<<"head node not created";
            return NULL;
        }
        else
        {
            char c[]={"white"};
            ptr->info=n;
            ptr->next=NULL;
            strcpy(ptr->color,"white");
            ptr->dis=-2222;
            //cout<<ptr->color<<" ";
            return ptr;

        }
    }
    void create_graph(int);
    bfs(int n);
    void insert(int,node*);
    void showlist(int);
    void Bfs();
    void vdisplay(int);

};
void bfs::create_graph(int n)
{
    int no,x;
    for(int i=0;i<n;i++)
    {

        cout<<"enter the no of adjecent vertex of "<<i<<" ";
        cin>>no;
        for(int j=0;j<no;j++)
        {
            cout<<"enter the adjecent of "<<i<<" ";
            cin>>x;
            insert(i,getnode(x));

        }

    }
}
bfs::bfs(int n)             //constructor to initialize the value
{
    headnode=new hnode*[n];     //initialize the array of pointer node
    for(int i=0;i<n;i++)
    {
        headnode[i]=gethnode(i);
       // hnode *ptr=headnode[i];
       // cout<<headnode[i]->color<<" ";
    }
}
void bfs::insert(int i,node *ptr)
{
    node *p;
    p=headnode[i]->next;
    if(headnode[i]->next==NULL)
    headnode[i]->next=ptr;
    else
    {
        while(p->next!=NULL)
        p=p->next;
        p->next=ptr;
    }
}
void bfs::showlist(int n)
{
    node *ptr;
    for(int i=0;i<n;i++)
    {

        ptr=headnode[i]->next;
        cout<<"adjecent of vertex of "<<headnode[i]->info<<" is"<<endl;
       // cout<<"adjecent vertex is ";
        while(ptr!=NULL)
        {
                        cout<<" "<<ptr->info;
                        ptr=ptr->next;


        }
        cout<<endl;
    }
}
void bfs::Bfs()                 //bfs algo
{
    int x,v;
    char g[]={"grey"},b[]={"black"},w[]={"white"};
    Queue q;
    node *ptr;

    cout<<"enter the vertex no from it started:";
    cin>>x;
    strcpy(headnode[x]->color,"grey");
    headnode[x]->dis=0;
    q.enQueue(x);
    while(!(q.isempty()))
    {
        int u=q.dequeue();
        ptr=headnode[u]->next;
        while(ptr!=NULL)
        {
            v=ptr->info;
            if(!strcmp(headnode[v]->color,w))
            {
                //cout<<"here";
                strcpy(headnode[v]->color,"grey");
                headnode[v]->dis=(headnode[u]->dis)+1;
                q.enQueue(v);

            }
            ptr=ptr->next;

        }
        strcpy(headnode[u]->color,"black");

    }



}
void bfs::vdisplay(int n)
{
   for(int i=0;i<n;i++)
   {
       cout<<"vertex "<<i<<" ";
       cout<<"distance= "<<headnode[i]->dis<<" ";
       cout<<"color="<<headnode[i]->color<<" ";
       cout<<endl;
   }
}

int main()
{
    int n;
    cout<<"enter the no of vertices in the graph:";
    cin>>n;

    bfs b(n);
    b.create_graph(n);
    b.showlist(n);
    cout<<"before apply bfs"<<endl;
    b.vdisplay(n);
    b.Bfs();
    cout<<"after apply bfs"<<endl;
    b.vdisplay(n);


}
