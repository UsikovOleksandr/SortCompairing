#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void BubbleSort(int* array1, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array1[j] > array1[j + 1])
                swap(array1[j], array1[j + 1]);
        }
    }
}

///....................................................................................................

void Merge(int* array2, int first, int last, int size) {
    int middle, start, final, j;
    int* mas = new int[size];
    middle = (first + last) / 2;  //middle element calculation
    start = first;                //beginning of the left part
    final = middle + 1;           //beginning of the right part
    for (j = first; j <= last; j++)  //perform from start to finish
        if ((start <= middle) && ((final > last) || (array2[start] < array2[final]))) {
            mas[j] = array2[start];
            start++;
        }
        else {
            mas[j] = array2[final];
            final++;
        }
    //returning the result to a list
    for (j = first; j <= last; j++)
        array2[j] = mas[j];
    delete[] mas;
}


//recursive sort procedure
void MergeSort(int* array2, int first, int last, int size) {
    if (first < last) {
        MergeSort(array2, first, (first + last) / 2, size);  //left side sort
        MergeSort(array2, (first + last) / 2 + 1, last, size);  //right side sort
        Merge(array2, first, last, size);  //merging of two parts
    }
}

///....................................................................................................

int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void CountingSort(int array[], int size, int div)
{
    int* output = new int[size];
    int count[10] = { 0 };

    for (int i = 0; i < size; i++)
        count[(array[i] / div) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / div) % 10] - 1] = array[i];
        count[(array[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}


void RadixSort(int array[], int size)
{
    int m = getMax(array, size);
    for (int div = 1; m / div > 0; div *= 10)
        CountingSort(array, size, div);
}

///....................................................................................................

void arrayFill(int* array1, int* array2, int* array3, int size)
{
    for (int i = 0; i < size; i++) {
        array1[i] = rand() % 100;
        array3[i] = rand() % 100;
    }
    for (int i = 1; i <= size; i++) {
        array2[i] = rand() % 100;
    }
}

int main()
{
    srand(time(NULL));

    clock_t start;
    double duration;

    int size, size2;

    cout << "Enter the number of array elements: ";
    cin >> size;

    size2 = size + 1;

    int* array1 = new int[size];
    int* array2 = new int[size2];
    int* array3 = new int[size];


    arrayFill(array1, array2, array3, size);

    start = clock();
    BubbleSort(array1, size);
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << endl << "Array after BubbleSort: ";

    cout << endl << "Sorting time: " << duration << endl;

    start = clock();
    MergeSort(array2, 1, size, size2);
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << endl << "Массив после MergeSort: ";

    cout << endl << "Sorting time: " << duration << endl;

    start = clock();
    RadixSort(array3, size);
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << endl << "Array after RadixSort: ";

    cout << endl << "Sorting time: " << duration << endl;

    delete[] array1;
    delete[] array2;
    delete[] array3;

    system("pause");
    return 0;
}
