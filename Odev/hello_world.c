#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	float latitude;
    float longitude;
    float temperature;
    int hash_deger;
    struct Node* next;
};
int hash(float latitude,float longitude)
{
	int hash;
	float temp;
	temp = latitude * 1e6 + longitude * 1e6;
	hash = ((int)abs(temp)) % 1079;//Hash fonksiyonuna gore hash degerleri hesaplanir
	return hash;
}
struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    return newNode;
}
struct Node* addLast(struct Node* root,float latitude, float longitude, float temperature)
{
    struct Node* eleman = createNode();
    eleman->latitude = latitude;
    eleman->longitude= longitude;
    eleman->temperature= temperature;
    eleman->hash_deger = hash(latitude,longitude);
    eleman->next = NULL;
 	
    if(root == NULL)//ilk eleman eklemesi
    {
        root = eleman;
        return root;
    }
    else
    {
        struct Node * temp = root;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = eleman;
        return root;
    }
 
}
void printLinkedList(struct Node* root)
{
    if(root == NULL)
    {
        printf("\n Your List is EMPTY");
    }
    else
    {	
        struct Node* temp = root;
        while(temp->next != NULL)
        {
            printf("Hash:%d  Lati:%f  Long:%.6f  Temp:%.1f\n", temp->hash_deger, temp->latitude,temp->longitude,temp->temperature);
            temp = temp->next;
        }
        printf("Hash:%d  Lati:%f  Long:%.6f  Temp:%.1f\n",temp->hash_deger,  temp->latitude,temp->longitude,temp->temperature);
    }
 
}
void selection_Sort(struct Node* root) 
{ 
    struct Node* temp = root; 
  	while (temp) { 
        struct Node* min = temp; 
        struct Node* r = temp->next; 
  
        while (r) { 
            if (min->hash_deger > r->hash_deger) 
                min = r; 
  
            r = r->next; 
        } 
   		int x = temp->hash_deger;
		float y= temp->latitude;
		float z= temp->longitude;
		float b= temp->temperature; 
        temp->hash_deger = min->hash_deger; 
        temp->latitude = min->latitude; 
        temp->longitude = min->longitude; 
        temp->temperature = min->temperature; 
        min->hash_deger = x; 
        min->latitude=y;
        min->longitude=z;
        min->temperature=b;
        temp = temp->next; 
    } 
} 


int main(int argc, char *argv[]) {
    FILE* file = fopen("veri.txt", "r");//Dosya okunur.
    char line[256];
    float latitude;
    float longitude;
    float temperature;
    struct Node* root=NULL;//Bir pointer olusturulur.

    while (fgets(line, sizeof(line), file)) {
        sscanf_s(line, "%f %f %f", &latitude, &longitude, &temperature);
        root=addLast(root,latitude,longitude,temperature);//Line okunduktan sonra linked-liste ekleme
    }
	fclose(file);
	printf("Siralama yapmadan onceki liste:\n");
	printLinkedList(root);//Once sirasiz liste yazdirilir.
	printf("\n**************************************************************\n");
	selection_Sort(root);
	printf("Siralamadan sonraki liste:\n");
	printLinkedList(root);

	return 0;
}
