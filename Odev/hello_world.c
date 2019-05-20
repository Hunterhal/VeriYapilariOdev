#include <stdio.h>
#include <stdlib.h>

struct node{  //liste elemanları tanımlaması.

  double x;
  double y;
  float temp;
  int h;

  struct node *left;

};

typedef struct node element;

element* new_element(){
  element *N;
  N = (element*)malloc(sizeof(struct node));
  N->left = NULL;
  return N;
}



int hashing(double x, double y){ //hash işlemi.
  long a = x*1e6 + y*1e6;
  return ((int)abs(a))%1064;
}

element *adding(element *head, int h, float temp, double x, double y){ //listeye yeni elemanı özyinelemeli şekilde, doğru sırayla ekleme işlemi.

  if(head == NULL){

    element *dummy;
    dummy= (element *) malloc(1);

    dummy->h = h;
    dummy->x = x;
    dummy->y = y;
    dummy->temp = temp;
    head = dummy;

  }

  else if(head->h > h){

    head->left = adding(head->left, h, temp, x, y);
  }

  else{

    element *dummy;
    dummy = new_element();

    dummy->h = h;
    dummy-> temp = temp;
    dummy->left = head;
    head = dummy;
    dummy->x = x;
    dummy->y = y;
  }

  return head;
}

void print_list(element *head){ //liste yazdırma işlemi.

  if(head->left != NULL)print_list(head->left);
  printf("%d %f\n", head->h, head->temp);

}

int main(){

  FILE *f; //dosyanın açılası.
  f = fopen("veri.txt", "r");

  double location_x,location_y;
  float temp;
  int hash;

  element *head = new_element();
  //dosyanın sonuna kadar ,elemanları okuyabildiği taktirde, devam edecen listeyi oluşturma döngüsü.

  while( !feof(f)){

    fscanf(f, "%lf %lf %f", &location_x, &location_y, &temp);

    hash = hashing(location_x,location_y);

    head = adding(head, hash, temp, location_x, location_y);

  }

  print_list(head); //listenin küçük hash değerinden büyüğe doğru yazımı.

  return 0;
}
