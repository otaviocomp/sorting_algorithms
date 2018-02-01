#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *input_vector(int size, int *vector);
void quicksort(int *vector, int l, int h);
int partition(int *vector, int l, int h);
void sorted_vector(int size, int *vector);

int main()
{
	int size;
	printf("size: ");
	scanf("%d", &size);
	int *vector = malloc(size*sizeof(int));
	vector = input_vector(size, vector);
	quicksort(vector, 0, size - 1);
	sorted_vector(size, vector);
}

// input vector
int *input_vector(int size, int *vector)
{
	int i;
	printf("input vector: ");
	for(i = 0; i < size; i++)
		scanf("%d", &vector[i]);
	return vector;	
}

// quicksort algorithm
void quicksort(int *vector, int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(vector, l, h);
		quicksort(vector, l, j - 1);
		quicksort(vector, j + 1, h);
	}
}

// partition algorithm
int partition(int *vector, int l, int h)
{
	int pivot, i = l + 1, j = h, tmp;
	pivot = vector[l];
	while(i <= j)
	{
		if(vector[i] <= pivot)
			i++;
		else if(pivot < vector[j])
			j--;
		else
		{
			tmp = vector[i];
			vector[i] = vector[j];
			vector[j] = tmp;
			i++;
			j--;
		}
	}
	vector[l] = vector[j];
	vector[j] = pivot;
	return j;
}

void sorted_vector(int size, int *vector)
{
	int i;
	printf("sorted vector: ");
	for(i = 0; i < size; i++)
		printf("%d ", vector[i]);
	printf("\n");	
}
