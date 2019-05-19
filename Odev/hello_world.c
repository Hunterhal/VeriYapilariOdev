#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 2000
#define HASH_KEY 1056

struct DataItem {
	float latitude;
	float longitude;
	float temperature;
	int hashKey;
};

struct DataItem* itemArray[SIZE];
struct DataItem* sortedArray[SIZE];
struct DataItem* item;

int hashCode(float latitude, float longitude) {
	// Hash latitude & longitude
	float temp = latitude * 1e6 + longitude * 1e6;
	int key = ((int)abs(temp)) % HASH_KEY;
	return key;
}

void insert(float latitude, float longitude, float temperature, int index) {

	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item->latitude = latitude;
	item->longitude = longitude;
	item->temperature = temperature;

	//get the hash
	item->hashKey = hashCode(latitude, longitude);

	if (index <= sizeof(itemArray))
		itemArray[index] = item;
	else
		return;
}

void bubble_sort(DataItem* list[], int n)
{
	int c, d;
	DataItem* t;

	for (c = 0; c < n - 1; c++)
	{
		for (d = 0; d < n - c - 1; d++)
		{
			if (list[d] != NULL && list[d]->hashKey > list[d + 1]->hashKey)
			{
				/* Swapping */
				t = list[d];
				list[d] = list[d + 1];
				list[d + 1] = t;
			}
		}
	}
}

void display(DataItem* list[]) {
	int i = 0;

	for (i = 0; i < SIZE; i++) {

		if (list[i] != NULL)
			printf(" (%d,%f,%f,%f) \n", list[i]->hashKey, list[i]->latitude, list[i]->longitude, list[i]->temperature);
	}

	printf("\n");
}

int main() {
	float latitude;
	float longitude;
	float temperature;
	static const char filename[] = "C:\Users\elgor\Desktop\VeriYapilariOdev-master\Odev\veri.txt";
	FILE *file = fopen(filename, "r");

	int lineCount = 0;
	if (file != NULL)
	{
		char line[128]; /* or other suitable maximum line size */
		while (fgets(line, sizeof line, file) != NULL) /* read a line */
		{
			sscanf(line, "%f %f %f", &latitude, &longitude, &temperature);
			insert(latitude, longitude, temperature, lineCount);
			++lineCount;
		}
		fclose(file);
	}

	printf(" Listing unsorted values... \n");
	display(itemArray);
	bubble_sort(itemArray, SIZE);
	printf(" Listing sorted values... \n");
	display(itemArray);
	return 0;
}

