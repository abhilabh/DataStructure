#include<iostream>

using namespace std;
class max1
{
    public:
    int left,right,sum;
    max1(){

        sum=-2222;
        }
};

class sub
{
    public:
        int n,*A;


    sub(){
        cout<<"enter the no of element :";
        cin>>n;

       A=new int[n];
        cout<<"enter the no of ellement :";

        for(int i=0;i<n;i++)
        {
            cout<<"A["<<i<<"]=";
            cin>>A[i];
        }
    }
    max1* max_cross_sum(int *A,int low,int mid ,int high);
    max1* max_sub_arr(int *A,int low,int high);
};

    max1* sub::max_cross_sum(int *A,int low,int mid ,int high)
    {
        max1 *p=new max1;
        int left_sum=-2222;
        int summ=0,max_left,max_right;
        for(int i=mid;i>=0;i--)
        {
            summ=summ+A[i];
            if(summ>left_sum)
            {
                left_sum=summ;
                max_left=i;
            }
        }
      int right_sum=-3333;
      summ=0;

    for(int j=mid+1;j<high;j++)
        {
            summ=summ+A[j];
            if(summ>right_sum)
            {
                right_sum=summ;
                max_right=j;
            }

        }

    p->left=max_left;
    p->right=max_right;
    p->sum=left_sum+right_sum;
    return p;

    }
    max1* sub::max_sub_arr(int *A,int low,int high)
    {
        max1 *m=new max1;
        max1 *l,*r,*c;
        if(high==low)
        {
            m->left=low;
            m->right=high;
            m->sum=A[low];
            return m;

        }
        else
        {
           int mid=(low+high)/2;
            l=max_sub_arr(A,low,mid);
           // cout<<l->left<<" "<<l->right<<" "<<l->sum;
            r=max_sub_arr(A,mid+1,high);
            c=max_cross_sum(A,low,mid,high);

        }
        if((l->sum>=r->sum) && (l->sum=c->sum))
        {
            m->left=l->left;
            m->right=l->right;
            m->sum=l->sum;
            return m;

        }

        else if((r->sum>=l->sum) && (r->sum>=c->sum))
        {

            m->left=r->left;
            m->right=r->right;
            m->sum=r->sum;
            return m;


        }
        else
        {

            m->left=c->left;
            m->right=c->right;
            m->sum=c->sum;
            return m;


        }
            }

int main()
{
    sub s;
    max1 *k=s.max_sub_arr(s.A,0,(s.n-1));
    cout<<k->left<<" "<<k->right<<" "<<k->sum;

}
