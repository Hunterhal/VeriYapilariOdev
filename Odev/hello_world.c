#include <stdio.h>
#include <stdlib.h>

struct dugum{  

  double birincil;
  double ikincil;
  float sicak;
  int yuksek;

  struct dugum *sonraki;

};

typedef struct dugum eleman;

eleman* y_eleman(){
  eleman *N;
  N = (eleman*)malloc(sizeof(struct dugum));
  N->sonraki = NULL;
  return N;
}

int hashing(double birincil, double ikincil){ 
  long a = birincil*1e6 + ikincil*1e6;
  return ((int)abs(a))%1064;
}

eleman *ekleme(eleman *bas, int yuksek, float sicak, double birincil, double ikincil){ 

  if(bas == NULL){

    eleman *dummy;
    dummy= (eleman *) malloc(1);

    dummy->yuksek = yuksek;
    dummy->birincil = birincil;
    dummy->ikincil = ikincil;
    dummy->sicak = sicak;
    bas = dummy;

  }

  else if(bas->yuksek > yuksek){

    bas->sonraki = ekleme(bas->sonraki, yuksek, sicak, birincil, ikincil);
  }

  else{

    eleman *dummy;
    dummy = y_eleman();

    dummy->yuksek = yuksek;
    dummy-> sicak = sicak;
    dummy->sonraki = bas;
    bas = dummy;
    dummy->birincil = birincil;
    dummy->ikincil = ikincil;
  }

  return bas;
}

void print_list(eleman *bas){ 

  if(bas->sonraki != NULL)print_list(bas->sonraki);
  printf("%d %f\n", bas->yuksek, bas->sicak);

}

int main(){

  FILE *f; 
  f = fopen("veri.txt", "r");

  double y_birincil,y_ikincil;
  float sicak;
  int hash;

  eleman *bas = y_eleman();
  
  while( !feof(f)){

    fscanf(f, "%lf %lf %f", &y_birincil, &y_ikincil, &sicak);

    hash = hashing(y_birincil,y_ikincil);

    bas = ekleme(bas, hash, sicak, y_birincil, y_ikincil);

  }


  print_list(bas); 
  return 0;
}
