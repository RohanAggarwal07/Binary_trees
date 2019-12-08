#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
   int data;
   struct Node* next[2];
};

struct Node* newnode(int d)
{
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root->data=d;
    root->next[0]=root->next[1]=NULL;
return root;
}

struct Node* construct_tree(struct Node* root,int d)
{
  if(root==NULL)
   return(newnode(d));

  if(d<root->data)
  root->next[0]= construct_tree(root->next[0],d);
  
  if(d>root->data)
   root->next[1]=construct_tree(root->next[1],d);

return root;
}

void print_tree(struct Node* root)
{
	if(root!=NULL)
	{
	   print_tree(root->next[0]);
	   cout<<root->data<<" ";
	   print_tree(root->next[1]);
	}
}


int main(int argc,char* argv[])
{
int arr[argc-1];
int n=argc-1;
for(int i=1;i<=n;i++)
{
	arr[i-1]=atoi(argv[i]);
}
struct Node* root=NULL;
root=construct_tree(root,arr[n-1]);
for(int i=n-2;i>=0;i--)
{
construct_tree(root,arr[i]);
}
print_tree(root);
return 0;
}

