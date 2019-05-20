#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
struct Node  
{ 
  float hash;
  float data1,data2,data3; 
  struct Node *next; 
}; 
void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %f %f %f \n", node->data1,node->data2,node->data3); 
     node = node->next; 
  } 
} 
void append(struct Node** head_ref, float new_data1,float new_data2,float new_data3,float new_hash) 
{ 
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  
    new_node->data1  = new_data1;
	new_node->data2  = new_data2;
	new_node->data3  = new_data3; 
    new_node->hash  = new_hash;
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    
    while (last->next != NULL) 
        last = last->next; 
  
    
    last->next = new_node; 
    return; 
} 
void swapNodes(struct Node** head_ref, struct Node* currX, 
               struct Node* currY, struct Node* prevY) 
{ 
    
    *head_ref = currY; 
  
    
    prevY->next = currX; 
  
    
    struct Node* temp = currY->next; 
    currY->next = currX->next; 
    currX->next = temp; 
}  
struct Node* recurSelectionSort(struct Node* head) 
{ 
    
    if (head->next == NULL) 
        return head; 
  
    
    struct Node* min = head; 
  
    
    struct Node* beforeMin = NULL; 
    struct Node* ptr; 
  
    
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) { 
  
       
        if (ptr->next->hash < min->hash) { 
            min = ptr->next; 
            beforeMin = ptr; 
        } 
    } 
  
    if (min != head) 
        swapNodes(&head, head, min, beforeMin); 
  
    head->next = recurSelectionSort(head->next); 
  
    return head; 
} 
void sort(struct Node** head_ref) 
{ 
    if ((*head_ref) == NULL) 
        return; 
    *head_ref = recurSelectionSort(*head_ref); 
} 
int main ( void )
{  struct Node* head = NULL;
   FILE *file = fopen ( "Veri.txt", "r" );
   if ( file != NULL )
   {  float latitude,longitude,temperature,temp,hash;
      char line [ 50 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         sscanf_s(line, "%f %f %f", &latitude, &longitude, &temperature);
         temp = latitude * 1e6 + longitude * 1e6;
         hash = ((int)abs(temp)) % 1015;
         append(&head,latitude,longitude,temperature,hash);
      }
      fclose ( file );
   }
   else
   {
     printf("Dosya acilamadi\n"); return 0;
     return 0;
   }
   printf("Not sorted list:**************************************************************************\n");
   printList(head);
   sort(&head);
   printf("Sorted list:******************************************************************************\n");
   printList(head);
   return 0;
   
}

