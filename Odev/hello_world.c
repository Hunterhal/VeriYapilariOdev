#include <stdio.h>
#include <stdlib.h>


FILE *veri;

//node definition

// A linked list node 
struct Node 
{ 
  float latitude;
  float longitude;
  float temperature;
  float hash;
  struct Node *next; 
}; 

//hash function definition
float Hash(int latitude, int longitude){
	float hash, temp;
	temp = latitude * 1e6 + longitude * 1e6;
	hash = ((int)abs(temp)) % 1042; // student id: 040150042 => 1000 + 0042	
	return hash;
}

// inserting new node
void push(struct Node** head_ref, float latitude, float longitude, float temperature, float hash) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    /* 2. put in the data  */
    new_node->latitude  = latitude; 
    new_node->longitude  = longitude; 
    new_node->temperature  = temperature;
	new_node->hash  = hash;  
   
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
   
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
} 


main(){
	float latitude, longitude, temperature, hash;
	veri = fopen("veri.txt", "r");
	
	struct Node* head = NULL; // head node
	
	while(!feof(veri)){
		fscanf(veri, "%f %f %f", &latitude, &longitude, &temperature);
		hash = Hash(latitude, longitude);
		push(&head, latitude, longitude, temperature, hash);
	}
	
    fclose(veri);
}

