#include<stdio.h> 
  #include<string.h> 
  #include<stdlib.h>    
   //Berkay Yıldız 040160116
  int main () 
  { 
      float  latitude; 
      float longitude; 
      float  temperature;
	  int temp;
	  int hash; 
      FILE *dosya; 
      int dizi[2000];
      int gecici;
      int tut;
      
      
       dosya = fopen("C:\\veri.txt","r" );    //dosya açıldı dosya değişkenine atandı
  for(int k=0; k<2000;k++)
  {
  	fscanf(dosya, "%f %f %f", &latitude, &longitude, &temperature);	  //dosyadan 3 değer satır satır okundu
	temp = latitude * 1e2 + longitude * 1e2;    //hash değeri özgün bir algoritma ile hesaplandı 
	hash = ((int)abs(temp)) % 1000;
	dizi[k] = hash;                             //hash değeri diziye atıldı
	//printf("%d\n",dizi[i]);
  }
  
    for(gecici=1;gecici<2000;gecici++)           //döngü kullanılarak dizinin elemanları sıralandı
       {
           for (int i=0;i<2000 - 1;i++)
          {
           if (dizi[i]>dizi[i+1])
           {
               tut=dizi[i];
               dizi[i]=dizi[i+1];
               dizi[i+1]=tut;
           }
          }
       }
       
       for(int j=0; j<2000;j++)
       {
       	printf("%d \n",dizi[j]);             //dizi ekrana bastırıldı
	   }
       
       
       fclose(dosya);                       //okunan dosya kapandı
  }
