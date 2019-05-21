#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <string.h>


struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) \n",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}



int getHashValue(float value1,float value2,float value3)//Hash fonksiyonu
{
	int temp = value1 * 1e6 + value2 * 1e6; //GpsEnlem ve GpsBoylami aliyoruz.
	int hash = ((int)abs(temp)) % 1000; 

	printf("Hash value is %d\n", hash);

	return hash;
}


void selectionSort (int dizi[], int elemanSayisi)//selection sort a gore siralamayi yapan fonksiyon
{
     int i, j, enKucuk, temp;
     for (i=0; i<elemanSayisi-1; i++)
     {
         enKucuk = i;
         for (j=i+1; j<elemanSayisi; j++)
         {
             if (dizi[j] < dizi [enKucuk])
             enKucuk = j;
         }
         temp = dizi[i];
         dizi[i] = dizi[enKucuk];
         dizi[enKucuk] = temp;
     }
     
     printf("\n\n\n");
     
     for(i=0;i<elemanSayisi-1; i++){//siralanan diziyi yazdirma islemini gerceklestiriyoruz.
     	
     	printf("Selection Sorta gore %d. eleman: %d\n",i,dizi[i]);	
     	
	 }
}




int main(){
	
	float deger;
	int dizi[3005];//Hash degerlerini tutan bir dizi olusturdum.	
	FILE *hedef_dosya=fopen("veri.txt","r");//veri adli dosyadan bilgileri cekmek icin pointera atadik dosyayi.r+ burada read demek, w+ olsaydi tam tersi txt dosyasina yazdirma olurdu.
	
	if(hedef_dosya==NULL){
		
		printf("veri bulunamadi");
		return 0;
	}
	else{
		
		float GpsEnlem[3005],GpsBoylam[3005],Sicaklik[3005];//Dosyadan cekicegimiz degerler icin dizi olusturduk.
		int sayac=0;
		
		
		while(!feof(hedef_dosya)){//!feof  : Okunan verilerin sonuna gelinmedigi surece demek
			
			fscanf(hedef_dosya,"%f ile % f ile %f",&GpsEnlem[sayac],&GpsBoylam[sayac],&Sicaklik[sayac]);	//fscanf ile verileri atiyoruz degiskenlere
			dizi[sayac]=deger=getHashValue(GpsEnlem[sayac],GpsBoylam[sayac],Sicaklik[sayac]);//Hash degerini hesapliyoruz ve yazdiriyoruz.
			insertFirst(sayac,deger);
			sayac++;
			
			if(sayac==3005){
				break;
			}
			
		}
		
		printf("\n\n");
		printf("Original List: \n"); 
	
   		//print list
  	 	printList();//Linked liste kaydettigimiz degerleri yazdirdik.
  	 	
  	 	
  	 	selectionSort(dizi,3005);//selection sort fonsiyonuna gidip siralamayi yapiyor.
  	 	
		
	
		 
		
	}
	
	
	
	
	
	fclose(hedef_dosya);//Okuma isleminden sonra okunan txt dosyasini kapatmamiz lazim.
	
	return 0;
}



