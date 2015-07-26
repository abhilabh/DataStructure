
//					NAME ABHISHEK KUMAR LABH
//					ROLL NO: 09/CSE/52
#include<iostream>
 using namespace std;
 
 class heap{
	 public:
	 int *h;
		 heap(int n)
		{
		 
			 h=new int[n];
			 cout<<"enter the no to be sorted\n";
			 for(int a=0;a<n;a++)
			{
			 cout<<"h["<<a<<"]=";
			 cin>>h[a];
			 }
		 }


		void Heap(int n)		//heap the element
			 {
				 for(int i=(n/2)-1;i>=0;i--)
				 {
					 if(h[i]<h[2*i+1])
					 {
						 swap(i,i*2+1);
					 }
					 if(2*i+2!=n || n%2!=0)
					 {
						 if(h[i]<h[i*2+2])

						 {
						 swap(i,2*i+2);
					 }
					 }
						 
				 }
				 swap(0,n-1);
				if(n!=1){
					 Heap(n-1);
					}
			}
				 
				 void swap(int x,int y)
					{
					 int item=h[x];
					 h[x]=h[y];
					 h[y]=item;
					 }
				 void display(int n)
					 {
						 cout<<"sorted no are"<<endl;
						 for(int i=0;i<n;i++)
						 {
							 cout<<"h["<<i<<"]="<<h[i]<<endl;
							 
							 }
					 }
	

 };
	 
int main()
{
	int m;
	cout<<"enter the no of element:";
	cin>>m;
	heap h1(m);
	//h1.n=m;
	h1.Heap(m);
	h1.display(m);
	return 0;
	}

