#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*START = NULL,*START_BKP; //Both are used to store the start address
//START_BKP is used during start_delete, to have a backup of START pointer

void create();
void display();
//void sinsert(); //Start_insert
//void einsert(); //End_insert
//void minsert(); //Mid_insert
//void sdelete(); //Start_delete
//void mdelete(); //Mid_delete
//void edelete(); //End_delete
//void posdelete(); //Delete data from Particular position with particular number of data.

int main()
{
  create();
  display();
  //sinsert();
  //einsert();
  //minsert();
  //sdelete();
  //mdelete();
  //edelete();
  //posdelete();
}



void create()
{
  char enter;
  do
  {
    struct node *temp, *last; //temp is used to save the address of node, which is created the node
    //last is used to save the second last element address.
    temp = (struct node *)(malloc(sizeof(struct node))); //used to malloc the space.
    printf("Enter the value of the data");
    scanf("%d",&temp->data);
    temp->next = NULL;
    //if used to check START is NULL or not. If NULL then fill it with the first node address which is in temp
    if( START == NULL) 
    {
      START = temp;
      START_BKP = START;
      last = temp;
    }
    else
    {
      last->next = temp;
      last = temp;
    }
    printf("Enter y or no for more item\n");
    scanf(" %c",&enter); //used to ask, Is you want to enter more element or not.
  }
  while(enter == 'y' || enter == 'Y');
}

void display()
{
  struct node *temp;
  temp = START_BKP;
  printf("Your Linklist is---: ");
  while(temp != NULL)
  {
    printf("%d-->",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void sinsert()
{
  struct node *new, *start_ptr;
  new = (struct node *)(malloc(sizeof(struct node)));
  printf("Enter the value of the data");
  scanf("%d",&new->data);
  start_ptr = START;
  new->next = start_ptr;
  START = new;
  printf("Linklist after Sinsert function call");
  display();
}


void einsert()
{
  struct node *new, *start_ptr, *second_last;
  new = (struct node *)(malloc(sizeof(struct node)));
  printf("Enter the value of the data");
  scanf("%d",&new->data);
  new->next = NULL;
  start_ptr = START;
  while(start_ptr->next != NULL)
  {
    second_last = start_ptr;	  
    start_ptr = start_ptr->next;
  }
  second_last = start_ptr;
  second_last->next = new;
  printf("Linklist after einsert function call");
  display();

}


void minsert()
{
  struct node *new, *start_ptr, *second_last;
  int i=1,count=0,total=0;
  new = (struct node *)(malloc(sizeof(struct node)));
  printf("Enter the new Element");
  scanf("%d",&new->data);
  new->next == NULL;
  start_ptr = START;
  while(start_ptr != NULL)
  { 
    total++; //to know the total number of element.
    start_ptr = start_ptr->next;
  }
  start_ptr = START;
  if(total/2 == 0)
  {
    count = total/2;
  }
  else
  {
    count = (total + 1)/2;
  }
  printf("Linkedlist after midInsertion is -:\n");
  if(count >= 2)
  {
    for(i=1;i<=count-1;i++)
    {
      second_last = start_ptr;
      start_ptr = start_ptr->next;
    }
  }
  else
  {
    printf("Buffer is Under Flow\n");
  }
  second_last->next = new;
  new->next = start_ptr;
  display();
}


void sdelete()
{
  struct node *start_ptr, *second_last;
  printf("Your LinkedList after first Delete is -:\n");
  start_ptr = START_BKP;
  START_BKP = start_ptr->next;
  display();
}


void mdelete()
{
  struct node  *start_ptr, *second_last;
  int i=1,count=0,total=0;
  start_ptr = START;
  while(start_ptr != NULL)
  {
    total++;
    start_ptr = start_ptr->next;
  }
  start_ptr = START;
  if(total/2 == 0)
  {
    count = total/2;
  }
  else
  {
    count = (total + 1)/2;
  }

  for(i=1;i<=count-1;i++)
  {
    second_last = start_ptr;
    start_ptr = start_ptr->next;
  }
  second_last->next = start_ptr->next;
  printf("Linkedlist after midDelete is -:\n");
  display();
}



void edelete()
{
  struct node *new, *start_ptr, *second_last;
  start_ptr = START;
  while(start_ptr->next != NULL)
  {
    second_last = start_ptr;
    start_ptr = start_ptr->next;
  }
  second_last->next = NULL;
  printf("Linklist after edelete -:\n");
  display();
}

int posdelete()
{
  struct node *start_ptr, *second_last, *pre_mid_del_ptr, *mid_del_ptr;
  int i=1, pos, no_of_element, total=0;
  printf("Enter the Position from where You want to Delete  the Element, it should be greater the 2 and less then the total element");
  scanf("%d",&pos);
  printf("Enter the Number of Elemnt you want to delete, you cant delete last NODE");
  scanf("%d",&no_of_element);
  start_ptr = START;
  while(start_ptr != NULL)
  {
    total++;
    start_ptr = start_ptr->next;
  }
  mid_del_ptr = START;
  if(pos >= 2)
  {
    for(i=1;i<=pos-1;i++)
    {
      pre_mid_del_ptr = mid_del_ptr;
      mid_del_ptr = mid_del_ptr->next;
    }
  }
  else
  {
    printf("Buffer is Under Flow\n");
    return 0;
  }

  if(no_of_element<total || no_of_element >= 1)
  {
    for(i=1;i<=no_of_element-1;i++)
    {
      second_last = mid_del_ptr;
      start_ptr = second_last->next;
    }
  }
  else
  {
    printf("Entered inapporpriate Entery\n");
  }
  printf("Linklist after posdelete");
  pre_mid_del_ptr->next = start_ptr->next;
  if(start_ptr->next->next == NULL)
  {
    pre_mid_del_ptr->next = NULL;
  }
  printf("value at pre_mid_del_ptr->next is %d", pre_mid_del_ptr->next);
  display();  
}















