
/*binary search tree using templates  */
//NAME-ABHISHEK KUMAR LABH
//ROLL NO-09/CSE/52


#include<iostream>

using namespace std;
template<class T>				//template
class bst2
{
public:
struct node{
struct node *right,*left;
T root;
};
node *temp,*tree;
bst2()						// costructor
{
tree=new node;
tree->left=NULL;
tree->right=NULL;
cout<<"enter the value of root=";
cin>>tree->root;
temp=NULL;
}

 void create(T item,node *tree)			// create function
	{
		if(temp==NULL){
		temp=new node;
	
		temp->left=NULL;
		temp->right=NULL;
		temp->root=item;
	}
		
if(tree!=NULL){
	
if(item<tree->root){
	if(tree->left==NULL)
			{

	tree->left=temp;
	temp=NULL;
	return;
	
	}
create(item,tree->left);
		}
if(item>tree->root)
	{
	if(tree->right==NULL)

	{
	tree->right=temp;
	temp=NULL;
	return;
	
			}
	create(item,tree->right);

		}
	}
}	

void inorder(node* tree)		//inorder fuction
{
	if(tree!=NULL)
{
	inorder(tree->left);
	cout<<tree->root<<endl;
	inorder(tree->right);  
}
}
void preorder(node* tree)		//preorder fuction
{
if(tree!=NULL)
{
	cout<<tree->root<<endl;
preorder(tree->left);
preorder(tree->right);
}
}
void postorder(node* tree)		//postorder function
{

if(tree!=NULL)
{
	postorder(tree->left);	
	postorder(tree->right);
	cout<<tree->root<<endl;
}
}

	
};


int main(){
bst2 <int> p;
int a,s,c;

do{
cout<<"main menu"<<endl;
cout<<"1.create tree"<<endl;
cout<<"2.inorder traversal"<<endl;
cout<<"3.preorder traversal"<<endl;
cout<<"4.postorder traversal"<<endl;
cout<<"enter ur choice:";
cin>>c;
switch(c)
{
	case 1:
		cout<<"enter a no:";
		cin>>s;
		p.create(s,p.tree);
		break;
		
	case 2:
		p.inorder(p.tree);
		break;
	case 3:
		p.preorder(p.tree);
		break;
	case 4:
		p.postorder(p.tree);
		break;
	case 5:
		c=0;
}

cout<<"press 1 for continue:";
cin>>a;
}while(a==1);
return 0;
}


/* 			output

dell@ubuntu:~$ g++ bsttemp.cpp
dell@ubuntu:~$ ./a.out
enter the value of root=23
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:1
enter a no:12
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:45
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:1
enter a no:21
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:1
enter a no:54
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:1
enter a no:74
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:1
enter a no:4
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:2
4
12
21
23
54
74
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:3
23
12
4
21
54
74
press 1 for continue:1
main menu
1.create tree
2.inorder traversal
3.preorder traversal
4.postorder traversal
enter ur choice:4
4
21
12
74
54
23
press 1 for continue:
*/

	

