#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int hash;
	float latitude;
	float longitude;
	float temperature;
	struct Node *next;
}Node;

void push(struct Node** head_ref, int hash,float longitude,float latitude,float temperature)
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    new_node->hash=hash;
    new_node->longitude=longitude;
	new_node->latitude=latitude;
	new_node->temperature=temperature;
	
    new_node->next = (*head_ref); 
  
    (*head_ref)    = new_node;
 
} 


void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf("%d\t%f\t%f\t%f\n",node->hash,node->longitude,node->latitude,node->temperature);
	node = node->next; 
  } 
}

int sizeList(struct Node *node)
{	
	int count=0;
	while (node != NULL)
	{
		count = count +1 ;
		node = node->next;
	
	}
	return count;
	
}
struct Node* SortedMerge(struct Node* a, struct Node* b); 
void FrontBackSplit(struct Node* source, 
                    struct Node** frontRef, struct Node** backRef); 
  

  void MergeSort(struct Node** headRef) 
{ 
    struct Node* head = *headRef; 
    struct Node* a; 
    struct Node* b; 
  
    
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  

    FrontBackSplit(head, &a, &b); 
  
  
    MergeSort(&a); 
    MergeSort(&b); 
  
 
    *headRef = SortedMerge(a, b); 
} 
  

struct Node* SortedMerge(struct Node* a, struct Node* b) 
{ 
    struct Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->hash <= b->hash) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
void FrontBackSplit(struct Node* source, 
                    struct Node** frontRef, struct Node** backRef) 
{ 
    struct Node* fast; 
    struct Node* slow; 
    slow = source; 
    fast = source->next; 
 
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 

    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 


	int main()
{	
  	struct Node* head = NULL; 
   	FILE *veri;
   	char satir[100];
   	char *c;	
 	float latitude,longitude,temperature;
   veri = fopen("veri.txt","r");
   while (c != NULL) {
     c = fgets(satir,100,veri); 
     if (c != NULL)
 		sscanf(satir, "%f %f %f", &latitude, &longitude, &temperature); 
   		//printf("latitude is  %f\n",latitude);
   		//printf("Longitude is  %f\n",longitude);
   		//printf("Temperature is  %f\n",temperature);
   		double temp;
		   int hash; //Hashing
   		temp = latitude * 1e6 + longitude * 1e6;
   		//printf("%f\t",temp);
		hash = ((int)abs(temp)) % 1034;
		//printf ("Hash value is  %d\n",hash);

   		push(&head, hash,longitude,latitude,temperature);
  		
	}
 	printList(head);
 	printf("Size of list is  %d ",sizeList(head));
 	MergeSort(&head);
 	printf("Sorted list is\n");
 	printList(head);
 	
   }; 
   
