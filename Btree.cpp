#include<iostream>
using namespace std;
template<class T,int m>
class bnode
{
    public:
    int nk;
    T  k[m-1];
    bnode<T,m> *p[m];
bnode(){
        nk=0;
    for(int i=0;i<m;i++)
        p[i]=NULL;
}
~bnode(){}
};
template<class T,int m>
class btree{
    public:
    int i,j;
    bnode<T,m> *root;
btree(){
    j=0;
    root=NULL;
}
~btree(){}

bnode<T,m>* insert(T x,bnode<T,m> *c,bnode<T,m> *p){
    bnode<T,m> *R;
    T y;
    if(c==NULL){
    root=new bnode<T,m>;
    root->k[0]=x;
    (root->nk)++;
    return (NULL);
    }
    else if(c->p[0]==NULL){
        if(c->nk==m-1){
            if(p==NULL){
                root=case2(x,c,NULL);
                return (NULL);
                }
            else{
                R=case3(x,c,NULL);
                return(R);
                }
        }
    else if(c->nk<=(m-1)){
        case1(x,c,NULL);
        return (NULL);
        }
    }
    else{
        for( i=0;i<c->nk;i++)
            if(x>c->k[i])
                break;
           R=insert(x,c->p[i],c);
                    if(R==NULL)
                        return (NULL);
                    else{
                        y=((c->p[i])->k[m-2]);
                        ((c->p[i])->nk)--;
                        if(c->nk==m-1){
                            if(p==NULL){
                                root=case2(y,c,R);
                                return (NULL);
                                }
                            else{
                                R=case3(y,c,R);
                                return (R);
                                }
                        }
                    else{
                        case1(y,c,R);
                        return (NULL);
                        }
                    }
    }
    return(NULL);

}
bnode<T,m>* case1(T x,bnode<T,m> *cur,bnode<T,m> *p){

    int i,j;
	for(i=0;i<cur->nk;)
	{
		if(x>cur->k[i])
		i++;
		else
		break;
	}
	for(j=(cur->nk)-1;j>=i;j--)
	{
		cur->k[j+1]=cur->k[j];
	}
	for( j=cur->nk;j>=i;j--)
	cur->p[j+1]=cur->p[j];
	cur->k[i]=x;
	cur->nk++;
	cur->p[i+1]=p;
	return NULL;
}
bnode<T,m>* case2(T x,bnode<T,m> *c,bnode<T,m> *r){
    bnode<T,m> *l=new bnode<T,m>;
    bnode<T,m> *p=new bnode<T,m>;
    int i,j;
    for(i=(c->nk)/2,j=0;i<c->nk;i++,j++){
    l->k[j]=c->k[i];
    }
    c->nk=j-1;
    l->nk=j;
    p->k[0]=l->k[0];
    for(i=0;i<l->nk-1;i++){
    l->k[i]=l->k[i+1];
    }
    (l->nk)--;
    for(i=c->nk+1,j=0;i<m;i++,j++){
    l->p[j]=c->p[i];
    }
    p->p[0]=c;
    p->p[1]=l;
    p->nk=1;
    bnode<T,m> *s=p;
    if(p->k[0]>=x)
        p=p->p[0];
    else
        p=p->p[1];
    for(i=0;i<p->nk;)
	{
		if(x>p->k[i])
		i++;
		else
		break;
	}
	for(j=(p->nk)-1;j>=i;j--)
	{
		p->k[j+1]=p->k[j];
	}
	for( j=p->nk;j>=i;j--)
	p->p[j+1]=p->p[j];
	p->k[i]=x;
	p->nk++;
	p->p[i+1]=r;
    return s;

}
bnode<T,m>* case3(T x,bnode<T,m> *c,bnode<T,m> *r){
    bnode<T,m> *l=new bnode<T,m>;
    for(i=c->nk/2,j=0;i<m-1;i++,j++){
    l->k[j]=c->k[i];
    }
    c->nk=j-1;
    l->nk=j;
    if(c->k[0]>x&&l->k[0]>x){

	for(i=0;i<c->nk;)
	{
		if(x>c->k[i])
		i++;
		else
		break;
	}
	for(j=(c->nk)-1;j>=i;j--)
	{
		c->k[j+1]=c->k[j];
	}
	for( j=c->nk;j>=i;j--)
	c->p[j+1]=c->p[j];
	c->k[i]=x;
	c->nk++;
	}
	else if(l->k[0]>x){

	for(i=0;i<l->nk;)
	{
		if(x>l->k[i])
		i++;
		else
		break;
	}
	for(j=(l->nk)-1;j>=i;j--)
	{
		l->k[j+1]=l->k[j];
	}
	for( j=l->nk;j>=i;j--)
	l->p[j+1]=l->p[j];
	l->k[i]=x;
	l->nk++;
	}
	for(i=0;i<=r->nk;i++){
        if(r->p[i]==c){
        break;
        }
	}
	r->p[i+1]=l;
	return (l);
}
/*void disp(bnode<T,m> *q){
    for(i=0;i<q->p[0]->nk;i++)
    cout<<q->p[0]->k[i]<<" ";
    for(i=0;i<q->nk;i++)
    cout<<q->k[i]<<" ";
    for(i=0;i<q->p[1]->nk;i++)
    cout<<q->p[1]->k[i]<<" ";
    //for(i=0;i<q[])
    //disp(q->p[i]);
}*/
void disp(bnode<T,m> *q,int c)
{
    if(q!=NULL){
    disp(q->p[0],c);
    for(int j=0;j<q->nk;j++)
    cout<<q->k[j]<<" ";
    if(c<q->nk && q->p[0]!=NULL){
        ++c;
    disp(q->p[c],c);
    if(c==q->nk)
    c=1;
    }
    }
}
};
int main(){
    btree<int,6> s;
    int n,c=0;
    char ch='y';
    while(ch=='y'){
    cout<<"enter a num";
    cin>>n;
    s.insert(n,s.root,NULL);
    cout<<"enter your option(y/n)";
    cin>>ch;
    }
    s.disp(s.root,c);
    return 0;
    }

