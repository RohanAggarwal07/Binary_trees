#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
class node
{
public:
int data;
node* a[2];
};


void traversal(node* root){
  if(root!=NULL)
    return;
  else
   queue<node *> q1;
    q1.push(root);

 while(q1.empty==false)
{
	node* n=q1.front();
	cout<<n->data<<" ";
	q1.pop();

 if(n->a[0]!=NULL)
	q1.push(n->a[0]);

 if(n->a[1]!=NULL)
	q1.push(n->a[1]);
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
traversal(root);
return 0;
}
