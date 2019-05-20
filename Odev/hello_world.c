#include <stdio.h>
#include <stdlib.h>



struct Node{
	double enlem;
	double boylam;
	double sicaklik;
	long int hash;
	struct Node* next;
};

typedef struct Node Node;

Node* dosyayi_oku(FILE* veri);
Node* sirala(Node*);
double absolute(double sayi);
void list_yazdir(Node*);

int main(){
	FILE* veri;
	
	if(!(veri = fopen("veri.txt", "r"))){
		printf("Veri dosyasi bulunamadi.\n");
		return 0;
	}
	
	Node* sirasiz_head; //sirasiz haldeki olan linked liste ait ilk dugumu tutar. 
	Node* sirali_head; // siralanmis haldeki olan linked liste ait ilk dugumu tutar.

	sirasiz_head = dosyayi_oku(veri);
	printf("SIRASIZ BAGLI LISTE: \n");
	list_yazdir(sirasiz_head); //sirasiz listeyi yazdirir
	
	sirali_head = sirala(sirasiz_head);	
	printf("\n\nSIRALI BAGLI LISTE: \n");
	list_yazdir(sirali_head); // sirali listeyi yazdirir



	/*NOT: Dugumler ayni oldugundan dolayi sirali liste olusturuldugunda sirasiz liste kaybolacaktir.
		bu yuzden sirala() fonksiyonundan sonra list_yazdir() fonksiyonu ile sirasiz_head i yazdirmak
		hatali sonuc verecektir.
	*/	
	
	
	// Alinan hafizanin geri verilmesi:
	Node* temp = sirali_head;
	while(sirali_head != NULL){
		temp = sirali_head->next;
		free(sirali_head);
		sirali_head = temp;
	}
	printf("\nProgrami kapatmak icin bir tusa basin.\n");
	getchar();
	return 0;
}

void list_yazdir(Node* head){
	Node* temp;
	temp = head;
	while(temp != NULL){
		printf("Enlem: %.7lf, Boylam: %.7lf, Sicaklik: %.1lf, HashNo: %ld\n", temp->enlem, temp->boylam, temp->sicaklik, temp->hash);
		temp = temp->next;
	}	
}

Node* sirala(Node* sirasiz){
	Node* sirali = NULL;
	Node* temp;
	Node* iter;
	Node* previous;
	
	while(sirasiz != NULL){
		temp = sirasiz;
		sirasiz = sirasiz->next;
		iter = sirali;
		if(iter == NULL){ // eger siralanacak ilk elemansa
			sirali = temp;
			sirali->next = NULL;
		}
		else{
			if(iter->hash < temp->hash){ // sirali listteki ilk elemanin kontrolu
				temp->next = iter;
				sirali = temp;
				continue;
			}
			previous = iter;
			iter = iter->next;
			while(iter != NULL){ //sirali listenin sonuna kadar ara
				if(iter->hash < temp->hash){ 
					previous->next = temp;
					temp->next = iter;
					break; // eger yerlestirildiyse donguden cik listede aramayi birak
				}
				iter = iter->next;
				previous = previous->next;		
			}
			if(iter == NULL){ // eger listenin sonuna gelinmis ve hala eklenmemisse diye kontrol
				previous->next = temp;
				temp->next = NULL;
			}
		}
	}
	
	return sirali;
}
double absolute(double sayi){
	if(sayi < 0){
		return -1 * sayi; 
	}
	else{
		return sayi;
	}
}

Node* dosyayi_oku(FILE* veri){
	char satir[1000];
	Node* head = NULL;
	Node* end = NULL; // listin son elemani
	double hash;
	
	while(feof(veri) == 0){
		fgets(satir, 999, veri);
		if(head == NULL){ // eger liste henuz olusturulmamissa diye kontrol eder
			head = (Node*)malloc(sizeof(struct Node));	
			sscanf(satir, "%lf %lf %lf", &(head->enlem), &(head->boylam), &(head->sicaklik));
			head->hash = (head->enlem) * 1e6 + (head->boylam) * 1e6;
			head->hash = ((long int)abs(head->hash)) % 1020;
			head->next = NULL;
			end = head;
		}
		else{
			end->next = (Node*)malloc(sizeof(struct Node));
			sscanf(satir, "%lf %lf %lf", &(end->next->enlem), &(end->next->boylam), &(end->next->sicaklik));
			end->next->hash = (end->next->enlem) * 1e6 + (end->next->boylam) * 1e6;
			end->next->hash = ((long int)abs(end->next->hash)) % 1063;
			end = end->next;
			end->next = NULL;
		}
	}
	// dosyadan okuma islemi yaparken son satiri 2 defa okdugu icin son dugum siliniyor
	Node* temp;
	temp = head;
	end = head;
	if(temp->next != NULL){
		end = temp->next;
	}
	while(end->next != NULL){
		end = end->next;
		temp = temp->next;
	}
	temp->next = NULL;
	free(end);
	
	return head;
}
