// QUEUE PROGRAM USING TEMPLATES
//NAME-ABHISHEK KUMAR LABH
//ROLL NO-09/CSE/52


#include<iostream>

using namespace std;
template<class T>
class queue{
private:
int top,MAX;
T *v,j;
public:
queue(int a){
	v=new  T[a] ;
	top=-1;
MAX=a-1;
	}
void push(T j){
	if(top==MAX){
	cout<<"stack is overflow"<<endl;
	}
	else
	{
	v[++top]=j;
		}
	}	
void pop(){
	if(top==-1){
	cout<<"stack is underflow"<<endl;
		}
		else 
			{
		for(int s=0;s<top;s++)
		v[s]=v[s+1];
		
			--top;
			}
	}
void display(){
	for(int s=0;s<=top;s++)
	cout<<v[s]<<endl;
	}

};

int main(){
int c,n;

queue <int> q1(4);
do{
cout<<"queue"<<endl;
cout<<"1.push into the queue"<<endl;
cout<<"2.pop into the queue"<<endl;
cout<<"3.display"<<endl;

cin>>c;
switch(c)
{
	case 1:
		cout<<"enter the no:";
                int item;
		cin>>item;
		q1.push(item);
		break;
	case 2:
		q1.pop();
		break;
	case 3:
		q1.display();
		break;
	default:
	cout<<"error:try again"<<endl;
} 
cout<<"enter 1 for continue"<<endl;
cin>>n;
	}while(n==1);
return 0;
}

/*                output


dell@ubuntu:~$ g++ quetemplate.cpp
dell@ubuntu:~$ ./a.out
queue
1.push into the queue
2.pop into the queue
3.display
1
enter the no:34
enter 1 for continue
1
queue
1.push into the queue
2.pop into the queue
3.display
1
enter the no:23
enter 1 for continue
1
queue
1.push into the queue
2.pop into the queue
3.display
3
34
23
enter 1 for continue
1
queue
1.push into the queue
2.pop into the queue
3.display
2  
enter 1 for continue
1
queue
1.push into the queue
2.pop into the queue
3.display
3
23
enter 1 for continue
*/







