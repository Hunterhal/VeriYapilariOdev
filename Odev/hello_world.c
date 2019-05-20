#include<stdio.h>
#include<stdlib.h>


//Bağlı liste için longitude latitude temperature hash ve sonraki node'un pointerını strct yapısı oluşturduk
struct LinkedList{
    float hash,latitude,temperature,longitude;
    struct LinkedList *next;
 };
FILE *file;
typedef struct LinkedList *node; //struct linkedlist veri yapısını node pointerı olarak tanımladık

// kullanılacak fonksiyonları önceden tanımlıyoruz
//fonksiyonlar aşağıda tekrar tanımlanacak
node create(); 
node insert(node head, float latitude, float longitude, float temperature, float hash);
void display(node head);
node sort(node head);
void archive(node head);
void archive2 (node head);
node sort(node head);




int main()
{

// verilerin saklandığı ve program koduyla aynı yerde (directory) bulunan text dosyasını okumak ("r")için açıyoruz
file=fopen ("veri.txt","r");


node head=NULL;
node sortedlist=NULL;
node initialList=NULL;
int selection=1;

//fonksiyonda kullanılacak geçici değişkenleri referans ettikleri değerlere benzer isimlerde tanımlıyoruz. örneğin: h->hash tem->temperature...
float h,lat,tem,lon;	
	
if ( file != NULL )
		{
	
char line [ 50 ]; /* her satırda bulunan tahmini max karakter sayısı */
//veri text dosyasını satır satır okuyarak her satırdan emlem boylam ve sıcaklık değerlerini float cinsinden çekip bağlı listemize düğüm olarak aktarıyoruz
while ( fgets ( line, sizeof line, file ) != NULL ) 
{
sscanf(line, "%f %f %f", &lat, &lon, &tem);
//bu değerler için bir hash fonksiyonu yardımıyla her enlem boylam sıcaklık üçlüsü için bir hash değeri oluşturup ilgili düğüme atıyor
float calc = lat * 1e6 + lon * 1e6;
h = ((int)abs(calc)) % 1051;
//bu 4 veriyi bir düğüm olarak bağlı listenin sonuna ekle
head=insert (head, lat, lon, tem, h);
initialList=insert (initialList, lat, lon, tem, h);//head ve initialList adında iki farklı node veri tipinde değişken tanımlama sebebi head listesini sortladıktan sonra listenin ilk hali yok olacıktır.
												   //Bu yüzden initialList adında bir değikende listenin ilk hali saklanır
}

fclose ( file );

sortedlist=sort(head);


do{
	printf("Yapmak istediginiz islemi seciniz: \n 1.Orijinal listeyi goruntule \n 2.Siralanmis listeyi goruntule \n 3.Orijinal listeyi bir text dosyasina yazdir \n 4.Siralanmis listeyi bir text dosyasina yazdir \n 5.Cikis\n");
	scanf("%d", &selection);
	
	switch(selection){
		case 1:
			
			display(initialList);
			break;
			
		case 2:
			display(sortedlist);
			break;
			
		case 3:
			archive(initialList);
			break;
			
		case 4:
			archive2(sortedlist);
			break;
	    	
		case 5:
			exit(1);
		
			
		default:
			printf("Hatali giris\n");
			break;
			
		}

	}while (selection!=5);
}
	  
}

//fonksiyon tanımlamaları


//verilen bağlı listeyi sıraya sokmak için tanımlanan sort fonksiyonu
node sort(node head){
	node p,q;
	
	p=head;
	float h,lat,tem,lon; 
	
	for(p=head;p->next!=NULL;p=p->next){
		
		for(q=p->next;q!=NULL;q=q->next){
			
			if(p->hash>q->hash){
				h=p->hash;
				lat=p->latitude;
				tem=p->temperature;
				lon=p->longitude;
				
				p->hash=q->hash;
				p->temperature=q->temperature;
				p->longitude=q->longitude;
				p->latitude=q->latitude;
				
				q->hash=h;
				q->temperature=tem;
				q->latitude=lat;
				q->longitude=lon;
				
			}
		}
	}
return head;		
		
}

	



//verilen bağlı listeyi text dosyasına yazacak fomksiyon
void archive (node head){

file=fopen ("list1.txt","w");
node p;
p=head;
fprintf(file,"Latitude	    Longitude		Tempreature      Hash Value\n");
while (p!=NULL)
	{

		fprintf(file,"%f	    %f	  	%0.1f		  %0.1f\n",p->latitude,p->longitude,p->temperature,p->hash);
		p=p->next;

	}	
	fclose(file);
}
//verilen listeyi başka bir text dosyasına yazacak fonksiyon
void archive2 (node head){

file=fopen ("sortedlist.txt","w");
node p;
p=head;
fprintf(file,"Latitude	    Longitude		Tempreature      Hash Value\n");
while (p!=NULL)
	{
fprintf(file,"%f	    %f	  	%0.1f		  %0.1f\n",p->latitude,p->longitude,p->temperature,p->hash);
p=p->next;
	}	
fclose(file);
}

//aldığı bağlı listeyi görüntüleyecek fonksiyon
void display(node head)
{
	
	node p;
	p=head;
	
	while (p!=NULL)
	{
	
		printf("Latitude	Longtitude	 Temperature	Hash Value\n");
		printf("%f	%f	 %0.1f		%0.f\n\n", p->latitude, p->longitude, p->temperature, p->hash);
		p=p->next;
		
	}	
	
}

//boş bir düğüm oluşturma fonksiyonu
node create(){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    return temp;
}

//aldığı değerlerle bir düğüm oluşturup listenin sonuna ekleme fonksiyonu
node insert(node head, float latitude, float longitude, float temperature, float hash){
    node temp,p;
    temp = create();
    temp->latitude = latitude;
	temp->longitude = longitude;
	temp->temperature = temperature;
	temp->hash = hash; 
    if(head == NULL){
        head = temp; 
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

