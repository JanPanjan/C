#include<stdio.h>

int main() {

	// inicializiran array
	int evens[] = {2, 4, 6, 8, 10, 12};
	int odds[] = {1, 4, 5, 7, 10, 11}; 

	printf("%i\n", evens[5]); 
	printf("%i\n", evens[2]);

	// spreminjanje elementov
	odds[1] = 3;
	odds[4] = 9;

	// neinicializiran array
	int arr2[100];
	for(int i = 0; i < 100; i++) {
		arr2[i] = 4 + i;
		printf("%d\n", arr2[i]);
	}

	// velikost polja
	int arr3[] = {1,2,3,4,5,6};
	int bytes_len = sizeof(arr3);
	int int_len = sizeof(arr3)/sizeof(int);
	printf("arr3 size(bytes): %d\n", bytes_len);
	printf("arr3 size(integers): %d\n", int_len);

	// multidimensional
	int arr[2][2] = {{1,2},{3,4}};

	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(int);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\n", arr[i][j]);
		}
	}
}
