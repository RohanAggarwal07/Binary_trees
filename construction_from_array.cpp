#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
  public:
  int data;
  Node* next[2];
         Node(int data)
	{
	  this->data=data;
	  this->next[0]=NULL;
	  this->next[1]=NULL;
	}
};

Node* construct(int arr[],Node* root,int i,int n)
   {
	if(i<n)
	{
	 Node* temp=new Node(arr[i]);
	    root=temp;
         if((arr[2*i+1])!=-1)
	        root->next[0]=construct(arr,root->next[0],2*i+1,n);			
	 if((arr[2*i+2])!=-1)
    	        root->next[1]=construct(arr,root->next[1],2*i+2,n);		
 	}
   return root;
   }

 void print(Node* root)
  {
    if(root!=NULL)
     {
	print(root->next[0]);
	cout<<(root->data);
	print(root->next[1]);
     }
  }
	  
int main(int argc,char* argv[]){
   int arr[argc-1];
   int j=0;
       for(int i=1;i<argc;i++)
          {
	arr[j]=atoi(argv[i]);
	j++;
	  }
   Node* root=NULL;
   root=construct(arr,root,0,j);
   print(root);
return 0;
}
