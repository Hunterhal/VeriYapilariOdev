
/* Doğa Gündüzalp 040160055
   Veri Yapıları ve Programlama EHB 208 
   Ödev 2 */

#include <stdlib.h>
#include <stdio.h>

/* Bir bağlı liste düğümü */
struct Dugum 
{ 
	int veri1;   /*Hash değerini ifade eder */
	float veri2; /* Enlem değerini ifade eder */
	float veri3; /* Boylam değerini ifade eder */
	float veri4; /* Sıcaklık değerini ifade eder */
	struct Dugum *sonraki; 
}; 

/* İleride kullanılacak fonksiyon protetipleri */
struct Dugum* Siralanmis(struct Dugum* a, struct Dugum* b); 
void OnArkaAyirma(struct Dugum* kaynak, struct Dugum** onReferans, struct Dugum** arkaReferans);

/* Pointerleri değiştirerek bağlı listemizi sıralar */
void BirlestirmeliSiralama(struct Dugum** headReferans) 
{ 
	struct Dugum* head = *headReferans; 
	struct Dugum* x; 
	struct Dugum* y; 

	/*Listenin 0 ya da 1 elemanlı olma durumu */
	if ((head == NULL) || (head->sonraki == NULL)) { 
		return; 
	} 

	/* x ve y olan iki alt listeye ayırır */
	OnArkaAyirma(head, &x, &y); 

	/* Özyinelemelidir
	   Alt listeleri çağırıp sıralar */
	BirlestirmeliSiralama(&x); 
	BirlestirmeliSiralama(&y); 

	/* Bu alt listeleri birleştirir */
	*headReferans = Siralanmis(x, y); 
}

/* Sıralama işlemini yapan fonksiyondur */
struct Dugum* Siralanmis(struct Dugum* x, struct Dugum* y) 
{ 
	struct Dugum* sonuc = NULL; 

	/* Temel durumlar */
	if (x == NULL) 
		return (y); 
	else if (y == NULL) 
		return (x); 

	/* a'yı ya da b'yi seçer ve yineler */
	/* Veri1 Hash değerini ifade eder */
	if (x->veri1 <= y->veri1) { 
		sonuc = x; 
		sonuc->sonraki = Siralanmis(x->sonraki, y); 
	} 
	else { 
		sonuc = y; 
		sonuc->sonraki = Siralanmis(x, y->sonraki); 
	} 
	return (sonuc); 
}

/* Listeyi ön ve arka olarak 2'ye böler 
   ve bu 2 listeye geri döner. Referans
   parametreleri kullanılır. */
void OnArkaAyirma(struct Dugum* kaynak, struct Dugum** onReferans, struct Dugum** arkaReferans) 
{
	struct Dugum* hizli;
	struct Dugum* yavas;
	yavas = kaynak;
	hizli = kaynak->sonraki;

	while (hizli != NULL) { 
		hizli = hizli->sonraki; 
		if (hizli != NULL) { 
			yavas = yavas->sonraki; 
			hizli = hizli->sonraki; 
		}
	}

	/* "yavaş" denilen düğüm orta noktadan öncedir.
	   Buradan listeyi 2'ye böler */
	*onReferans = kaynak; 
	*arkaReferans = yavas->sonraki; 
	yavas->sonraki = NULL; 
}

/* Girilen ilk değer listenin head'i olarak belirlenir
   veya listenin sonuna girilen değeri ekler */
void ekle(struct Dugum** head_referans, int yeni_veri1, float yeni_veri2, float yeni_veri3, float yeni_veri4) 
{ 
	/* Yeni düğümü ayırır */
	struct Dugum* yeni_dugum = (struct Dugum*) malloc(sizeof(struct Dugum)); 
	struct Dugum *son = *head_referans; 

	/* Verileri yeni düğüme koyar */
	yeni_dugum->veri1 = yeni_veri1;
	yeni_dugum->veri2 = yeni_veri2;
	yeni_dugum->veri3 = yeni_veri3;
	yeni_dugum->veri4 = yeni_veri4;

	/* Yeni düğüm, listemizin son düğümü olucaktır.
	   Bu nedenle sonrasını NULL yapmak gerekir */
	yeni_dugum->sonraki = NULL; 

	/* Eğer bağlı liste boşsa, yeni düğümü head olarak atar */
	if (*head_referans == NULL) { 
		*head_referans = yeni_dugum; 
		return; 
	}

	/* Eğer bağlı liste boş değilse, listenin sonuna kadar gider */
	while (son->sonraki != NULL) 
		son = son->sonraki; 

	/* Eklenen yeni düğüm son düğüm olur */
	son->sonraki = yeni_dugum; 
	return; 
} 

/* printListe fonksiyonu bağlı listemizin içindeki 
   elemanları baştan başlayarak yazdırır */
void printListe(struct Dugum *dugum) 
{
	while (dugum != NULL) { 
		printf(" %d ", dugum->veri1); 
		printf(" %f ", dugum->veri2);
		printf(" %f ", dugum->veri3);
		printf(" %f ", dugum->veri4);
		printf("\n");
		dugum = dugum->sonraki; 
}
} 

/* Hash değerlerini hesaplayan fonksiyon */   
float Hash(float latitude, float longitude)
{
	float hash, temp;
	temp = latitude * 1e6 + longitude * 1e6; 
	hash = ((int)abs(temp)) % 1055; 
	return hash;
}

/* Programımızı çalıştıralım */
int main() 
{
	struct Dugum* head = NULL;  /* Boş bir bağlı liste oluşturur */
    
	FILE *dosya = fopen("GPSveri.txt", "r"); /* Text dosyamızı okumak için açar */
    char satir[60];  /* Satır satır okuma işlemi yapılacak. Satırdaki karakter sayısı yaklaşık 60'dır.*/
	float latitude, longitude, temperature;  /* Text dosyasından çekiceğimiz değişkenler */
    
	while (fgets(satir, sizeof satir, dosya) != NULL){
        sscanf(satir, "%f %f %f", &latitude, &longitude, &temperature); /* Veriyi çeker */
        ekle(&head, Hash(latitude, longitude), latitude, longitude, temperature); /* Sırasıyla Hash, enlem, boylam ve sıcaklık değerlerini bağlı listeye ekler */
    }
    
    fclose(dosya); /* Text dosyasını kapatır */
    
    printf("Siralanmamis hash degerlerine gore olusan listeniz: \n");
    printf(" Hash Latitude   Longitude  Temperature\n");
    printListe(head); /* Sıralanmamış bağlı listeyi yazdırır */
    
    printf("\n\n\n");
    
    BirlestirmeliSiralama(&head); /* Merge Sort algoritması bağlı listeyi küçükten büyüğe sıralar */
    
	printf("Siralanmis hash degerlerine gore olusan listeniz: \n");
	printf("Hash Latitude  Longitude  Temperature\n");
	printListe(head); /* Sıralanmış bağlı listeyi yazdırır */
    return 0;
}
