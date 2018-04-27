/*	--------------------------------------------------
*	To Do: (1) make a copy of the values from one array to another array
*		   (2) sort an array in ascending order
*          (3) perform a linear search on the unsorted array
*		   (4) perform a binary search on the sorted array
*	--------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

// arrayCopy function copy the values from one array to another array
void arrayCopy (int fromArray[], int toArray[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		toArray[i] = fromArray[i];
	}
}// end of arrayCopy()

// sort function sorts an array in ascending order. This is Selection sort
void sort (int arr[], int size)
{
	int i;
	int j = 0;
	int indexSmallest = 0;
	int temp = 0; // temporay variable for swap
	
	for (i = 0; i < size; i++)
	{
		// find index of smallest remaining element
		indexSmallest = i;
		
		for (j = i+1; j < size; ++j)
		{
			if (arr[j] < arr[indexSmallest])
			{
				indexSmallest = j;
			}
		}
		
		// swap numbers[i] and numbers[indexSmallest]
		temp = arr[i];
		arr[i] = arr[indexSmallest];
		arr[indexSmallest] = temp;
	}
}// end of sort()

// linSearch function performs a linear search.
int linSearch (int arr[], int size, int target, int* numComparisons)
{
	int i;
	*numComparisons = 0;

	for (i = 0; i < size; ++i)
	{
		++*numComparisons;
		if (arr[i] == target)
		{
			return i;
		}

	}
	return -1; // not found
}// end of linSearch()

// binSearch function performs a binary search
int binSearch (int arr[], int size, int target, int* numComparisons)
{
	int mid = 0;
	int low = 0;
	int high = 0;
	*numComparisons = 0;

	high = size - 1;

	while (high >= low)
	{

		mid = (high + low) / 2;
				
		++*numComparisons;

		if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	
	return -1; // not found
}// end of binSearch()

/*****************************************************************************/

int main()
{
	int *arr2;
	int size2 = 100;
	int val;
	int i = 0;
	int k;
        int *arrCopy;
	//variables for Linear and Binary search
        int target = 0;
        int numComparisons=0;
        int targetIndex = 0;

	arr2 = (int *) malloc ( size2 * sizeof(int) );
	
	// prompt the user for input
	printf ("Enter in a list of numbers followed by the terminal value of -999:\n");

	// loop until the user enters -999
	scanf (" %d", &val);
	while (val != -999)
	{	
		/* check if the array is full before adding the value */
		if ( i >= size2 )
		{
			/* add more space in the array - this code doubles the array size */
			int *temp;
			temp = (int *) malloc ( size2 * 2 * sizeof(int) );

			/* copy existing value to new memory space */
			arrayCopy(arr2, temp, size2);

			/* de-allocate the old memory space */
			free (arr2);

			/* update the variables to reflect the larger memory space */
			arr2 = temp;
			size2 = size2 * 2;

		}

		arr2[i] = val; 
		i++;

		scanf (" %d", &val);
	}

	
	arrCopy = (int *) malloc (i * sizeof(int) );
	arrayCopy(arr2, arrCopy, i); // arr2 is copied to arrCopy
	sort(arrCopy, i);  //sorts arrCopy in an ascending order
        
	// prints the unsorted array
	printf ("\nUNSORTED: ");
	for (k = 0; k < i; ++k)
	{
		printf ("%i ", arr2[k]);
	}
	printf ("\n");
	
	//prints the sorted array 
	printf ("\nSORTED: ");
	for (k = 0; k < i; ++k)
	{
		printf ("%i ", arrCopy[k]);
	}
	printf ("\n");
	
	printf ("Enter a value or -999 to terminate: \n");
	scanf ("%d", &target);

	// tests for every key in the file
	while(target != -999)
	{
		targetIndex = linSearch (arr2, i, target, &numComparisons); // does linear search for the entered key
	
		printf ("\nLinear Search: ");
        	if (targetIndex == -1)
        	{
                	printf ("%d was not found.\n", target);
                	printf ("Num of Comparisons to search %d is %d\n", target, numComparisons);
        	}
        	else
        	{
                	printf ("Found %d at index %d.\n", target, targetIndex);
                	printf ("Num of Comparisons to search %d is %d\n", target, numComparisons);
        	}

		targetIndex = binSearch (arrCopy, i, target, &numComparisons); // does binary search for the same key entered for linear search

		printf ("\nBinary Search: ");
		if (targetIndex == -1)
		{
			printf ("%d was not found.\n", target);
                	printf ("Num of Comparisons to search %d is %d\n", target, numComparisons);
		}
		else
		{
			printf ("Found %d at index %d.\n", target, targetIndex);
			printf ("Num of Comparisons to search %d is %d\n", target, numComparisons);
		}
		
		printf ("Enter a value or -999 to terminate: \n");
		scanf ("%d", &target);
        }
	return 0;
}

