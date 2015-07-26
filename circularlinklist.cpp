#include<iostream>

using namespace std;

class circular
{
	class node 
	{
		public:
		int item;
		class node *next;
		
		};
		public:
		node *start,*ptr,*temp;
		
		//public:
	circular()
	{
		start=temp=ptr=NULL;
		}
		void create()
		{
			int c;
			//start=NULL;
			
			do
			{
				cout<<"enter the no:";
				temp=new node;
				cin>>temp->item;
				cout<<endl;
				if(start==NULL)
				{
					start=temp;
					ptr=temp;
					temp->next=start;
					}
					else
					{
						ptr->next=temp;
						ptr=temp;
						ptr->next=start;
						
						}
						cout<<"press 1 for continue:";
						cin>>c;
				}while(c==1);

  }
   void display(node *ptr)
  {
	 // ptr=start;
	   cout<<"nos are :"<<" ";
	  do
	  {
		
		  cout<<ptr->item<<"   ";
		  ptr=ptr->next;
		  }while(ptr!=start);
	  }
	};
int main()
{
	int c;
	circular s;
	do
	{
		cout<<"\n main menu "<<endl
		<<"1.create"<<endl
		<<"2.display"<<endl
		<<"press 0 for exit"<<endl
		<<"enter ur choice"<<endl;
		//int c;
		cin>>c;
		switch(c)
		{
			case 1:
			
			s.create();
			
			break;
			case 2:
			s.display(s.start);
			break;
			default:
			cout<<"error: try again";
			}
			//int k;
			//cout<<"press 1 for continue";
			//cin>>k;
		
		}while(c!=0);
		return 0;
	}
