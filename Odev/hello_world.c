// kodlari c++ da yazdım 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <list>
#include<cstdlib>
#include <math.h>
#include<limits.h>
#include <cstdlib>
#include <cmath>
using namespace std; 
struct node{
    int hashdegeri;
    float enlem;
    float boylam;
    float sicaklik;
    struct node *next;
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;
struct node* head2 = NULL;
struct node* tail2 = NULL;
struct node* temp2;

struct node* createPerson(int hashdegeri, float enlem,  float boylam,  float sicaklik)
{
    struct node* newPerson = (struct node*)malloc(sizeof(struct node));
    newPerson->hashdegeri = hashdegeri;
    newPerson->enlem = enlem;
    newPerson->boylam = boylam;
    newPerson->sicaklik = sicaklik;
    newPerson->next = NULL;
 
    return newPerson;
}

void enQueuePerson(int hashdegeri, float enlem,  float boylam,  float sicaklik)
{
    struct node* person = createPerson(hashdegeri, enlem, boylam, sicaklik);
    if(head == NULL && tail == NULL)
    {
        head = person;
        tail = person;
    }
    
    else
    {
        tail->next = person;
        tail = person;
    }
    
}

void deleteNode(struct node **head_ref, int key) 
{  
    struct node* temp = *head_ref, *prev; 
    if (temp != NULL && temp->hashdegeri == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    while (temp != NULL && temp->hashdegeri != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
 
    if (temp == NULL) return; 
    
  	prev->next = temp->next; 
	free(temp);   
	
} 

void printQueue()
{
    int i = 1;
    if(head == NULL)
    {
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("\n%d. Position => %d %f %f %f ", i, temp->hashdegeri, temp->enlem, temp->boylam, temp->sicaklik );
      
        temp = temp->next;
        i++;
    }
    
  
} 

int hashfunction(float x,float y) 
{
	int temp;
	int hash;
	temp = x * 1e6 + y * 1e6;
	hash=(abs(temp)) % 1087;  
	return hash;
}

int minElement(struct node* head) 
{ 
	node* minnode;
	int min = 10000; 
  	while (head!= NULL) 
	{ 
  		if (min > head->hashdegeri)
		   {
				min = head->hashdegeri;
				minnode = head; 
    		}
		head = head->next; 
        
    }

return min;

}

node* minnode(struct node* head) 
{ 
	node* minnode;
	int min = 10000; 
    while (head != NULL)
	{ 
  		if (min > head->hashdegeri) 
		{
			min = head->hashdegeri;
			minnode = head; 
        }
		head = head->next; 
        
    }
  
    return minnode;
}
  
int main () 
{ 
  	float latitude;
  	float longitude;
  	float temperature;
  	string line;
  	ifstream myfile ("veri.txt");
  	if (myfile.is_open())
  	{
  		while (myfile.good())
		{
        	getline (myfile,line);
	  		std::string str = line;
		    char const *c = str.data();
			sscanf(c, "%f %f %f", &latitude,&longitude, &temperature);
	  		enQueuePerson(hashfunction(latitude, longitude), latitude, longitude, temperature);
		}		
   		 myfile.close();
  }

  	else cout << "Unable to open file"; 
  	printf("\n----liste 1----\n");
	printQueue();
	
	printf("\n----liste 2----\n");
  	head2 = minnode(head);
    deleteNode(&head,minElement(head));
 	printf("\n %d %f %f %f ",  head2->hashdegeri, head2->enlem, head2->boylam, head2->sicaklik );
 	
  	while(head2 !=0)
	{
  		head2->next = minnode(head);
  		printf("\n %d %f %f %f ",  head2->hashdegeri, head2->enlem, head2->boylam, head2->sicaklik );
  		head2=head2->next;
  		deleteNode(&head,minElement(head));	
	}

  return 0;
}
