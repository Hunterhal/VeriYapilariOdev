/*
Veri Yapıları ve Programlama/2. Ödev
Nazım Altar Koca
040160006
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define TABLE_SIZE 1006 


//Hash Table element, linked list node
typedef struct node {
	float n1;
	float n2;
	float n3;
	struct node * next;
} node_t;

node_t *hashTable[TABLE_SIZE]; //Global Hash Table
node_t *sorted_list[TABLE_SIZE];

/*
This function calculates the Hash Value
*/
int getHastValue(float a, float b)
{
	double temp;
	int hash;
	temp = a * 1e6 + b * 1e6;
     hash = ((int)abs(temp)) % TABLE_SIZE;


	return hash;
}

/*
This function adds new node to the end of the linked list
*/
void add_end(node_t * head, float a, float b, float c)
{
	node_t * current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	current->next->n1 = a;
	current->next->n2 = b;
	current->next->n3 = c;
	current->next->next = NULL;
}

/*
This function prints out the list by iterating in the
list until the last node by checking if the next pointer
of the last node is NULL or not
*/
void print_list(node_t * head)
{
	node_t * current = head;
	int i = 1;

	while (current != NULL) {
		printf("%d element of current index of Hash Table is: ", i);
		printf("05%02f - %03f - %04f\n", current->n1, current->n2, current->n3);
		current = current->next;
		i++;
	}
}


int main(void){

    FILE* file = fopen("veri.txt", "r"); //opens veri.txt to read
    
    char line[256]; // an array to read text lines
    float latitude[TABLE_SIZE], longitude[TABLE_SIZE], temperature[TABLE_SIZE];// arrays to keep GPS values
    int i=0, counter=0, hash;
    int j,k,l,m,n; // counters for for loop
    double temp;

    // gets text values by line
    while (fgets(line, sizeof(line), file)&&i!=TABLE_SIZE) {
       
        //printf("%s", line); 
        sscanf_s(line, "%f %f %f\n", &latitude[i], &longitude[i], &temperature[i]);
    
//        temp = latitude * 1e6 + longitude * 1e6;
//        hash = ((int)abs(temp)) % 1000;
         i++;
        //printf("%d\n", hash);
    }
    
    //Initialize Hash Table
	for (j = 0; j < TABLE_SIZE; j++)
	{
		hashTable[j] = NULL;
	}

	//Write down values to the Hash Table
	for (k = 0; k < TABLE_SIZE; k++)
	{
		int hashValue = getHastValue(latitude[k], longitude[k]);

		//Look if indexed element is NULL or not
		if (hashTable[hashValue] == NULL)
		{
			hashTable[hashValue] = malloc(sizeof(node_t));
			hashTable[hashValue]->n1 = latitude[k];
			hashTable[hashValue]->n2 = longitude[k];
			hashTable[hashValue]->n3 = temperature[k];
			hashTable[hashValue]->next = NULL;
		}
		else
			add_end(hashTable[hashValue], latitude[k], longitude[k], temperature[k]);
	}

	printf("Hash Table is created !!!\n");
	printf("--------------------------------------------------\n");
	
	
	//Print Sorted Hash Table
	//
	for (l = 0; l < TABLE_SIZE; l++)
	{
		//Check if the Hash index is used or not
		if (hashTable[l] != NULL)
		{
			// prints index and the elements ascending order
			printf("%d indexed element of the Hash Table has:\n", l);
			print_list(hashTable[l]);
			printf("--------------------------------------------------\n");
		}
		
	}

	//Print the Hash Table
	for ( m = 0; m < TABLE_SIZE; m++)
	{
		//Check if the Hash index is used or not
		if (hashTable[m] == NULL)
		{
			//Only one number in this index
			printf("%d index not used !!!\n", m);
		
		printf("--------------------------------------------------\n");
		}
	}
	

	getchar();
   
    fclose(file);
      
      
}
