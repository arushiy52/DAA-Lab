// Quick Sort
# include <iostream>
using namespace std;


// Last Element as Pivot
void QuickSort1(int * arr, int len) {
    if (len<=1) return;

    int pivot = arr[len-1];
    int i=-1;
    for (int j=0; j<len-1; j++ ) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    int part_idx = i+1;     // Partition Index
    swap(arr[i+1], arr[len-1]);
    
    QuickSort1(arr, part_idx);
    QuickSort1(arr+part_idx+1, len-part_idx-1);
    
}



// First Element as Pivot
void QuickSort2(int * arr, int len) {
    if (len<=1) return;

    int pivot = arr[0];
    int i = 0;
    for (int j=1; j<len; j++) {
        if (arr[j] < pivot ) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[0], arr[i]);
    int part_idx = i;
    QuickSort2(arr, part_idx);
    QuickSort2(arr + part_idx +1, len-part_idx-1);
}




// Any element as pivot 
void QuickSort3(int *arr, int len, int pivot_idx=0) {
    if (len <= 1) return;
    
    // Move pivot to the end for easier partitioning
    swap(arr[pivot_idx], arr[len-1]);
    int pivot = arr[len-1];
    
    int i = -1;
    for (int j = 0; j < len-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    int part_idx = i + 1;
    swap(arr[part_idx], arr[len-1]);
    
    QuickSort3(arr, part_idx, 0);  
    QuickSort3(arr + part_idx + 1, len - part_idx - 1, 0);
}





int main() 
{
    int arr[] = {4,2,6,9,2};
    QuickSort1(arr,5);

    for (int i=0; i<5; i++)     cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {4,2,6,9,2};
    QuickSort2(arr2,5);
    for (int i=0; i<5; i++)     cout << arr2[i] << " ";
    cout << endl;


    int arr3[] = {4,2,6,9,2};
    QuickSort3(arr3,5,2);
    for (int i=0; i<5; i++)     cout << arr3[i] << " ";
    cout << endl;


}
