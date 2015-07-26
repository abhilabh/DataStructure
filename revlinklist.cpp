#include<iostream>

using namespace std;

//template<class T>
class linklist
{
    public:
    int info;
    linklist *next;
 };
 class node
 {
     public:
     linklist *root;


    void insert(linklist *ptr)
    {
       linklist *temp;
       int c=0;

       do
       {
            temp=new linklist;
            cout<<"\nenter the no to be inserted:";
            cin>>temp->info;
            if(ptr==NULL)
            {
                root=temp;
                root->next=NULL;
                ptr=temp;

            }

            else
            {
                ptr->next=temp;
                ptr=temp;
                temp->next=NULL;

            }
      cout<<"enter 1 for continue:";
      cin>>c;
       }while(c==1);

    }

    void display(linklist *ptr)
    {
        while(ptr!=NULL)
        {
            cout<<" "<<ptr->info;
            ptr=ptr->next;
        }
    }
    linklist* rev(linklist *ptr,linklist *prev)
    {
        if(ptr->next==NULL)
        {
            root=ptr;
            return prev;
        }
        prev=ptr;
        ptr->next=rev(ptr->next,prev);
        return prev;
    }
    void del(linklist *ptr)
    {
        int x;
        linklist *prev;
        cout<<"enter the no which is deleted:";
        cin>>x;
        while(ptr!=NULL)
        {
            if(ptr->info==x)
            {
                if(ptr==root)
                root=ptr->next;
                else
                {
                    prev->next=ptr->next;
                }
               delete (ptr);
               break;
            }

            else
            {
                prev=ptr;
                ptr=ptr->next;
            }
        }
    }

};


int main()
{

node a;
    a.root=NULL;

    int c,x=1;
    while(x!=0){
    cout<<"\n\nlinklistlist list program"<<"\n\n1.insert"<<"\n2.display"<<"\n3.delete"<<"\nentr ur choice:";
    cin>>c;
    switch(c)
    {
        case 1:
        a.insert(a.root);
        break;

        case 2:
        a.display(a.root);
        break;
        case 3:
        a.del(a.root);
        case 4:
        a.rev(root);
        break;

        default:
        cout<<"error:try agian"<<endl;




    }
    cout<<"\nenter 0 for exit:";
    cin>>x;
    }


}

