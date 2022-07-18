#ifndef __SORTS__HPP__
#define __SORTS__HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

template <typename T>
void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename Iter>
void bubbleSort(Iter start, Iter end) {
    for(; start != end ; ++start) {
        for(auto tmp = std::next(start); tmp != end; ++tmp) {
            if(*start > *tmp) {
                swap(*start, *tmp);
            }
        }
    }
}

template <typename T>
void merge (T* arr, int start, int mid, int end) {
	T temp[end - start + 1];
	int left_index = start;
	int right_index = mid + 1;
	int temp_index = 0;
	while(left_index <= mid && right_index <= end) {
		if(arr[left_index] <= arr[right_index]) {
			temp[temp_index] = arr[left_index];
			left_index++;
			temp_index++;
		} else {
			temp[temp_index] = arr[right_index];
			right_index++;
			temp_index++;
		}
	}
	while(left_index <= mid) {
		temp[temp_index] = arr[left_index];
		left_index++;
		temp_index++;
	}

	while(right_index <= end) {
		temp[temp_index] = arr[right_index];
		right_index++;
		temp_index++;
	}

	for(int i = start; i <= end; i++) {
		arr[i] = temp[i - start];
	}
}

template <typename T>
void merge_sort (T* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort (arr, start, mid);
        merge_sort (arr, mid + 1, end);
        merge (arr, start, mid, end);
    }
}

template<typename  Iter>
void insertionSort(Iter begin, Iter end) {
    for(auto it1 = begin; it1 != std::prev(end); ++it1) {
        for(auto it2 = std::next(it1); (it2 != begin) && (*(std::prev(it2)) > *it2); --it2){
            swap(*(std::prev(it2)), *it2);
        }
    }
}

template <typename T>
void insertionSort(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j >= 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

template <typename Iter>
void selectionSort(Iter it1, Iter it2) {
    for(; it1 != std::prev(it2); ++it1) {
        auto max = it1; 
        for(auto tmpIter = std::next(it1); tmpIter != it2; ++tmpIter) {
            if (*max > *tmpIter) {
                max = tmpIter;
            }
        }
        swap(*it1, *max);
    }
};

template <typename T>
void quickSort(T *array, int low, int high)
{
    int i = low;
    int j = high;
    T pivot = array[(i + j) / 2];
    T temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

template <typename T>
void Sort(T* arr, const int size) {
    if(std::is_same <double*, decltype(arr)>::value) {
        std::cout << "insertion sort:" << std::endl;
        insertionSort(arr, size);
    } else if(size < 500000) {
        std::cout << "merge sort:" << std::endl;
        merge_sort(arr, 0, size - 1);
    } else {
        std::cout << "quick sort:" << std::endl;
        quickSort(arr, 0, size - 1);
    }
}




#endif

