#include <iostream>
using namespace std;
template <class T>
class thnode{
    public:
              T key;
              thnode<T> *lc,*rc,*p;
              char col;
              thnode(T x,thnode<T> *l=NULL,thnode<T> *r=NULL,thnode<T> *par=NULL){
                  key=x;
                  lc=l,rc=r,p=par;
                  col='R';
              }
              ~thnode(){
                  lc=rc=NULL;
              }
};
thnode<int> *nil;

template <class T>
class thtree{
    public:
              thnode<T> *root,*nil;
              thtree(){
				  nil=new thnode<T>(-1);
				  nil->col='B';
				  nil->lc=nil->rc=nil->p=nil;
				  root=nil;
              }
              void lrot(thnode<T> *x);
              void rrot(thnode<T> *x);
              void insert(thnode<T> *x);
              void rbfix(thnode<T> *z);
              void disp(thnode<T> *z);
};
template <class T>
void thtree<T>::lrot(thnode<T> *x){
    thnode<T> *y;
    y=x->rc;
    x->rc=y->lc;
    if(y->lc!=nil){
	    (y->lc)->p=x;
	}
	y->p=x->p;
	if(x->p==nil)
	    root=y;
	else{
		if(x==((x->p)->lc))
	        ((x->p)->lc)=y;
	    else
	        ((x->p)->rc)=y;
	}
	y->lc=x;
	x->p=y;
}
template<class T>
void thtree<T>::rrot(thnode<T> *x){
    thnode<T> *y;
    y=x->lc;
    x->lc=y->rc;
    if(y->rc!=nil){
	    (y->rc)->p=x;
	}
	y->p=x->p;
	if(x->p==nil)
	    root=y;
	else{
		if(x==((x->p)->rc))
	        ((x->p)->rc)=y;
	    else
	        ((x->p)->rc)=y;
	}
	y->rc=x;
	x->p=y;
}
template<class T>
void thtree<T>::rbfix(thnode<T> *z){
    while((z->p)->col=='R'){
	    if(z->p==(((z->p)->p)->lc)){
		    thnode<T> *y;
		    y=(((z->p)->p)->rc);
		    if(y->col=='R'){
		        (z->p)->col='B';
		        y->col='B';
		        ((z->p)->p)->col='R';
		        z=z->p->p;
			}
			else{
			    if(z==(z->p)->rc){
			        z=z->p;
			        lrot(z);
			    }
			    (z->p)->col='B';
			    ((z->p)->p)->col='R';
			    rrot(((z->p)->p));
		    }
	    }
	    else{
			thnode<T> *y;
		    y=(((z->p)->p)->lc);
		    if(y->col=='R'){
		        (z->p)->col='B';
		        y->col='B';
		        ((z->p)->p)->col='R';
		        z=z->p->p;
			}
			else{
			    if(z==(z->p)->lc){
			        z=z->p;
			        rrot(z);
			    }
			    (z->p)->col='B';
			    ((z->p)->p)->col='R';
			    lrot(((z->p)->p));
		    }
		}
    }
    root->col='B';
}
template<class T>
void thtree<T>::insert(thnode<T> *z){
    thnode<T> *y,*x;
    y=nil;
    x=root;
    while(x!=nil){
	    y=x;
	    if(z->key<x->key)
	        x=x->lc;
	    else
	        x=x->rc;
	}
	z->p=y;
	if(y==nil)
	    root=z;
	else{
	    if(z->key<y->key)
	        y->lc=z;
	    else
	        y->rc=z;
	}
	z->lc=z->rc=nil;
	z->col='R';
	rbfix(z);
}
template<class T>
void thtree<T>::disp(thnode<T> *r){
    if(r!=nil){
		cout<<" "<<r->key<<r->col;
		disp(r->lc);
		disp(r->rc);
	}
}
int main(int argc, char** argv)
{
	thtree<int> a;
	char ch='y';
	while(ch=='y'){
	    int val;
	    cout<<"enter the element:";
	    cin>>val;
	    thnode<int> *x=new thnode<int>(val);
    	a.insert(x);
    	cout<<"you want to enter more(y/n)";
    	cin>>ch;
    }
	a.disp(a.root);
	return 0;
}
