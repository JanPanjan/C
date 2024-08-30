#include<stdio.h>

int main() {

	// NOTE: inicializiran array
	int evens[] = {2, 4, 6, 8, 10, 12};
	int odds[] = {1, 4, 5, 7, 10, 11}; 

	printf("%i\n", evens[5]); 
	printf("%i\n", evens[2]);

	// NOTE: spreminjanje elementov
	odds[1] = 3;
	odds[4] = 9;

	// NOTE: neinicializiran array
	int arr2[100];
	for(int i = 0; i < 100; i++) {
		arr2[i] = 4 + i;
		printf("%d\n", arr2[i]);
	}

	// NOTE: velikost polja
	int arr3[] = {1,2,3,4,5,6};
	int bytes_len = sizeof(arr3);
	int int_len = sizeof(arr3)/sizeof(int);
	printf("arr3 size(bytes): %d\n", bytes_len);
	printf("arr3 size(integers): %d\n", int_len);

	// NOTE: multidimensional
	int arr[2][2] = {{1,2},{3,4}};

	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(int);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\n", arr[i][j]);
		}
	}

	// NOTE: loopanje skozi elemente
	int polje[] = {1,2,3,4};
	printf("naprej:\n");
	for (int i = 0; i < sizeof(polje)/sizeof(int); i++) {
		printf("%d ", polje[i]);
	}

	// NOTE: loopanje v obratno smer
	printf("\nnazaj:\n");
	for (int i = sizeof(polje)/sizeof(int)-1; i >= 0; i--) {
		printf("%d ", polje[i]);
	}
}
