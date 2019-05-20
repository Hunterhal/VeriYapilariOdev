#include <stdio.h>
#include<math.h>

FILE *hedef_dosya;  //text dosyasindan verileri cekmemiz icin gereken genel yap˝

// verileri tutan ana struct yapimiz
typedef struct veri{
	// la degeri latitude
	// lo degeri longitude
	// te degeri temperature
	// k degeri hash degerimizdir.
	float k,la,lo,te;
		
}v;
v a[2000];	 //bu k¸mede tanimlanmis bilgileri tutacagimiz 2000 boyutunda array

int h(int x){
	return    x%2000;      //hash fonksiyonunda Á˝kan sonucun 2000 ile mod¸l i˛lemi
	
}
// has tablosuna veri koyan fonksiyon
int put (v data){
	if(a[h(data.k)].k ==-1){    // -1 degeri main fonksiyonumuz icinde belirttigimiz gibi bo˛ yerleri gˆsteriyor
								// eger atanacak konumun degeri -1 ise sayi direkt oraya ataniyor.
			a[h(data.k)] = data;
					return 1 ;
	}
	else {
		int donussayisi = 0;
		int indis = h(data.k);
		
		while ( a[indis].k!=-1){
		//	printf("%d %d %d \n ",a[indis].k, data.k, indis);   komutunu kullanarak kontrol edebiliriz.
			indis ++;
			if ( indis >= 2000){
				if(donussayisi >= 1){
					printf("hashtable dolu");  // eger degerlerimiz daha fazla olsayd˝ bu uyar˝y˝ verecekti
					return -1;
					
				}
				indis = indis%2000;    // indisimiz 2000 degerini gectigi noktalar olabilir diye 
										// tek sefere mahsus indis degerinin modulunu alabiliriz
			     donussayisi++;
			}
					
		}
		
		a[indis].k = data.k;         // burada indisleri tutmak icin degerlerimizi kaydettik.
		a[indis].la = data.la;
		a[indis].lo = data.lo;
		a[indis].te = data.te;
		
		
	}
		
}


int bastir (){   
  // bastirma fonksiyonumuz.
	int i ;
	for ( i = 0 ; i<2000 ;i++){
		printf("hash : %f latitude: %f longitude: %f  temperature: %f\n",a[i].k, a[i].la, a[i].lo,a[i].te);				
	}
	printf("\n ");
	
	
}


// eger bir h degerine gore sonuclari ariyorsak bu fonksiyonu kullaniriz.
// put fonksiyonuyla neredeyse ayni kodlari kullandik sadece girdi yerine cikti aldik.
int get (int k ){  
if(a[h(k)].k == k ){
	
		return 	a[h(k)].la, a[h(k)].lo, a[h(k)].te ;
	}
	else {
		int donussayisi = 0;
		int indis = h(k);
		
		while (a[indis].k != k && a[indis].k != k){
		
			indis ++;
			if ( indis >= 2000){
				if(donussayisi >= 1){
					printf("hashtableda kay˝t yok");
					return -1;
					
				}
				indis = indis%2000;
				donussayisi++;
			}
					
		}
	
		return a[indis].la,a[indis].lo ,a[indis].te ;
	
		
	}
		
}

		



int main(){
	float latitude;
	float longitude;
	float temperature;
	int temp;
	int hash;
	int gecici;
	int q;
	int u;
	int i;
	int modul;
	// oncelikle a matrisini olusturmak icin her elemanina -1 degeri atand˝.
	
	for (i = 0 ; i<2000 ; i++){
		a[i].k = -1.0;
		
	}
	v data;
	// burada veri text dosyasini actik
	hedef_dosya = fopen("veri.txt","r+");
	//for dongusu icerisinde 2000 verinin hepsini aldik
	int p;
	for ( p = 0; p<2000 ; p++){		
	fscanf(hedef_dosya, "%f %f %f", &latitude, &longitude, &temperature);
	  // bu kisimda hash degerimizi veren fonksiyonu tanimladik
   
    temp = latitude * 1e6 + longitude * 1e6 ;  
    modul = abs(temp);
	 
	hash = modul % 1081;
	
	// buldugumuz degerleri struct yapisinda tanimladik ve yerlerine koyduk.
	data.k = hash;
	data.la = latitude;
	data.lo= longitude;
	data.te = temperature;
	put(data);
}
  bastir();
// veri dosyayisini kapattik.
fclose(hedef_dosya);


printf("\n *******************************************************************\n");
printf("\n *******************************************************************\n");
printf("\n *******************************************************************\n");
printf("\n *******************************************************************\n");


// burada ise hash degerlerini kucukten buyuge dogru tum tabloyu s˝ralayacagiz.

printf("\n Tablomuzun hash degerlerinin selection sort'a gore siralanmis hali sudur:\n");

// Selection sort islemi
int j, enKucuk, tempp;
     for (i=0; i<2000; i++)
     {
         enKucuk = i;          // i degerimizi en kucuk deger olarak kabul ediyoruz.
         for (j=i+1; j<2000; j++)
         {
             if (a[j].k < a[enKucuk].k)    // sonraki tum degerleri en kucuk degeri karsilastiriyoruz
             enKucuk = j;					// eger sonraki deger en kucuk degerden kucukse o deger EnKucuk yerine geciyor.
         }
         tempp = a[i].k;           // burada ise klasik atama islemi yapiyoruz.
         a[i].k = a[enKucuk].k;
         a[enKucuk].k = tempp;
     }
     
bastir();

	
	return 0 ;

	
	
	
}
