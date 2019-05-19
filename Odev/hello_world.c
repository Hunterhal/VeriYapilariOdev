#include <stdio.h>
#include <stdlib.h> 
#include <time.h>



typedef struct node {
	int val;
	float longitude;
	float latitude;
	float temperature;
	struct node * next;
} node_t;



void add(node_t** root, int new_val, float longitude, float latitude, float temperature) {
	
	
	node_t* new_node = (node_t*) malloc (sizeof(node_t));
	new_node->val = new_val;
	new_node->longitude = longitude;
	new_node->latitude = latitude;
	new_node->temperature=temperature;
	new_node->next = NULL;
	
	if(*root == NULL) {
		*root = new_node;
		return;
	}
	
    
	if((*root)->next == NULL) {
		if((*root)->val < new_val) {
			(*root)->next = new_node;
		}else {
			new_node->next = (*root);
			(*root) = new_node;
		}
		return;
	}
	
	
	if((*root)->val > new_val) {
		new_node->next = (*root);
		(*root) = new_node;
		return;
	}
	
	
	node_t* temp = (*root);

	
	while(temp->next != NULL && temp->next->val < new_val) {
		temp = temp->next;
	}
	
	new_node->next = temp->next;
	temp->next = new_node;
	
	
	
}


int main(void) {
	  float latitude[2000];
            float longitude[2000]; 
            float temperature[2000];
            float temp[2000];
            int hash[2000];
    int  j=0,i=0;
    int no;
    double numbers[2000];
        double atof ( const char * str ); 

    char line[2000];  
    
    FILE *file;  
    file = fopen("C:\\veri.txt", "r"); 
    no = i;
    while(fgets(line, sizeof line, file)!=NULL) {      
        printf("%d Lines of numbers.txt file are: %s", i,line);     
        numbers[i]=atoi(line); 
	   sscanf(line, "%f %f %f", &latitude[i], &longitude[i], &temperature[i]);
      i++;
    }
    
    node_t* list = NULL;
    
 
    fclose(file);
	
	for (i=0;i<2000;i++){
			 //  printf("i %d %f**%f*%f \n",i,latitude[i],longitude[i], temperature[i]); 

		temp[i]= latitude[i]* 1e6 + longitude[i]* 1e6;
        hash[i] = ((int)abs(temp[i])) % 1050; 
		printf("%dhash values %d \n ",i,hash[i]);
		
		add(&list, hash[i], latitude[i],longitude[i], temperature[i]);
			
	}
	
	
	node_t* tempr = list;

	printf("Hash\tLatitude\tLongitude\tTemperature");

	while(tempr != NULL) {
		printf("%d\t%f\t%f\t%0.1f\n", tempr->val, tempr->latitude, tempr->longitude, tempr->temperature);
		tempr = tempr->next;
	}

	

    return 0;
}
