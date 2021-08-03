#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct contact {
	char first_name[20];
	char last_name[20];
	char email[30];
	struct contact *next;
};
typedef struct contact *CONTACT;

CONTACT add_new_contact(CONTACT head);
CONTACT delete_contact(CONTACT head);
void print_list_of_contacts(CONTACT head);
void save_to_file(CONTACT head);
CONTACT read_from_file();

int main(int argc, char *argv[])
{
	int ans, done = 0;
	CONTACT head = NULL;

	while (!done) {
		printf("\n0: exit\n");
		printf("1: add new contact\n");
		printf("2: delete contact\n");
		printf("3: print list of contacts\n");
		printf("4: save contacts\n");
		printf("5: read contacts\n");
		printf("\nenter command: ");
		scanf("%d", &ans);

		switch (ans) {
			case 0:
				done = 1;
				break;
			case 1:
				head = add_new_contact(head);
				break;
			case 2:
				head = delete_contact(head);
				break;
			case 3:
				print_list_of_contacts(head);
				break;
			case 4:
				save_to_file(head);
				break;
			case 5:
				head = read_from_file();
				break;
			default:
				printf("Invalid command\n");
				break;
		}
	}
}
CONTACT add_new_contact(CONTACT head)
{
	CONTACT p, new;

	new = (CONTACT) malloc(sizeof(struct contact));
	printf("First Name: ");
	scanf("%s", new->first_name);
	printf("Last Name: ");
	scanf("%s", new->last_name);
	printf("email: ");
	scanf("%s", new->email);

	if (head == NULL) {
		//insert into empty list 
		head = new;
		return head;
	}
	else if(strcmp(new->last_name, head->last_name) < 0) { 
		//insert at beginning
		new->next = head;
		head = new;
		return head;
	}

	//set p to point to the node after which the new node should be inserted
	p = head;
	while (p->next != NULL && strcmp(new->last_name, p->next->last_name) > 0)
		p = p->next;

	if(p->next != NULL) {
		//insert somewhere in middle of list
		printf("Inserting in middle\n");
		new->next = p->next;
		p->next = new;
	}
	else {
		//insert at the end
		p->next = new;
		new->next = NULL;
	}
	return head;
}
void print_list_of_contacts(CONTACT head)
{
	CONTACT p = head;

	while (p != NULL) {
		printf("%s %s %s\n", p->first_name, p->last_name, p->email);
		p = p->next;
	}
}
CONTACT delete_contact(CONTACT head)
{
	CONTACT p = head, del;
	CONTACT remove = (CONTACT) malloc(sizeof(struct contact));

	printf("Which contact do you want to delete?\n");
	printf("First Name: ");
	scanf("%s", remove->first_name);
	printf("Last Name: ");
	scanf("%s", remove->last_name);

	if (p == NULL)
		printf("No contacts found.\n");

	else {
		if (strcmp(remove->last_name, p->last_name) == 0 && 
		    p->next != NULL) {
			del = p->next;
			p->next = del->next;
			free(del);
		}
		while (p->next != NULL && strcmp(remove->last_name, 
			p->next->last_name)
			!= 0)
			p = p->next;
	
		if (p->next == NULL)
			printf("Contact not found.\n");
		if (strcmp(remove->last_name, p->next->last_name) == 0) {
			del = p->next;
			p->next = del->next;
			free(del);
			printf("Contact removed.\n");
		}
	}
	free(remove);
	return head;
}
void save_to_file(CONTACT head)
{
	char filename[50];

	printf("Enter name of file to save contacts to: ");
	scanf("%s", filename);
	FILE *fp = fopen(filename, "w");

	while (head->next != NULL) {
		fprintf(fp,"%s %s %s \n", head->first_name, head->last_name, 
			head->email);
		head = head->next;
	}
	fclose(fp);
}
CONTACT read_from_file()
{
	CONTACT head, p, new;
	char filename[50];

	printf("Enter name of file to read contacts from: ");
	scanf("%s", filename);
	FILE *fp = fopen(filename, "r");
	
	head = (CONTACT) malloc(sizeof(struct contact));
	fscanf(fp, "%s %s %s", head->first_name, head->last_name, head->email);
	head->next = NULL;
	p = head;

	while (!feof(fp)) {
		new = (CONTACT) malloc(sizeof(struct contact));
		fscanf(fp, "%s %s %s", new->first_name, new->last_name,
			new->email);
		p->next = new;
		p = new;
	}
	fclose(fp);
	return head;
}

