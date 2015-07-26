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
        max1 *p;
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


int main()
{
    sub s;
    max1 *k=s.max_cross_sum(s.A,0,4,8);
    cout<<k->left<<" "<<k->right<<" "<<k->sum;

}
