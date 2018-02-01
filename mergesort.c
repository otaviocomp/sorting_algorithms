#include <stdio.h>
#include <stdlib.h>

int *input_vector(int size, int* vector);
void mergesort(int *vector, int l, int h);
void merge(int *vector, int l, int m, int h);
void sorted_vector(int size, int *vector);

int main()
{
	int size;
	printf("size: ");
	scanf("%d", &size);
	int *vector = malloc(size*sizeof(int));
	vector = input_vector(size, vector);
	mergesort(vector, 0, size - 1);
	sorted_vector(size, vector);
}

// input vector
int *input_vector(int size, int *vector)
{
	int i;
	printf("vector: ");
	for(i = 0; i < size; i++)
		scanf("%d", &vector[i]);
	return vector;
}

// mergesort algorithm
void mergesort(int *vector, int l, int h)
{
	if(l < h)
	{
		int m = (h + l) / 2;
		mergesort(vector, l, m);
		mergesort(vector, m + 1, h);
		merge(vector, l, m, h);
	}
}

// merge
void merge(int *vector, int l, int m, int h)
{
	int i = l, j = m + 1, k = 0;
	int *aux = malloc((h - l + 1)*sizeof(int));
	while(i <= m && j <= h)
	{
		if(vector[i] <= vector[j])
			aux[k++] = vector[i++];
		else
			aux[k++] = vector[j++];
	}
	while(i <= m)
		aux[k++] = vector[i++];
	while(j <= h)
		aux[k++] = vector[j++];
	for(k = l; k <= h; k++)
		vector[k] = aux[k - l];
	free(aux);
}


void sorted_vector(int size, int *vector)
{
	int i;
	printf("sorted vector: ");
	for(i = 0; i < size; i++)
		printf("%d ", vector[i]);
	printf("\n");
}
