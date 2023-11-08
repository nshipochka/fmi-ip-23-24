#include <iostream>
const int MAX_SIZE = 256;

//helper functions
void inputArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void copyArray(int arr[], int n, int copy[]) {
	for (int i = 0; i < n; ++i)
		copy[i] = arr[i];
}

//task 1
void printBackwards(int arr[], int n) {
	for (int i = n - 1; i > 0; --i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//task 2
bool isPrime(int n) {
	if (n <= 1)
		return false;

	for (unsigned i = 2; i <= int(sqrt(n)); i++)
		if (n % i == 0)
			return false;

	return true;
}

void printPrimesCount(int arr[], int n) {
	int count = 0;

	for (int i = 0; i < n; ++i) {
		if (isPrime(arr[i])) {
			count++;
			std::cout << arr[i] << std::endl;
		}
	}

	std::cout << "count: " << count << std::endl;
}

//task 3
void generateInterval(int arr[], int a, int b) {
	if (a > b || b - a + 1 > MAX_SIZE)
		throw std::invalid_argument("Size of interval too small/big");

	for (int i = 0; a <= b; ++a, ++i) {
		arr[i] = a;
	}
}

//task 4
void insertElement(int arr[], int& n, int elem, int pos) {
	if (n + 1 > MAX_SIZE)
		throw std::out_of_range("Not enough space in array to insert");

	if (pos > n)
		throw std::invalid_argument("Not a valid position for insertion");

	for (int i = n; i > pos; --i)
		arr[i] = arr[i - 1];

	n++;
	arr[pos] = elem;
}

//task 5
void removeAtPos(int arr[], int& n, int pos) {
	if (pos >= n)
		throw std::invalid_argument("Not a valid position for deletion");

	for (int i = pos; i < n; ++i)
		arr[i] = arr[i + 1];

	n--;
}

//task 5.1
void removeElement(int arr[], int& n, int elem) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == elem)
			removeAtPos(arr, n, i);
	}
}

// task 6
int firstOccurance(int arr[], int n, int elem) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == elem)
			return i;
	}

	return -1;
}

int lastOccurance(int arr[], int n, int elem) {
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == elem)
			return i;
	}

	return -1;
}

int countOccurances(int arr[], int n, int elem) {
	int first = firstOccurance(arr, n, elem);
	if (first == -1)
		return 0;

	int count = 0;
	for (int i = first; i < n; ++i) {
		if (arr[i] == elem)
			count++;
	}

	return count;
}

//task 7
void printUniqueElements(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		if (countOccurances(arr + i, n, arr[i]) == 1)
			std::cout << arr[i] << std::endl;
	}
}

//task 8
void printRepeatingElements(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		if (countOccurances(arr + i, n, arr[i]) > 1)
			std::cout << arr[i] << std::endl;
	}
}

//task9
void printElementOccurancesCount(int arr[], int n) {
	int uniqueElements[MAX_SIZE];
	int uniqueSize = 0;

	for (int i = 0; i < n; ++i) {
		if (countOccurances(arr + i, n, arr[i]) == 1)
			uniqueElements[uniqueSize++] = arr[i];
	}

	for (int i = 0; i < uniqueSize; ++i) {
		std::cout << uniqueElements[i] << ": " << countOccurances(arr, n, uniqueElements[i]) << std::endl;
	}
}

//task 10
bool compareArrInterval(int arr[], int n, int a, int b) {
	int uniqueCount = 0;

	for (int i = 0; i < n; ++i)
		if (countOccurances(arr + i, n, arr[i]) == 1)
			uniqueCount++;
	
	if (uniqueCount != (b - a + 1))
		return false;

	return true;
}

//task 11
int findUnique(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		if (countOccurances(arr, n, arr[i]) == 1)
			return arr[i];
}

//task12
bool isTrion(int arr[], int n) {
	for (int i = 1; i < n - 1; ++i) {
		if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])
			return false;

		if (arr[i - 1] > arr[i] && arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

//task 13
void insertInSorted(int arr[], int& n, int elem) {
	int i = 0;
	while (i < n && elem > arr[i]) {
		i++;
	}

	insertElement(arr, n, elem, i);
}

//task 14
void fillOddsSubarray(int arr[], int& arrLen, int odds[], int& oddsLen) {
	oddsLen = 0;
	for (int i = 0; i < arrLen; ++i) {
		if (arr[i] % 2) {
			odds[oddsLen] = arr[i];
			oddsLen++;
		}
	}
}

void fillEvensSubarray(int arr[], int& arrLen, int evens[], int& evensLen) {
	evensLen = 0;
	for (int i = 0; i < arrLen; ++i) {
		if (arr[i] % 2 == 0) {
			evens[evensLen] = arr[i];
			evensLen++;
		}
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

void mergeIntoArr(int arr1[], int& size1, int arr2[], int size2) {
	for (int i = 0; i < size2; i++) {
		insertInSorted(arr1, size1, arr2[i]);
	}
}


int main() {
	
	/*int arr[MAX_SIZE];
	int n;
	
	std::cin >> n;
	inputArray(arr, n);*/
	
	//task 1
	/*printBackwards(arr, n);*/

	//task 2
	/*printPrimesCount(arr, n);*/

	//task 3
	/*int a, b;
	std::cin >> a >> b;

	try {
		generateInterval(arr, a, b);
		printArray(arr, b - a + 1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}*/

	//task 4
	/*insertElement(arr, n, 15, 2);
	printArray(arr, n);*/

	//task5
	/*removeElement(arr, n, 2);
	printArray(arr, n);*/

	// task 13
	/*int arr[MAX_SIZE] = { 1, 2, 3, 4, 5, 7 };
	int n = 6;
	insertInSorted(arr, n, 5);
	printArray(arr, n);*/

	//task 14
	int arr[] = { 1, 5, 6, 18, 21, 3, 15, 14, 68, 39, 2, 9, 3, 8, 18 };
	int odds[MAX_SIZE], evens[MAX_SIZE];

	int arrSize = sizeof(arr) / sizeof(int);
	int oddsSize = 0, evensSize = 0;

	fillOddsSubarray(arr, arrSize, odds, oddsSize);
	fillEvensSubarray(arr, arrSize, evens, evensSize);

	insertionSort(odds, oddsSize);
	insertionSort(evens, evensSize);

	printArray(odds, oddsSize);
	printArray(evens, evensSize);

	mergeIntoArr(odds, oddsSize, evens, evensSize);

	printArray(odds, oddsSize);

	return 0;
}