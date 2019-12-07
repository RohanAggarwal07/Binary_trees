#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
   int data;
   struct Node* next[2];

};
struct Node* newnode(int d){
     struct Node* root= (struct Node *)malloc(sizeof(struct Node));  
     root->data=d;
     root->next[0]=NULL;
     root->next[1]=NULL;
  return root;
   }

struct Node* construct_tree(struct Node* root,int c){
  if(root==NULL)
	return newnode(c);
  if(c<root->data)
	root->next[0]=construct_tree(root->next[0],c);
  if(c>root->data)
	root->next[1]=construct_tree(root->next[1],c);
return root;
}

void printtree(struct Node* root){
	if(root!=NULL)
	{
	   printtree(root->next[0]);
           cout<<root->data<<" ";
	   printtree(root->next[1]);
	}
}
int main(int argc,char* argv[]){
   int arr[argc-1];
   int n=argc-1;
        for(int i=1;i<=n;i++)
	{  
	   arr[i-1]=atoi(argv[i]);
   	}
	struct Node* root=NULL;
	root=construct_tree(root,arr[0]);
	for(int i=1;i<n;i++)
	{
	  construct_tree(root,arr[i]);
	}
	printtree(root);
return 0;
}
