#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class QuickSorter {
public:
    // Sort the array
    void quickSort(T* array, int size) {
        quickSort(array, 0, size - 1);
    }

private:
    // Recursive quicksort function
    void quickSort(T* array, int start, int end) {
        if (start < end) {
            int pivotIndex = partition(array, start, end);
            quickSort(array, start, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, end);
        }
    }

    // Partition the array
    int partition(T* array, int start, int end) {
        T pivot = array[end];
        int i = start - 1;

        for (int j = start; j < end; ++j) {
            if (array[j] <= pivot) {
                ++i;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[end]);
        return i + 1;
    }
};

// Utility function to format an array as a comma-separated string
template <typename T>
string formatArray(const T* array, int size) {
    stringstream output;
    for (int i = 0; i < size; ++i) {
        output << array[i];
        if (i < size - 1) {
            output << ", ";
        }
    }
    return output.str();
}

#endif // QUICKSORTER_H
