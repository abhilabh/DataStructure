#include<iostream>
//#include<conio.h>
#include<cstring>

using namespace std;

class Huffman{
private:
        class Node{
        public:
               char c;
               double info;
               Node* left;
               Node* right;      
        };
        int size;
        //char* symbols;
        //double* prob;
        Node* root;
        Node** arr;
        char* code;
public:
       //constructor
       
       Huffman(int num);
       void insertsort(int begindex);//to sort probability array
       Node* getnode(double n,char sym){
             Node* ptr;
             ptr=new Node;
      
               ptr->info=n;
               ptr->left=ptr->right=NULL;
               ptr->c=sym;
               return ptr;                      
          
                 return 0; 
       } 
       
       void formTree();
       void gethuffcode(Node* ptr);
       void inorder(Node* p);
       Node* getroot(){return root;}
       void printarr(int begindex);
              
};

Huffman::Huffman(int num){
            size=num;
            arr=new Node*[size];
            double prob;
            char sym; 
            cout<<"Enter the symbols followed by their probabilities."<<endl;
            for(int i=0;i<size;i++){
                 cin>>sym;
                 cin>>prob;
               
                      arr[i]=getnode(prob,sym);
                 
                         
            }
            root=NULL;
            code=new char[num];
          //  code[0]=' ';
            //code[1]='\0';
            
            
       }

void Huffman:: insertsort(int begindex){
     for(int k=begindex+1;k<size;k++){
          Node* element=arr[k];
          int i;
          for(i=k-1;i>=begindex && (arr[i]->info)>(element->info);i--){
               arr[i+1]=arr[i];             
          }
          arr[i+1]=element;        
     }          
}

void Huffman::formTree(){
     for(int i=0;i<size-1;i++){
          insertsort(i);
          cout<<"The sorted array is: "<<flush;
          printarr(i);
          Node* ptr=new Node;
          ptr->info=(arr[i]->info)+(arr[i+1]->info);
          ptr->c='\0';
          ptr->left=arr[i];
          ptr->right=arr[i+1];
          root=ptr;
          arr[i+1]=ptr;
       //   getch();        
     }
     
     
     cout<<"Tree formation is complete."<<endl;
     cout<<"The value at root is: "<<root->info<<endl;
    // getch();
}

void Huffman::inorder(Node* p){
     //if(p==NULL){
       //   cout<<"Root is empty."<<endl;
     //}
     if(p!=NULL){
          inorder(p->left);
      //   getch();         
          cout<<p->info<<"  "<<flush;
          inorder(p->right);
     }     
}

void Huffman::printarr(int begindex){
     //cout<<"The prob array is: "<<flush;
     for(int i=begindex;i<size;i++){
             cout<<arr[i]->info<<" "<<flush;       
     } 
     cout<<endl;    
}

void Huffman::gethuffcode(Node* ptr){ 
     if((ptr->left==NULL)&&(ptr->right==NULL)){
          cout<<"Code for "<<(ptr->c)<<" is : "<<code<<endl;                                                                                       
     }
     if(ptr->left!=NULL){
               code=strcat(code,"0");
               gethuffcode(ptr->left);
     }    
     if(ptr->right!=NULL){
          code=strcat(code,"1");                
          gethuffcode(ptr->right);
     }    
 
}

int main(){
    int num;
    //char* s;
    cout<<"Enter the number of symbols: "<<flush;
    cin>>num;
    //s=new char[num];
    //s="\0";
    Huffman obj(num);  
    obj.formTree();
    if(obj.getroot()==NULL)cout<<"The root is NULL."<<endl;
    else{
         cout<<"Value at root is: "<<(obj.getroot())->info<<endl;
         obj.inorder(obj.getroot());
         cout<<"Value at root is: "<<(obj.getroot())->info<<endl;
         cout<<"Moving on to gethuffcode."<<endl;
    
         obj.gethuffcode(obj.getroot());
    }
   // getch();
}

