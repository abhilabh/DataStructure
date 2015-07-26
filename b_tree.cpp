#include<iostream>

using namespace std;
template<class T,int m>
class bnode
{

    public:
    int nk;
    T k[n-1];
    bnode<T,m> *p[m];
    bnode()
    {
		nk=0;
		for(i=0;i<m-2;i++)
		p[i]=NULL;
		}
~bnode(){};

};
template<claas T>
 class  btree
  {
	  public:
	 bnode<T> *root;
	  btree()
	  {
		  root=NULL;
		  c=NULL;

		  }
		  ~btree(){}

		//  void insert(T x);
		  //void inorder(void);
		  
	  }
template<claas T>
bnode<T,m>* btree<T>::insert(t x,bnode<t,m> *c,bnode<t,m> *par)
{
    bnode<T,m> *r;
    if(c==NULL)
    {
        root=new bnode<string,5>(x,0);
        return(root);
    }
}
if(c->p[0]==NULL)
{


    if(c->nk==(m-1))
    {
        if(par==NULL)
        {
            root=case 2(x,c,NULL);
            return(NULL);
        }
        else
        {
            r=case 3(x,c,NULL);
            return(root);
        }
    }
    else if(c->nk<=(m-1))
    {
        case 1(x,c,NULL);
        return(NULL);
    }
    else
    {
        for(int i=0;i<nk;i++)
        if(x>c->k[i])
        r=insert(x,c->p[i],c)
        if(r==NULL)
        return(NULL);
        else
        {
            y=((c->p[i])->k[nk-1])
            ((c->p[i])->nk)--;
            if(c-nk==(m-1))
            {
                if(par==NULL)
                {
                    root=case2(y,c,r);
                    return(NULL);

                }
                else
                {
                    r=case3(y,c,r);
                    return(r);

                }
            }
            else
            {
                case1(y,c,r);
                return(NULL);
            }
        }
    }
}
template<class T>
void btree<T>::case1(T x,bnode<T,m> *c,bnode<T,m> *r)
{
    for(int i=0;i<=nk-1;i++)
    if(x<c->k[i])

{
    for(int j=m-1;j<i;j--)
    c->k[i+1]=c->k[i];
    c->k[i]=x;

    c->p[i+1]=r;

    break;
}
}

template<claas T>
void btree<T>::case2(T x,bnode<T,m> *c,bnode<T,m> *r)
{
     bnode<T,m> *P=new bnode<string,5>;
    bnode<T,m> *L=new bnode<string,5>;
    for(int i=0;i<=(m/2)-1;i++)
    L->k[(L->nk)++]=c->k[(c->nk)++];
    
    root=case1(x,c,NULL);
    P->k[0]=c->k[nk-1];
    (c->nk)--;
    p->p[0]=c;
    p->p[1]=L;
    return(p);
    
}
template<claas T>
void btree<T>::case3(T x,bnode<T,m> *c,bnode<T,m> *r)
{
	
	 bnode<T,m> *L=new bnode<string,5>;
	 
	for(int i=0;i<=(m/2)-1;i++)
    L->k[(L->nk)++]=c->k[(c->nk)++];
    
    root=case1(x,c,NULL);
    r->k[nk-1]=c->k[nk-1];
    (r->nk)++;  (c->nk)++;
    return(L);
	
	}

int main()
{
	int x;
	cout<<"enter the no of element: ";
	cin>>n;
	btree<int> b1;
	for(int i=0;i<n;i++)
	{
	b1.insert(x,root,NULL);
	b1.display;
}
	
	}
