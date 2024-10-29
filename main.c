#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	node *head=NULL;
	/*node *p;
	node *newNode=(node*)malloc(sizeof(node)); //1
	newNode->id=1;  //2
	newNode->grade=4.5;
	strcpy(newNode->name,"Maria");
	
	
	newNode->next =head; //4
	head=newNode;//5
	
	
	newNode=(node*)malloc(sizeof(node)); //1
	newNode->id=2;  //2
	newNode->grade=3.5;
	strcpy(newNode->name,"Joe");
	
	
	newNode->next = head->next;//4
	head->next=newNode;
	
	display(head);
	*/
	
	int choice;
	int id;
	float grade;
	char name[50];
	do{
		printf("\n\n1-Insert Front\n");
		printf("2-Insert End\n");
		printf("3-Delete Front\n");
		printf("4-Delete End\n");
		printf("5-Delete a Name\n");
		printf("6-Display\n");
		printf("7-Exit\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Input id: ");
					scanf("%d",&id);
					printf("Input grade: ");
					scanf("%f",&grade);
					printf("Input name: ");
					scanf("%s",&name);
					head = insertFront(head,id,grade,name);
					break;
			case 2: printf("Input id: ");
					scanf("%d",&id);
					printf("Input grade: ");
					scanf("%f",&grade);
					printf("Input name: ");
					scanf("%s",&name);
					head = insertEnd(head,id,grade,name);
					break;
			case 3:
					head=deleteFront(head);
					display(head);
					break;
			case 4:
					head=deleteEnd(head);
					display(head);
					break;
			case 5: printf("Input name: ");
					scanf("%s",&name);
					if(searchName(head,name)==1){
						head=deleteName(head,name);
						display(head);
					}
					else
						printf("%s is not existing.\n",name);
					break;
			case 6: display(head);
					break;
		}
		
	}while(choice !=7);
	return 0;
}

