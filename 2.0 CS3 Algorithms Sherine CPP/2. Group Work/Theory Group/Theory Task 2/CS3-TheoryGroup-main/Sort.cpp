/*
Templated Quick Sort File

Quicksort Algorithm Steps
-begin by selecting a pivot point in the unsorted array
    *Assignment requires that pivot should be chosen by 4 different methods
        ~Middle value 
        ~Ninther Technique
        ~Median Value of first, last and middle value
    *ideally both sublists should be appx the same size
-move everything smaller than the pivot left & everything bigger to the right
-recursively call quicksort on the sublists


InsertionSort Algorithm Steps
-given an unsorted array, begin by creating a sublist containing an item.
-when an item gets added to your sublist, increment your virtual wall by one.
    *Possible upgrade: perform a binary search on your sorted sublist to find 
     the appropriate location of an item in O(log n)
*/
#include <cmath>
#include <iostream>
#include<cstring>

//prototypes

//Basic Quicksort algorithm
template<class T>
void quickSort(T* list,int begin, int end);

//quicksort w/ insertion sort for small subarrays
template<class T>
void insertionQuickSort(T* list ,int begin, int end);

//insertion sort
template<class T>
void insertionSort(T* list, int end);

//partitioning algorithm for quicksort
template <class T>
int partition(T* list, int begin, int end);

// Scrapped function
// template <class T>
// int findMedianPivot(T* list, int begin, int end);

//partitioning algorithm for median of 3 method on Quicksort
template<class T>
int medianPartition(T* list, int begin, int end);

//Scrapped implementation of median of 3 quicksort
// template<class T>
// void medianQuickSort(T* list, int begin, int end);

//finds k smallest item in list w/o sorting entirety
template<class T>
void kSmallest(T* list, int begin, int end, int k);

//shuffles list
template<class T>
void shuffle(T* list,const int& size);

//Recursive Quicksort
template<class T>
void quickSort(T* list, int begin, int end){
    if(end > begin){
        int pivotIndex = partition(list, begin, end);
        quickSort(list, begin, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, end);
    }
}

//Sort array of type T using quickSort algorithm
//if array size <= switch to Insertion sort
//Help received from the Textbook
template<class T>
void insertionQuickSort(T* list, int begin, int end){
    //Recursive Quicksort w/ Insertion...
    if(end > begin){
        //if subarray size < 20 give it to insertion sort
        if(end - begin <= 20){
            insertionSort(list, end);
        }else{
            //recursion...
            int pivotIndex = partition(list, begin, end);
            insertionQuickSort(list, begin, pivotIndex- 1);
            insertionQuickSort(list, pivotIndex + 1, end);
        }
    }
}


//partitions list by fisrt element
template<class T>
int partition(T* list, int begin, int end){
    //pivot
    T pivot = list[begin];

    //low and high indices
    int low = begin;
    int high = end;
    
    while(high > low){
        // move low index up while element is <= pivot
        while(low <= high && list[low] <= pivot){
            low++;
        }

        //move high index down while element is > pivot
        while(low <= high && list[high] > pivot){
            high--;
        }

        //swap values of low and high 
        if(high > low){
            T temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    //make sure list[high] > pivot
    while(high > begin && list[high] >= pivot){
        high--;
    }

    //swap values of high for pivot
    if(pivot > list[high]){
        list[begin] = list[high];
        list[high] = pivot;

        //this is the new partition
        return high;
    }else{
        //otherwise the partition was the first value...
        return begin;
    }

    return 0;
}

//finds median value of first,middle, and last and partitions based on that median
template<class T>
int medianPartition(T* list, int begin, int end){
    int middle = (end - begin)/2 + begin;
    //takes 3 values and positions the median in the middle index
    //found swap() function @ https://en.cppreference.com/w/cpp/algorithm/swap
    if(list[begin] > list[middle]){    
        std::swap(list[begin], list[middle]);
    }
    if(list[begin] >=list[end]){
        std::swap(list[begin], list[end]);
    }
    if(list[middle] > list[end]){
        std::swap(list[middle], list[end]);
    }
    T pivot = list[middle];

    //low and high indices
    int low = begin;
    int high = end;

    while(high > low){
        // move low index up while element is <= pivot
        while(low <= high && list[low] <= pivot){
            low++;
        }

        //move high index down while element is > pivot
        while(low <= high && list[high] > pivot){
            high--;
        }

        //swap values of low and high 
        if(high > low){
            std::swap(list[low], list[high]);
        }
    }

    //make sure list[high] > pivot
    while(high > low && list[high] > pivot){
        high--;
    }

    //swap values of high for pivot
    if(pivot > list[high]){
        list[middle] = list[high];
        list[high] = pivot;

        //this is the new partition
        return high;
    }else{
        //otherwise the partition was the first value...
        return middle;
    }

}
//Insertion sort (help received from the Pearson Textbook)
template <class T>
void insertionSort(T* list, int size){

    //iterate over list
    for(int i = 1; i <= size; i++){
        //check item after virtual wall
        T temp = list[i];

        //iterate backwards over sorted segment
        int k;
        for(k = i - 1; k >= 0 && list[k] > temp; k--){
            list[k+1] = list[k];
        }

        //insert item at its appropriate location
        list[k+1] = temp;
    }
}

// Ksmallest and improvedSort were "inspired" by the Algorithms in C textbook... 

//finds the median of 3, and gives task to insertion sort if sublist are below 20 items
template<class T>
void improvedSort(T* list, int begin, int end){
    if(end - begin <= 20){
        insertionSort(list, end);
    }else{
        int partition = medianPartition(list, begin, end);
        improvedSort(list, begin, partition - 1);
        improvedSort(list, partition + 1, end);
    }
}

//inspired by Select() function from Algorithms in C
//need to initially pass k-1 in b/c it will find the k+1 smallest, (passing 0 gives the smallest)
template<class T>
void kSmallest(T* list, int begin, int end, int k){
    int i;
    if(end <= begin){
        return;
    }
    //uses the default partition to find a pivot
    i = partition(list, begin, end);
    
    //check current partition pos relative to k
    if(i > k){
        kSmallest(list, begin, i - 1, k);
    }
    if(i < k){
        kSmallest(list, i+1, end, k);
    }

}

//Shuffle algorithm
template<class T>
void shuffle(T* list,const int& size){
    for(int i = size - 1; i > 0; i--){
        int j = rand() % (i+1); //generate int b/n 0 and i
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

//pseudocode from texbook...
// template<class T>
// int textPartition(T* list, int begin, int end){
//     //originally int i = begin - 1???
//     int i = begin, j = end; T v = list[end];
//     for(;;){
//         while( list[++i] < v){
//             while (v < list[--j]){
//                 if(j == begin){
//                     break;
//                 }
//                 if(i >= j){
//                     break;
//                 }
//                 std::swap(list[i], list[j]);
//             }
//         }
//     }
//     std::swap(list[i], list[end]);
//     return i;
// }


//Wrapper class for C style strings just for operator overloading... didnt end up working so i scrapped it.

// struct CString{
//     char* data;
    
//     CString(){
//         this->data = nullptr;
//     }
//     CString(char* data){
//         this->data = data;
//     }
//     ~CString(){
//         delete[] data;
//     }

//     bool operator==(CString& other){
//         if(strcmp(data, other.data) < 0 || strcmp(data, other.data) > 0){
//             return false;
//         }
//         return true;
//     }

//     bool operator!=(CString& other){
//         if(!(data == other.data)){
//             return true;
//         }
//         return false;
//     }

//     bool operator>(CString&other){
//         if(strcmp(data, other.data) > 0){
//             return true;
//         }
//         return false;
//     }

//     bool operator<=(CString &other){
//         if(!(data > other.data)){
//             return true;
//         }
//         return false;
//     }

//     bool operator<(CString&other){
//         if(strcmp(data, other.data) < 0){
//             return true;
//         }
//         return false;
//     }

//     bool operator>=(CString &other){
//         if(!(data < other.data)){
//             return true;
//         }
//         return false;
//     }
    // friend std::ostream& operator<<(std::ostream& out, CString& string);
    // friend std::istream& operator>>(std::istream& in, CString& string);
//};

// std::ostream& operator<<(std::ostream& out,const CString& string){
//     if(string.data == nullptr){
//         out << ' ';        
//     }else{
//         out << string.data;
//     }
//     return out;
// }

// std::istream& operator>>(std::istream& in,const CString& string){
//     in >> string.data;
//     return in;
// }