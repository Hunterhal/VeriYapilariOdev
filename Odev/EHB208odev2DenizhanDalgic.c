/*
*	EHB208 Veri Yapilari ve Programlama
*	Odev 2
* 	Denizhan Dalgic - 040170085
*	17.05.19
*/

#include <stdio.h>
#include <stdlib.h>

//Koordinat ve sicakliklarin tutulacagi dugumler
typedef struct data_node{
	float enlem;
	float boylam;
	float sicaklik;
	struct data_node *next;
} node_d;

//Hash verilerinin tutulacagi dugumler
typedef struct hash_node{
	float hash;
	struct hash_node *next;
} node_h;

//Gerekli degiskenler
float eklenen_enlem, eklenen_boylam, eklenen_sicaklik;

//Satir sayisi buyuklugunda hash degerlerinin tutulacagi dizi
float hash[2002];

//Fonksiyonlarin duzgun calismasi icin belirlenen global degiskenler
node_d * d_bas = NULL;
node_d * d_son;

node_h * h_bas = NULL;
node_h * h_son;
	
//data_node icin sona dugum ekleme fonksiyonu
node_d * dataSonaEkle(node_d ** bas)
{
	node_d * current = *bas;

	if (current == NULL)
	{
		current = (node_d*)malloc(sizeof(node_d));
		current->next = NULL;
		*bas = current;
		return *bas;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = (node_d*)malloc(sizeof(node_d));
	current->next->next = NULL;
	return current->next;
}

//hash_node icin sona dugum ekleme fonksiyonu
node_h * hashSonaEkle(node_h ** bas){
	node_h * current = *bas;
	
	if(current == NULL) {
		current = (node_h*)malloc(sizeof(node_h));
		current->next = NULL;
		*bas = current;
		return *bas;
	}
	while(current->next != NULL) {
		current = current->next;
	}
	
	current->next = (node_h*)malloc(sizeof(node_h));
	current->next->next = NULL;
	return current->next;
}

//Minimum deger bulma fonksiyonu
int find_minimum(float arr[], float n)
{
	int min = arr[0];
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

//Brute force siralama fonksiyonu
void brute_force_sort(float arr[], float n)
{
	int newArray[8];
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		newArray[i] = arr[find_minimum(arr, n)];
		arr++;
		n--;
	}
}

//Listeden dizi olusturma fonksiyonu
void createListFromArray(int arraySize)
{
    int counter = 0;
    
    while(counter < arraySize){
    	h_son = hashSonaEkle(&h_bas);
    	h_son->hash = hash[counter];
    	counter++;
	}
    
}

int main()
{	
	//Maksimum satir uzunlugumuz kadarlik string
	char satir[31];
    int index = 0, n;
    
    //txt dosyasinin isaretcisi
    FILE *fptr;
    
    float temp;

	//Dosya acilmaya calisiliyor
    if ((fptr = fopen("veri.txt", "r")) == NULL) 
	{
        printf("Sayfa acilirken hata");
        return 1;         
    }
    
    //Dosya sonuna gelinip gelinmedigi kontrol ediliyor
    while(feof(fptr) == 0) {
    	
    	//satir uzunlugu kadar okuma yapiliyor
		fgets(satir, sizeof(satir), fptr);
		
		//Okuma istenilen parcalara ayriliyor
		sscanf(satir, "%f %f %f", &eklenen_enlem, &eklenen_boylam, &eklenen_sicaklik);
		
		//Parcalarin eklencegi dugum sona ekleniyor
		d_son = dataSonaEkle(&d_bas);		
		
		//Parcalar dugume ekleniyor
		d_son->enlem = eklenen_enlem;
		d_son->boylam = eklenen_boylam;
		d_son->sicaklik = eklenen_sicaklik;	
		
		//Hash degeri hesaplaniyor
		temp = d_son->enlem*1e6 + d_son->boylam*1e6;
		hash[index] = ((int)abs(temp)) % 1085;
		index++;
	}
	
	//Brute force ile siralama hazirligi
	n = sizeof(hash) / sizeof(hash[0]);
	brute_force_sort(hash, n);
	
	//Basima hazirlaniyor
	node_d * yazilan = d_bas;
	
	//Hash degerlerinden baglantili liste hazirlaniyor
	createListFromArray(2002);
	
	//Basima hazirlaniyor
	node_h * h_yazilan = h_bas;
	
	//txt dosyasindan gelen veriler basiliyor
	printf("Alinan veriler: \n");
	while (yazilan != NULL) {
		printf("Enlem: %f\tBoylam: %f\tSicaklik: %f\n", yazilan->enlem, yazilan->boylam, yazilan->sicaklik);
		yazilan = yazilan->next;
	}
	
	//Hesaplanan hash degerleri baglantili listeden basiliyor
	printf("Siralanmis hash degerleri: \n");
	while(h_yazilan != NULL){
		printf("Hash Degeri: %f\n", h_yazilan->hash);
		h_yazilan = h_yazilan->next;
	}
	
	//Dosya okumasi sonlandiriliyor
    fclose(fptr);
    
    //Programdan hatasiz cikis saglaniyor
    return 0;
}
