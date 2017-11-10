// ConsoleApplication40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef int T;

typedef struct Node 
{
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} N;

N* getn(T value, N *parent) 
{
	N* tmp = (N*)malloc(sizeof(N));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

void add(N **head, int value)
{
	N *tmp = NULL;
	N *ins = NULL;
	if (*head == NULL)
	{
		*head = getn(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else 
			{
				tmp->right = getn(value, tmp);
				return;
			}
		}
		else if (value < tmp->data) 
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getn(value, tmp);
				return;
			}
		}
		else 
		{
			exit(2);
		}
	}
}

N *search(N *root, T value)
{
	while (root)
	{
		if (root->data > value)
		{
			root = root->left;
			continue;
		}
		else if (root->data < value)
		{
			root = root->right;
			continue;
		}
		else 
		{
			return root;
		}
	}
	return NULL;
}

void printTree(N *root, const char *dir, int level)
{
	if (root)
	{
		printf("узел %d %s = %d\n", level, dir, root->data);
		printTree(root->left, "левый", level + 1);
		printTree(root->right, "правый", level + 1);
	}
}
void main()
{

	setlocale(LC_ALL, "Rus");
	N *root = NULL;
	add(&root, 9);
	add(&root, 10);
	add(&root, 14);
	add(&root, 8);
	add(&root, 7);
	add(&root, 5);
	add(&root, 1);
	add(&root, 2);
	add(&root, 3);
	add(&root, 4);

	printTree(root, "root", 0);
	printf("элемент 14 %d\n", search(root, 14)->parent->data);
	printf("элемент 7 %d\n", search(root, 7)->parent->data);
	printf("элемент 4 %d\n", search(root, 4)->parent->data);
	printf("------------------\n");

	system("pause");
}