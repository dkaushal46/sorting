#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int arrSize = 20;  // Reduced size for faster testing in online compilers
int arr[arrSize];

void printArray() {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void randomizeArray() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100;  // Limit numbers for readability
    }
    cout << "New random array generated: ";
    printArray();
}

void selectionSort() {
    for (int i = 0; i < arrSize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        cout << "After sorting index " << i << ": ";
        printArray();
    }
}

void insertionSort() {
    for (int i = 1; i < arrSize; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "After inserting index " << i << ": ";
        printArray();
    }
}

void bubbleSort() {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << "After pass " << i + 1 << ": ";
        printArray();
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        cout << "After merging from " << left << " to " << right << ": ";
        printArray();
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout << "Pivot sorted at index " << pi << ": ";
        printArray();
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    randomizeArray();
    int choice;
    
    cout << "Choose sorting algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter choice (1-5): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "\nSelection Sort:\n";
            selectionSort();
            break;
        case 2:
            cout << "\nInsertion Sort:\n";
            insertionSort();
            break;
        case 3:
            cout << "\nBubble Sort:\n";
            bubbleSort();
            break;
        case 4:
            cout << "\nMerge Sort:\n";
            mergeSort(arr, 0, arrSize - 1);
            break;
        case 5:
            cout << "\nQuick Sort:\n";
            quickSort(arr, 0, arrSize - 1);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
    
    cout << "Final sorted array: ";
    printArray();
    return 0;
}
