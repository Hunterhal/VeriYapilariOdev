#include <stdio.h>
#include <stdlib.h>
struct Node{
	int key;
	float data[3];
	struct Node* link;
	
};	
struct Node* head;
float yedek[4];
int tick = 0;
 struct Node* array15[1056];
void ekle(float* array){
	struct Node* temp;
	
	temp = head;
	///// TARAMA
	while(temp -> link != NULL){
		temp = temp->link;
	}
	///// EKLEME 
	temp -> link = (struct Node*)malloc(sizeof(struct Node));
	for(int i = 0;i<3;i++){temp->link->data[i] = *(array+i) ;};
	temp->link->key = (abs((int)(*(array)*1e6 + *(array+1) * 1e6)))%1056;
	printf("SayÄ± eklendi\n"); 
	}
void printall(){
	struct Node* temp;
	temp = head;
	///// TARAMA
	while(temp -> link != NULL){
		printf(" SayÄ± = %f %f %f %d %d \n",temp->data[0],temp->data[1],temp->data[2],temp->key,array15[temp->key]);
		temp = temp->link;
		tick++;
		
	} 
	}
void hashall(int key){
	struct Node* temp;
	temp = array15[key];
	///// TARAMA
	while(temp -> link != NULL && temp ->key == key){
		printf(" SayÄ± = %f %f %f %d %d \n",temp->data[0],temp->data[1],temp->data[2],temp->key,array15[temp->key]);
		temp = temp->link;
		tick++;
	} 
	}
struct Node* hash_key(int key){
	struct Node* temp;
	temp = head;
	///// TARAMA
	while(temp -> link != NULL){
		if(temp->key == key){return(temp);}
		temp = temp->link;		
	} 
	return(head);
	}
void bubblesort(){
	struct Node* temp;	
	struct Node* temp1;	
	struct Node* temp2;	
	temp = head;
	///// TARAMA
	while(temp -> link != NULL){
		temp1 = temp;
		temp2 = temp->link;
		///// BUBBLE-SORT ALGORITMASI
		if(temp1 ->key > temp2 -> key){
				
			    yedek[0] = temp1->data[0];	
				yedek[1] = temp1->data[1];	
				yedek[2] = temp1->data[2];
				yedek[3] = temp1->key;	
				
				temp1->data[0] = temp2->data[0];
				temp1->data[1] = temp2->data[1];
				temp1->data[2] = temp2->data[2];
				temp1->key = temp2->key;
				
				temp2->data[0] = yedek[0];
				temp2->data[1] = yedek[1];
				temp2->data[2] = yedek[2];
				temp2->key = yedek[3];

			}
	
		temp = temp->link;
	}
}
int main(int argc, char **argv)
{	
	
	
	

	////ROOT EKLEME
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp1;
	temp1 = head;
	temp1 -> link = NULL;
  
    FILE* file = fopen("veri.txt", "r"); 
    char line[256];
    float temp67[3] = {1,6,9};
    float a,b,c; 
   
    while (fgets(line, sizeof(line), file)) {
        
        /////TXT DOSYASINDAN VERI Ã‡EKÄ°P SIRALI LISTEYE EKLEME
        sscanf(line,"%f %f %f",&a,&b,&c); 
        temp67[0] = a; 
        temp67[1] = b;
        temp67[2] = c;
        //printf("%s",line);
        printf("%f %f %f ",temp67[0],temp67[1],temp67[2]); 
        ekle(temp67); 
    }
   

    fclose(file);
	
	printall();
	
	///SIRALAMA
	for(int u = 0; u<3000;u++){
	bubblesort();}
	 
	for(int u = 0; u<1056;u++){
	array15[u]=hash_key(u);
	}
	
	printall();
	
	for(int u = 0; u<1056;u++){
		printf("HASH: %d----------------------------------\n",u);	
		hashall(u);
		}
	
	int y;
	while(1){
		printf("\n*******************************");	
		scanf("%d",&y); if(y > 1055){y = 0;}
		hashall(y);	
	}
	
	return 0;
}

