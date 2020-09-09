#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*START = NULL;





void create();
void display();
void sinsert();
void einsert();
void minsert();
void posinsert();
void sdelete();
void edelete();
void mdelete();
void posdelete();
int main()
{
  create();
  display();
 //sinsert();
 //einsert();
 //minsert();
 //posinsert();
 //sdelete();
 //edelete();
 //mdelete();
 posdelete();
}

void create()
{
  char c;
  do
  {
    struct node *temp, *last;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(START == NULL)
    {
      START = temp;
      last = temp;
    }
    else
    {
      last->link = temp;
      last = temp;
    }
    printf("Enter Y for Yes, to Enter More Data\n");
    scanf(" %c",&c);
  }while(c == 'y' || c == 'Y');
}


void display()
{
  struct node *temp;
  temp = START;
  while(temp != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->link;
  }
  printf("NULL");
}

void sinsert()
{
  struct node *temp, *old;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("Enter value you want to ADD in Starting\n");
  scanf("%d",&temp->data);
  old = START;
  START = temp;
  temp->link = old;
  printf("\n");
  display();
}

void einsert()
{
  struct node *temp, *start_copy, *second_last;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("\nEnter value you want to ADD in End\n");
  scanf("%d",&temp->data);
  start_copy = START;
  while(start_copy != NULL)
  {
    second_last = start_copy;
    start_copy = start_copy->link;
  }
  second_last->link = temp;
  temp->link = NULL;
  printf("\n");
  display();
}

void minsert()
{

  struct node *temp, *start_copy, *second_last;
  int count = 0, i = 1;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("\nEnter value you want to ADD in Middle\n");
  scanf("%d",&temp->data);
  temp->link = NULL;
  start_copy = START;
  while(start_copy != NULL)
  {
    count++;
    start_copy = start_copy->link;
  }
  start_copy = START;
  if(count%2 == 0)
  {
    count = count/2;
  }
  else
  {
    count = (count+1)/2;
  }
  if(count >= 2)
  { 
    while(i <= count)
    {
    second_last = start_copy;
    start_copy = start_copy->link;
    i++;
    }
  }
  else
  {
    printf("Buffer is UnderFlow");
  }
  second_last->link = temp;
  temp->link = start_copy;
  printf("\n");
  display();
}

void posinsert()
{

  struct node *temp, *start_copy, *second_last, *old;
  int count = 0, i = 1;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("\nEnter value you want to ADD on position\n");
  scanf("%d",&temp->data);
  temp->link = NULL;
  printf("Enter Position on which you want Number to be Add\n");
  scanf("%d",&count);
  start_copy = START;
  if(count == 1)
  {
    old = START;
    START = temp;
    temp->link = old;
  }
  else
  {
    while(i < count)
    {
      second_last = start_copy;
      start_copy = start_copy->link;
      i++;
    }
    second_last->link = temp;
    temp->link = start_copy;
  }
  printf("\n");
  display();
}

void sdelete()
{
  printf("\nAfter Deleting First Element Linked List is :-");
  START = START->link;
  display();
}

void edelete()
{
  struct node *start_copy, *second_last;
  start_copy = START;
  while(start_copy->link != NULL)
  {
    second_last = start_copy;
    start_copy = start_copy->link;
  }
  second_last->link = NULL;
  printf("\n After Deleting Last Element From LinkedList :-");
  display();
}

void mdelete()
{

  struct node *start_copy, *second_last;
  int count = 0, i = 1;
  start_copy = START;
  while(start_copy != NULL)
  {
    count++;
    start_copy = start_copy->link;
  }
  start_copy = START;
  if(count%2 == 0)
  {
    count = count/2;
  }
  else
  {
    count = (count+1)/2;
  }
  if(count >= 2)
  { 
    while(i < count)
    {
    second_last = start_copy;
    start_copy = start_copy->link;
    i++;
    }
  }
  else
  {
    printf("Buffer is UnderFlow");
  }
  second_last->link = start_copy->link;
  printf("\n");
  display();
}

void posdelete()
{

  struct node *start_copy, *second_last;
  int count = 0, i = 1;
  start_copy = START;
  printf("\nEnter Position of number you want to delete\n");
  scanf("%d",&count);
  if(count == 1)
  {
    START = START->link;
  }
  else
  {
    while(i < count)
    {
    second_last = start_copy;
    start_copy = start_copy->link;
    i++;
    }
    second_last->link = start_copy->link;
  }
  printf("\n");
  display();
}

