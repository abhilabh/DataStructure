#include<iostream>

using namespace std;

class mrgsort
{
    public:
    int *A,n,p,r;

    mrgsort()
    {
        cout<<"enter the no of element: ";
        cin>>n;
        p=0;r=n;
        A=new int[n+1];

        cout<<"enter the numbers"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<"A["<<i<<"]=";
            cin>>A[i];
            cout<<endl;
        }
    }

   void msort(int p,int r);
   void mergesort(int p,int q,int r);
   void display()
   {
       cout<<"sorted numbers are:"<<endl;
       for(int i=1;i<=n;i++)
       {

           cout<<"A["<<i<<"]=";
           cout<<A[i];
       }
   }
};

void mrgsort::msort(int p,int r)
{
    if(p<r)
    {
       int q=(p+r)/2;
        msort(p,q);
        msort(q+1,r);
        mergesort(p,q,r);
    }
    return;
}
void mrgsort::mergesort(int p,int q,int r)
{
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int *L,*R;
    L=new int[n1+1];
    R=new int[n2+1];
    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[q+j];
        L[n1+1]=1111;
        R[n2+1]=1111;
     i=1;j=1;
     for(int k=p;k<r;k++)
     {
         if(L[i]<=R[j])
         {
             A[k]=L[i];
             i=i+1;
         }
         else
         {
             A[k]=R[j];
             j=j+1;
         }
     }

    return;
}

int main()
{
    mrgsort m;

    m.msort(m.p,m.r);
    m.display();
    return 0;

}
