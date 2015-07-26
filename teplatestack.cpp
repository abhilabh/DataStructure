// stack program using template
//NAME-ABHISHEK KUMAR LABH
//ROLL NO-09/CSE/52

#include<iostream>

using namespace std;
template<class T> 
class stack {
private:
int top,j;
T *a,b;
public:
 stack(int n){

top=n;
j=0;
a=new T[n];
}
 	void push(T b)
	{ 
	if(j<top){
	a[j]=b;
		j++;
		}
		else 
			isfull();
	}
	void pop()
	{
	if(j==0)
	isempty();
		else{
  			a[j]=0;
			j--;
  		}
	}
 	void isfull(){
		cout<<"stack is full"<<endl;
	}
	void isempty(){
		cout<<"stack is empty"<<endl;
	}
 	void display(){
		for(int i=0;i<j;i++)
		cout<<"a["<<i<<"]="<<a[i];
	}
};

int main()
{ 
	int num,n,c;
	float k;

 stack < int> s1(3);
 stack <float> s2(4);

do{
	cout<<"stack"<<endl<<endl;
	cout<<"1. push a int no "<<endl;
	cout<<"2.pop a int no"<<endl;
	cout<<"3.push a float no"<<endl;
	cout<<"4.pop a float no"<<endl;
	cout<<"5.for display the no in the stack"<<endl;
		cout<<"enter ur choise"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"enter the no"<<endl;
			cin>>num;
			s1.push(num);
			break;
		case 2:
			s1.pop();
	             break;
		case 3:
			cout<<"enter the no"<<endl;
			cin>>k;
			s2.push(k);
			break;
		case 4:
			s2.pop();
			break;
		case 5:
	s1.display();

	s2.display();
	break;
		default: 
				cout<<"error:try again"<<endl;
	
	
	}	cout<<"enter 1 for continue"<<endl;
	cin>>n;
	
    }while(n==1);
return 0;
}
			
/*                output




dell@ubuntu:~$ g++ templatestack.cpp
g++: templatestack.cpp: No such file or directory
g++: no input files
dell@ubuntu:~$ g++ teplatestack.cpp
dell@ubuntu:~$ ./a.out
stack

1. push a int no 
2.pop a int no
3.push a float no
4.pop a float no
5.for display the no in the stack
enter ur choise
1
enter the no
34
enter 1 for continue
1
stack

1. push a int no 
2.pop a int no
3.push a float no
4.pop a float no
5.for display the no in the stack
enter ur choise
1
enter the no
23
enter 1 for continue
1
stack

1. push a int no 
2.pop a int no
3.push a float no
4.pop a float no
5.for display the no in the stack
enter ur choise
3
enter the no
2.50
enter 1 for continue
1
stack

1. push a int no 
2.pop a int no
3.push a float no
4.pop a float no
5.for display the no in the stack
enter ur choise
3.50
enter the no
enter 1 for continue
1
stack

1. push a int no 
2.pop a int no
3.push a float no
4.pop a float no
5.for display the no in the stack
enter ur choise
5
a[0]=34a[1]=23a[0]=2.5a[1]=0.5enter 1 for continue

*/
