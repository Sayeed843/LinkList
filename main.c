#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

node* createList(node *head);
void display(node *head);
node* beginningInsertion(node *head);
node* nthPositionInsertion(node *head);
node* lastPositionInsertion(node *head);

int main(int argc, char **argv)
{
	int choose;

	
	node *head=NULL;
	for (int i =0;;i++)
	{
		printf("\n");
		printf("1: Create a Link List.\n");
		printf("2: Begining Insertion in a Link List.\n");
		printf("3: nth Position Insertion in a Link List.\n");
		printf("4: Last Insertion in a Link List.\n");
		printf("5: Display.\n");
	
		scanf("%d",&choose);
		if(choose==1)
	{
		// Create a Link List
		head=createList(head);
	}
	else if(choose==2)
	{
		head=beginningInsertion(head);
	}
	else if(choose==3)
	{
		head=nthPositionInsertion(head);
	}
	else if(choose==4)
	{
		head=lastPositionInsertion(head);
	}
	else if(choose==5)
	{
		display(head);
	}
	else
	{
		printf("System is Brake\n");
		break;
	}
	}	
	return 0;
}

node* createList(node *head)
{
	//node *head=NULL;		// initial state head is null
	node *temp=NULL;		// initial state temp is null
	node *temp1=NULL;		// initial state temp1 is null
	
	temp=(node*)malloc(sizeof(node));   // create a new Node
	printf("\nEnter the Node value: ");
	scanf("%d",&temp->data);		// insert data into node
	temp->next=NULL;				// make sure next state is null
	if(head==NULL)
	{
		head=temp;					// make sure, first node is head
	}
	else
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}	
	return head;
}
void display(node *head)
	{
		//printf("LOL");
		node *temp=NULL;
		if(head==NULL)
		{
			printf("Empty List.\n");
		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				printf("Data: ");
				printf("%d ",temp->data);
				printf("Next Address: ");
				printf("%x\n",temp->next);
				temp=temp->next;
			}
		}
		
	}

node* beginningInsertion(node *head)
{
	if (head==NULL)
	{
		printf("List is Empty.");
	}
	else
	{
		node *newHead=(node*)malloc(sizeof(node));
		printf("\nEnter the New Header Node Value: ");
		scanf("%d",&newHead->data);
		//newHead->next=NULL;
		
		newHead->next=head;
		head=newHead;
		
	}
	return head;
}

node* nthPositionInsertion(node *head)
{
	int position,count=0;
	printf("Which position you want to insert: ");
	scanf("%d",&position);
	node *temp=(node*)malloc(sizeof(node));
	printf("Enetr the new node value: ");
	scanf("%d",&temp->data);
	//temp->next=NULL;
	if(position==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		node *temp1=(node*)malloc(sizeof(node));
		temp1=head;
		while(count < position-2 && temp1->next!=NULL)
		{
			temp1=temp1->next;
			count++;
		}
		if (temp1->next==NULL)
		{
			printf("Your Position is invalid.\n");
		}
		else
		{
			temp->next=temp1->next;
			temp1->next=temp;
		}
	}
	return head;
}

node* lastPositionInsertion(node *head)
{
	node *temp=(node*)malloc(sizeof(node));
	printf("Enter the new node value: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	node *temp1=(node*)malloc(sizeof(node));
	
	temp1=head; 
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	return head;
}