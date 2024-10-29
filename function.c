#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void display(node *head){
	node *p=head;
	while(p!=NULL){
		printf("Id:%d\t",p->id);
		printf("Name:%s\t",p->name);
		printf("Grade:%0.1f\n",p->grade);
		p=p->next;
	}
}
node* insertEnd(node *head, int id,float grade, char *name){
	node *newNode,*p;
	newNode= (node*)malloc(sizeof(node));
	newNode->id = id; 
	newNode->grade=grade;
	strcpy(newNode->name,name);
	
	if(head==NULL){ //list is empty
		newNode->next=head;
		head=newNode;
	}else{
		p=head;
		while(p->next != NULL)
			p=p->next;
		newNode->next=p->next;
		p->next=newNode;
	}
	return head;
}


node* insertFront(node *head, int id,float grade, char *name){
	node *newNode;
	newNode= (node*)malloc(sizeof(node));
	newNode->id = id; 
	newNode->grade=grade;
	strcpy(newNode->name,name);
	
	
	newNode->next=head;
	head=newNode;
}

node* deleteFront(node *head){
	node *temp;
	if(head==NULL)
		printf("Linkedlist is empty.\n");
	else{
		temp=head;
		head=head->next;
		printf("Deleted id: %d\n",temp->id);
		free(temp);
	}
	return head;
}
node* deleteEnd(node *head){
	node *temp, *p;
	if(head==NULL)
		printf("Linkedlist is empty.\n");
	else if(head->next==NULL)
		head=deleteFront(head);
	else{
		p=head;
		while(p->next->next!=NULL)
			p=p->next;
		temp=p->next;
		p->next=p->next->next;
		printf("Deleted id: %d\n",temp->id);
		free(temp);
		
	}
	return head;
}
node* deleteName(node *head,char *name){
	node *temp, *p;
	if(head==NULL)
		printf("Linkedlist is empty.\n");
	else if(strcmp(head->name,name)==0)
		head=deleteFront(head);
	else{
		p=head;
		while(strcmp(p->next->name,name)!=0)
			p=p->next;	//Maria
		temp=p->next;
		p->next=p->next->next;
		printf("Deleted name: %s\n",temp->name);
		free(temp);
	}
	return head;
}

int searchName(node *head,char *name){
	node *p=head;
	while(p!=NULL){
		if(strcmp(p->name,name)==0)
			return 1;
		p=p->next;
	}
	return 0;
}
