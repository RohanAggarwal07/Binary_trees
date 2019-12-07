#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
public:
int data;
node* a[2];
};

int max_depth(node* node){
  if(node==NULL)
     return 0;
  else{
int maxl=  max_depth(node->a[0]);
int maxr= max_depth(node->a[1]);
  return(maxl>maxr?maxl+1:maxr+1);
}
}

node* n_node(int a){
   node* n=new node();
      n->data=a;
      n->a[0]=NULL;
      n->a[1]=NULL;	
  return(n);
}

int main()
{
    node* root=n_node(1);
          root->a[0]=n_node(2);
	  root->a[1]=n_node(3);
	  root->a[0]->a[0]=n_node(4);
	  root->a[0]->a[1]=n_node(5);
cout<<"max depth of the tree is "<<max_depth(root);	
return 0;
}
