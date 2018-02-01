#include <stdio.h>
#include <stdlib.h>

int *input_vector(int size, int *vector);
int *bubblesort(int size, int *vector);
void print_vector(int size, int *vector);

int main()
{
	int size;
	printf("size of vector: ");
	scanf("%d", &size);
	int *vector = malloc(size*sizeof(int));
	vector = input_vector(size, vector);
	vector = bubblesort(size, vector);
	print_vector(size, vector);
}

// input values in the vector
int *input_vector(int size, int *vector)
{
	int i;
	printf("input vector: ");
	for(i = 0; i < size; i++)
		scanf("%d", &vector[i]);
	return vector;
}

// bubblesort algorithm
int *bubblesort(int size, int *vector)
{
	int i, tmp;
	char ordened;
	while(!ordened)
	{
		ordened = 1;
		for(i = 0; i < size; i++)
			if(vector[i] > vector[i + 1])
			{
				tmp = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = tmp;
				ordened = 0;
			}
	}
	return vector;
}

// print ordened vector
void print_vector(int size, int *vector)
{
	int i;
	printf("ordened vetor: ");
	for(i = 0; i < size; i++)
		printf("%d ", vector[i]);
	printf("\n");
}
