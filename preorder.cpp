#include<iostream>
#include<stdlib.h>
using namespace std;

 struct Node{
  int data;
  struct Node* a[2];
   Node(int d)
   {
    this->data=d;
    this->a[0]=NULL;
    this->a[1]=NULL;
   }
};

void preorder(struct Node* n1){
 if(n1==NULL)
  return;

  cout<<n1->data<<" ";

  preorder(n1->a[0]);  
preorder(n1->a[1]);
}
int main(){
struct Node* root=new Node(1);
  root->a[0]=new Node(2);
  root->a[0]->a[0]=new Node(3);
  root->a[0]->a[1]=new Node(4);
  root->a[1]=new Node(5);
preorder(root);
return 0;
}
