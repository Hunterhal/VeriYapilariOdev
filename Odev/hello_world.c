#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 128



struct node{
	int hash;
	float latitude;
	float longitude;
	float temperature;

	struct node* next;
	
};


int main()
{
	// head node is defined following codes
	struct node* head_node = (struct node*) malloc(sizeof(struct node)); 
	FILE* data_file;
	
	// open the file
	data_file = fopen("veri.txt","r");	
	if(data_file == NULL){ 
		printf("FILE cannot be found!");  // If file cannot open, return error
	}
	
	char buffer[MAX_SIZE];
	
	// create a node, this node point last node 
	struct node* iter_node = (struct node*) malloc(sizeof(struct node));
	iter_node = head_node;
	
	
	
	int iter_num = 1; // for the print number of line
	printf("\t   Hash \t   Latitude \t\t Longitude \t    Temperature\n\n");
	
	while ( fgets (buffer, sizeof(buffer), data_file) != NULL){
		sscanf(buffer,"%f %f %f", &iter_node->latitude, &iter_node->longitude, &iter_node->temperature);
				
		
		int temp = iter_node->latitude * pow(10,6)  + iter_node->longitude * pow(10,6);
		int hash = ((int)abs(temp)) % 1603;
		
		// create a next node
		iter_node->next = (struct node*) malloc(sizeof(struct node));
		iter_node->hash = hash;
		
		printf("%d.  Node : %d %20f %20f %20f\n",iter_num, iter_node->hash, iter_node->latitude, iter_node->longitude, iter_node->temperature);
		
		
		iter_node = iter_node->next;
		iter_num++;
	}
	
	
	printf("\n");
	

//Bubble Sort
	int swapped,temp,i,k;
	struct node *ptr1;
	struct node *lptr = NULL;
	
	
	
	do
	{
		swapped = 0;
		k=1999;
		ptr1 = head_node;
		while (ptr1->next != lptr && k != 0 )
		{
			if ( ptr1->hash <= ptr1->next->hash )
			{
				temp = ptr1->hash;
				ptr1->hash = ptr1->next->hash;
				ptr1->next->hash = temp;
				swapped=1;
				
			}
		
			ptr1 = ptr1->next;
			
			
			k--;
			
		}
		
		lptr = ptr1;
		printf(" %d. Node : %d \n",k+1, ptr1->hash);
	
		}
		while(swapped);
	
		
	fclose(data_file);

	return EXIT_SUCCESS;
	
}
