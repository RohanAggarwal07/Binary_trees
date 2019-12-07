#include<iostream>
#include<queue>
using namespace std;
struct Node
{
int data;
struct Node* next[2];
 Node(int data1)
{
	this->data=data1;
	this->next[0]=NULL;
	this->next[1]=NULL;
}
};

void inorder(struct Node* temp)
{
   if(temp==NULL)
	return;

	inorder(temp->next[0]);
	cout<<temp->data<<" ";
	inorder(temp->next[1]);
}

void insert_node(struct Node* temp,int data1)
{

queue<struct Node*> q;
q.push(temp);

while(!q.empty()){
struct Node* temp=q.front();
q.pop();


if(!temp->next[0])
{
temp->next[0]=new Node(data1);
break;
}
else
q.push(temp->next[0]);

if(!temp->next[1])
{
temp->next[1]=new Node(data1);
break;
}
else
q.push(temp->next[1]);
}

}
int main()
{
struct Node* root=new Node(10);
root->next[0]=new Node(11);
root->next[0]->next[0]=new Node(7);
root->next[1]=new Node(12);
inorder(root);
insert_node(root,40);
return 0;
}
