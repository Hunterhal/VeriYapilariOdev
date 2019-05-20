#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int hash;
    float latitude,longitude,temperature;
    struct node * next;
};



void pp (struct node* head){
    
    struct node* cur=head;
    
    while (cur != NULL){
        printf("%d\n",cur->hash);
        cur=cur->next;
    }
}




int hash_hesapla(float latitude,float longitude){
    float temp;
    int hash;
    
    temp =latitude* 1e6 +longitude*1e6;
    hash=((int) fabs(temp))%1602;
    
    return hash;
}






struct node* add_node (struct node* head,int hash,float latitude,float longitude,float temperature){
    
  
     head= (struct node*)malloc (sizeof(struct node*));
     head->next=NULL;
     head->hash=hash;
    head->latitude=latitude;
    head->longitude=longitude;
    head->temperature=temperature;
    return head;
    
    
    
    struct node* current = head;
    while(current->next!=NULL){
        
        current=current->next;
        current->next->hash= hash;
        current->next->latitude=latitude;
        current->next->longitude=longitude;
        current->next->temperature=temperature;
        current->next->next=NULL;
        return head;
        
    }
    return head;
}



struct node* nodeolustur(int hash){
    
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->hash= hash;
    head->next=NULL;
   
    return head;
}



void selection_sort(struct node*head){
     struct node* selected=head;
     while(selected->next!=NULL){
         struct node*current=selected;
         struct node*min_node=current;
         int min_hash=current->hash;
         while(current!=NULL){
             if(min_hash>current->hash){
                 min_hash=current ->hash;
                 min_node=current;
             }
             current=current->next;
         }int swap=min_node->hash;
         min_node->hash= swap;
         selected=selected->next;
     }
    
}





int min(struct node*head,int hash)
{
    head=nodeolustur(hash);
    int m;
    m=head->hash;
    
    struct node*current=head;
    while(current!=NULL)
    {
        if(m>current->hash)
        {
            m=current->hash;
        }
        current =current->next;
    }
    return m;
}


struct node * read_from_file (struct node*head){
    FILE* file = fopen("veri.txt", "r");
    int hash;
 
    char line[256];
    float latitude,longitude,temperature;
    struct node*root=NULL;
    while (fgets(line,sizeof(line),file)!=NULL){
        sscanf(line,"%f %f %f",&latitude,&longitude,&temperature);
        hash=  hash_hesapla( latitude,longitude);
        min(root,hash);
     head= add_node(head, hash, latitude, longitude, temperature);
       pp(head);
        
    }fclose(file);
       return head;
}

int main()
{
    struct node* head=NULL;

    read_from_file(head);
    
    return 0;
}



        

  

