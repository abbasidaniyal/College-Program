#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int data;
	struct Element *L, *R;

}*root=NULL;

typedef struct Element node;

void find(node* parent,int ele)
{

	if (parent->data==ele)
	{
		printf("\n\nElement Exists!!");
		return;
	}
	else if (parent->data > ele)
	{
		if (parent->L!=NULL)
			find(parent->L,ele);

		else
		{
			printf("\n\nNOT FOUND\n" );
			return;
		}
	}
	else if (parent->data < ele)
	{
		if(parent->R!=NULL)	
			find(parent->R,ele);	
		else
		{
			printf("\n\nNOT FOUND\n" );
			return;
		}
	}

}





void searchele()
{
	int ele;
	printf("\nEnter Element to be Searched - "); scanf("%d",&ele);

	find(root,ele);

}





void postdisplay(node* parent)
{


	if (parent->L!=NULL)
		postdisplay(parent->L);
	

	if (parent->R!=NULL)
		postdisplay(parent->R);



	printf(" %d ", parent->data );

}



void predisplay(node* parent)
{
	printf(" %d ", parent->data );

	if (parent->L!=NULL)
		predisplay(parent->L);


	if (parent->R!=NULL)
		predisplay(parent->R);

}



void indisplay(node* parent)
{
	

	if (parent->L!=NULL)
		indisplay(parent->L);
	
	printf(" %d ", parent->data );
	
	if (parent->R!=NULL)
		indisplay(parent->R);

}








node* delfind(node* parent,int ele)
{

	if (parent->data==ele)
	{
		return parent;
	}
	else if (parent->data > ele)
	{
		if (parent->L!=NULL)
			delfind(parent->L,ele);

		else
		{
			//printf("\n\nNOT FOUND\n" );
			return NULL;
		}
	}
	else if (parent->data < ele)
	{
		if(parent->R!=NULL)	
			delfind(parent->R,ele);	
		else
		{
			//printf("\n\nNOT FOUND\n" );
			return NULL;
		}
	}

}


node* inordersuc(node* parent)
{
	node *temp;
	if (parent->L!=NULL)
		temp=inordersuc(parent->L);
	else 
		temp=parent;

	return temp;

}






node* delit(node* parent,int ele)
{

	if(root==NULL)
		return root;


	if ( parent->data > ele )
	{
		parent->L = (delit(parent->L,ele));
		return parent;
	}	
	else if( parent->data < ele)
	{
		parent->R = (delit(parent->R,ele));
		return parent;	
	}	
	else
	{
		if (parent->L==NULL)
		{
			node *temp=parent->R;
			return temp;

		} 
		else if (parent->R==NULL)
		{
			node *temp=parent->L;
			return temp;
			
		}
		else
		{
			node *temp=inordersuc(parent->R);
			parent->data=temp->data;
			delit(parent->R,temp->data);
			return parent;
		}

	}



}




void drawtree()
{

}







void del()
{
	int ele;
	printf("\n\nEnter Element to be Deleted ");
	scanf("%d",&ele);

	root=delit(root,ele);

}





void add()
{


	node* newnode;
	newnode = (node *)malloc(sizeof(node));

	int Data;
	printf("\n\nEnter Data -");
	scanf("%d",&Data);

	newnode->data=Data;

	
	newnode->L=NULL;
	newnode->R=NULL;



	node *temp=root;

	
	if (root==NULL)
	{
		root=newnode;
		return;
	}

	
	for (;  ; )
	{
		if ( Data > temp->data )
		{
			if (temp->R==NULL)
			{
				temp->R=newnode;
				return;
			}
			else
				temp=temp->R;
		}	
		else if ( Data < temp->data )
		{
			if (temp->L==NULL)
			{
				temp->L=newnode;
				return ;
			}
			else
				temp=temp->L;
		}
		else
		{
			printf("\n\nDuplicate Value! \n");
			free(newnode);
			return;
		}	

	
	}


}




int main(int argc, char const *argv[])
{
	int choice;
	do
	{
		printf("\n\nBinary SearchTree!!  \n\n1. Add\n2. Delete\n3. Display pre order\n4. Display post order\n5. Display in order\n6. Search\n7. Exit\n\n Enter Choice :- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: add();break;
			case 2: del(); break;
			case 3: printf("PreOrder - "); predisplay(root); break;
			case 4: printf("PostOrder - "); postdisplay(root); break;
			case 5: printf("InOrder - "); indisplay(root); break;
			case 6: searchele();
			case 7: break;
			default : printf("\n\nINVALID CHOICE");
		}


	}while(choice!=7);


	return 0;
}