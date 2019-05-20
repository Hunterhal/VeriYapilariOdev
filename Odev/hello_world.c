#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataNode
{
    float latitude, longitude, temperature;
    int hashValue;
    struct dataNode *next;
};

//latitude ve longitude değerlerine göre hash değerinin hesaplanmasını sağlayan fonksiyon
int calculateHashValue(float latitude, float longitude)
{
    int hash;
    float temp;
    temp = latitude * 1e6 + longitude * 1e6;
    hash = ((int) abs(temp)) % 1040;
    return hash;
}

//bağlı listeye eleman ekleyen fonksiyon
struct dataNode *addToLinkedList(struct dataNode *r, float latitude, float longitude, float temperature)
{
    if(r==NULL)
    {
        r=(struct dataNode *)malloc(sizeof(struct dataNode));
        r->next=NULL;
        r->longitude=longitude;
        r->latitude=latitude;
        r->temperature=temperature;
        r->hashValue=calculateHashValue(latitude,longitude);
        return r;
    }

    struct dataNode *iter=r;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    struct dataNode *temp=(struct dataNode *) malloc(sizeof(struct dataNode));
    iter->next=temp;
    temp->longitude=longitude;
    temp->latitude=latitude;
    temp->temperature=temperature;
    temp->hashValue=calculateHashValue(latitude,longitude);
    temp->next = NULL;
    return r;
}

//dosyadan değerleri okuyup, okunan değerleri listeye ekleyen fonksiyon
struct dataNode* createListFromFile()
{
    float latitude, longitude, temperature;
    char const *const fileName = "veri.txt";
    FILE *file = fopen(fileName, "r");
    char line[256];

    struct dataNode* root=NULL;

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%f %f %f", &latitude, &longitude, &temperature);
        root=addToLinkedList(root, latitude, longitude, temperature);
    }

    fclose(file);
    return root;
}


//bağlı listedeki elemanları hash değerlerine göre sıralayan Bubble sort algoritması
void bubbleSort(struct dataNode* temp)
{
    struct dataNode* help=NULL;
    struct dataNode* store=temp;
    int swap_data;
    while(temp)
    {
        help=store;
        while(help)
        {
            if(help->next&&help->hashValue>help->next->hashValue)
            {
                swap_data=help->hashValue;
                help->hashValue=help->next->hashValue;
                help->next->hashValue=swap_data;
            }
            help=help->next;
        }
        temp=temp->next;
    }
}

//bağlı listeyi ekrana bastıran fonksiyon
void printListOnScreen(struct dataNode *r)
{
    int i = 1;
    struct dataNode *iter=r;
    while (iter != NULL)
    {
        printf("%d: HashValue:%d    Longitude:%f    Latitude:%f    Temperature:%f    \n",
               i, iter->hashValue, iter->longitude, iter->latitude, iter->temperature);
        iter = iter->next;
        i++;
    }
    printf("\n");

}


int main()
{
    struct dataNode* root=createListFromFile();
    printf("Sıralama algoritması yapılmadan önce liste\n");
    printListOnScreen(root);
    bubbleSort(root);
    printf("Sıralama algoritması yapıldıktan sonra liste\n");
    printListOnScreen(root);
    return 0;
}
