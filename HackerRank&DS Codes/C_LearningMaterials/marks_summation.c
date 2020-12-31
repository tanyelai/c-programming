#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int marks_summation(int* arr, char gender, int number_of_students);

int main()
{
	int number_of_students,i,temp;
	char gender;

	scanf("%d",&number_of_students);

	int *arr;
	arr = (int *) malloc (number_of_students * sizeof(int));
	
	for (i=0; i<number_of_students; i++)
	{
		scanf("%d",(arr + i));
	}
	
	scanf("%c",&gender);

	marks_summation(arr, gender, number_of_students);
	free(arr);
	return 0;

}

int marks_summation(int* arr, char gender, int number_of_students)
{
	int i,sum=0;
	for (i=0; i<number_of_students; i++)
	{
		if (gender = 'b'){
			if ((i%2 == 0)){
				sum += arr[i];
			}
		}
		else{
			if ((i%2 == 1)){
				sum += arr[i];
			}
		}
	}
	printf("%d",sum);
	return sum;
}
