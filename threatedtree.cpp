#include<iostream>
 using namespace std;

  template<class T>
  class thnode
  {
	  public:
	  T info;
	  thnode <T> *lc;
	  thnode<T> *rc;
	  char tag;

	  thnode()
	  {
		  lc=rc=NULL;
		  tag='L';


		  }
		  ~thnode()
		  {
			  lc=rc=NULL;
			  }

  };

  template<class T>
  class  thtree
  {
	  public:
	 thnode<T> *root,*prev;
	  thtree()
	  {
		  root=NULL;

		  }
		  ~thtree(){}

		//  void insert(T x);
		  //void inorder(void);
	void insert(T x)
 {
	 thnode<T> *p;
	p=root;
	 thnode<T> *n=new thnode<T>;
	  n->info=x;
	 if (root==NULL)
	 {
		 root=n;
		 return ;
		 }
	 while(p!=NULL)
	 {
		 prev=p;
		 if(x<p->info)
		 p=p->lc;
		 else if(p->tag!='T')
		 p=p->rc;
		 else break;


		 }
	 if(x<prev->info)
	 {
		 prev->lc=n;
		 n->rc=prev ;
		 n->tag='T';
		 return ;

		 }
		 else if(prev->tag=='T')
		 {
			 n->rc=prev->rc;
			 prev->tag='L';
			 n->tag='T';
			 prev->rc=n;
			 return ;

			 }
			 else
			 {
				  prev->rc=n;
			      return ;
			 }

	 return ;
	 }

	// template<class T>
	 void inorder(thnode<T> *ptr)
	 {
		 if(ptr!=NULL)
		 {
			 inorder(ptr->lc);
			 cout<<ptr->info;
			 if(ptr->tag!='L')
			 {
				 inorder(ptr->rc);
				 }
			 }
		 }

	  };
 //template<class T>

int main()
{
	int n=6;
	thtree<int> t1;
	thtree<string> t2;
	int x;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the no:";
		cin>>x;
		t1.insert(x);
		}
		t1.inorder(t1.root);
	}


