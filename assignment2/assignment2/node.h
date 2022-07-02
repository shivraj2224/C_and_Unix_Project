#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node* head=NULL;

void insertNode (int val)
{
  struct Node *newNode = malloc (sizeof (struct Node));

  if (newNode == NULL)
    {
      fprintf (stderr, "Error in malloc return.\n");
      exit (1);
    }

  newNode->data = val;
  newNode->next = NULL;

  if (head == NULL)
    {
      head = newNode;
      return;
    }

  if (head->data > val)
    {
      newNode->next = head;
      head = newNode;
      return;
    }

  struct Node *temp = head, *prev = NULL;

  while (temp != NULL && temp->data < val)
    {
      prev = temp;
      temp = temp->next;
    }

  newNode->next = temp;
  prev->next = newNode;

  return;
}

void deleteNode (int val)
{
  struct Node *temp = head, *prev = NULL;

  while (temp != NULL && temp->data < val)
    {
      prev = temp;
      temp = temp->next;
    }

  if (temp == NULL || temp->data != val)
    {
      return;
    }

  if (prev == NULL)
    {
      head = temp->next;
    }
  else
    {
      prev->next = temp->next;
    }

  free (temp);
  temp = NULL;
}

void displayLL()
{
  struct Node *temp = head;

  while (temp != NULL)
    {
      printf ("%d->", temp->data);
      temp = temp->next;
    }

  printf ("NULL\n");
}
