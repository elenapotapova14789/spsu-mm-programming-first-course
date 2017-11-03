// ConsoleApplication35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct list
{

	int arr;
	struct list *next;

}l;
l*head = NULL;

void add(int arr)
{
	l *new = malloc(sizeof(l));
	if (!new) return;
	new->arr = arr;
	new->next = head;
	head = new;
}

l* getLast(l *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	while (head->next) 
	{
		head = head->next;
	}
	return head;
}

void addToEnd(l *head, int arr)
{
	l *last = getLast(head);
	l *tmp = (l*)malloc(sizeof(l));
	tmp->arr = arr;
	tmp->next = NULL;
	last->next = tmp;
}

int get(l **head)
{
	l* prev = NULL;
	int elm;
	if (head == NULL) 
	{
		exit(-1);
	}
	prev = (*head);
	elm = prev->arr;
	(*head) = (*head)->next;
	free(prev);
	return elm;
}

void printLinkedList(const l *head)
{
	while (head) 
	{
		printf("%d ", head->arr);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	printLinkedList(head);

	addToEnd(head, 11);
	addToEnd(head, 12);
	addToEnd(head, 13);
	addToEnd(head, 14);
	addToEnd(head, 15);
	addToEnd(head, 16);
	addToEnd(head, 17);
	addToEnd(head, 18);
	printf("%d\n", get(&head));
	printLinkedList(head);
	system("pause");
	return 0;
}
