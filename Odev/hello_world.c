#include<stdio.h>

int deneme(int sayi){
	
	int fact=1;
	
	for (; sayi>0; sayi--){
		fact = fact*sayi;
	}
	
	return fact;
}


int main(){
	
	int x;
	
	printf("faktoriyelinin alinmasini istediginiz sayiyi girin: ");
	scanf("%d", &x);
		
	printf("bu sayinin faktoriyeli: %d", deneme(x));
	
	return 0;
}
