#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

int length(node* head)
{
	int str_length = 0;
	while (head != NULL) {
		str_length++;
		head = head->next;
	}
	return str_length;
}

char* toCString(node* head) 
{
	if (head == NULL) {
		return NULL;
	}

	int str_len = length(head);
	char* str = (char*) malloc(sizeof(char) * (str_len + 1));
	if (str == NULL) {
		return str;
	}

	node* temp = head;
	for(int i = 0; i < str_len; i++) {
		str[i] = temp->letter;
		temp = temp->next;
	}
	str[str_len] = '\0';
	return str;
}

void insertChar(node** pHead, char c) 
{
	node* new_node = (node*) malloc(sizeof(node));
	if (new_node == NULL) {
		return;
	}
	new_node->letter = c;
	new_node->next = NULL;

	if (*pHead == NULL) {
		*pHead = new_node;
	}
	else {
		node* tmp = *pHead;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new_node;
	}
}

void deleteList(node** pHead)
{
	while (*pHead != NULL) {
		node* temp = *pHead;
		*pHead = (*pHead)->next;
		free(temp);
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}