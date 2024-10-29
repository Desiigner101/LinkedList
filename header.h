
typedef struct node {
	int id;
	float grade;
	char name[50];
	struct node *next;
}node;

void display(node *head);
node* insertFront(node *head, int id,float grade, char *name);
node* insertEnd(node *head, int id,float grade, char *name);

node* deleteFront(node *head);
node* deleteEnd(node *head);
node* deleteName(node *head,char *name);

int searchName(node *head,char *name);

