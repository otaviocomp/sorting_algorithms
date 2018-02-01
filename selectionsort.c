#include <stdio.h>
#include <stdlib.h>

int *input_vector(int size, int *vector);
void selectionsort(int size, int *vector);
void print_vector(int size, int *vector);

int main()
{
	int size;
	printf("size of vector: ");
	scanf("%d", &size);
	int *vector = malloc(size*sizeof(int));
	vector = input_vector(size, vector);
	selectionsort(size, vector);
	print_vector(size, vector);
}

int *input_vector(int size, int *vector)
{
	int i;
	printf("input vector: ");
	for(i = 0; i < size; i++)
		scanf("%d", &vector[i]);
	return vector;
}

void selectionsort(int size, int *vector)
{
	int i, j, tmp, min;
	for(i = 0; i < size - 1; i++)
	{
		min = i;
		for(j = i + 1; j < size; j++)
			if(vector[j] < vector[min])
				min = j;
		if(vector[i] != vector[min])
		{
			tmp = vector[i];
			vector[i] = vector[min];
			vector[min] = tmp;
		}
	}
}

void print_vector(int size, int *vector)
{
	int i;
	printf("sorted vetor: ");
	for(i = 0; i < size; i++)
		printf("%d ", vector[i]);
	printf("\n");
}
