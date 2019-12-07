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
 
void Merge(int *a, int low, int high, int mid)
{
        int i, j, k, temp[high-low+1];
        i = low;
        k = 0;
        j = mid + 1;
        while (i <= mid && j <= high)
        {
                if (a[i] < a[j])
                {
                        temp[k] = a[i];
                        k++;
                        i++;
                }
                else
                {temp[k] = a[j];
                        k++;
                        j++;
                }
        }
        while (i <= mid)
        {
                temp[k] = a[i];
                k++;
                i++;
        }
        while (j <= high)
        {
                temp[k] = a[j];
                k++;
                j++;
        }
for (i = low; i <= high; i++)
        {
                a[i] = temp[i-low];
        }
}
    void MergeSort(int *a,int low,int high)
	{            
		int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

void print(Node* root)
  {
    if(root!=NULL)
     {
        print(root->next[0]);
        cout<<root->data<<" ";
        print(root->next[1]);
     }
  }

int main(int argc,char* argv[]){
   int arr[argc-1];
   int ar[argc-1];
   int j=0;
       for(int i=1;i<argc;i++)
          {
        arr[j]=atoi(argv[i]);
        j++;
          }
   Node* root=NULL;
   root=construct(arr,root,0,j);
   cout<<"Inorder for given binary tree is-:"<<endl;

   MergeSort(arr, 0, j);
	for(int i=2;i<j;i++)
	{
	   ar[i-2]=arr[i];
	}
	cout<<endl;
	print(root);
    for(int i=0;i<j-2;i++)
{
cout<<ar[i];
}

return 0;
}
