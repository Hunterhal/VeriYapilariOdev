// DENİZ ÜRGÜN
// 040160113

#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int hash;
	float latitude;
	float longitude;
	float temperature;
	struct Node *next;
};
struct Node *add_Node(struct Node *head,int hash, float latitude, float longitude, float temperature)
{
		head = (struct Node*)malloc(sizeof(struct Node));
		head->hash = hash;
		head->latitude = latitude;
		head->longitude = longitude;
		head->temperature = temperature;
		head->next = NULL;
		return head;

	struct Node *iter = head;
	while(iter->next != NULL)
	{
		iter = iter->next;
		iter->next->hash = hash;
		iter->next->latitude = latitude;
		iter->next->longitude = longitude;
		iter->next->temperature = temperature;
		iter->next->next = NULL;
		return head;
	}
}
int calculate_hash(float latitude, float longitude) 
{
	float temp;
	int hash;
	
	temp = latitude * 1e6 + longitude * 1e6;
	hash = ((int)abs(temp)) % 1113;

	return hash;
}
void printList(struct Node *head) 
{
	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("Hash Values> %.4d\tLat>\t%.7f\tLong>\t%.7f\tTemp>\t%.1f\n",temp->hash, temp->latitude, temp->longitude, temp->temperature );
		temp = temp->next;
	}
}

struct Node *move(struct Node *a, struct Node *b)
{
	a->next = b->next;
	b->next = a;
	return b;
}
struct Node *bubbleSort(struct Node *head)
{
	if(head == NULL)
		return NULL;
	
	if(head->next != NULL && head->hash > head->next->hash)
		head = move(head, head->next);
	head->next = bubbleSort(head->next);
	
	if(head->next != NULL && head->hash > head->next->hash)
	{
		head = move(head, head->next);
		head->next = bubbleSort(head->next);
	}
	return head;
}
int main()
{	
    FILE* fp = fopen("veri.txt", "r+"); 
    char line[256];
   	float latitude, longitude, temperature;
    int hash;
    struct Node *head = NULL;
    
    printf("Unsorted Linked List>\n\n");
	   
    while (fgets(line, sizeof(line), fp)) 
	{
		sscanf(line, "%f %f %f ", &latitude, &longitude, &temperature);
	/*	printf("%s", line); */
		hash = calculate_hash(latitude, longitude);
	/*	printf("%d\n", hash); */
        head = add_Node(head, hash, latitude, longitude, temperature);
    	printList(head); 
    	head = bubbleSort(head);
    /*	printList(head); */
    }
   
    fclose(fp);
    
	return 0;	
}

