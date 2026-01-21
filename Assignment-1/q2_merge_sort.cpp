// Merge sort
// Time Complexity = O(nlogn)

#include <iostream>
using namespace std;



void merge_sort(int arr[], int size)
{
    if (size <= 1)
        return;

    else
    {
        int i = 0, j=0, k = 0;
        int hsize = size / 2;
        int size1 = size / 2;
        int size2 = size - size1;

        int arr1[size1], arr2[size2];

        for (int x = 0; x < size1; x++)
        {
            arr1[x] = arr[x];
        }

        for (int x = 0; x < size2; x++)
        {
            arr2[x] = arr[size1+x];
        }

        merge_sort(arr1, size1);
        merge_sort(arr2, size2);

        while (i < size1 && j < size2)
        {

            if (arr1[i] <= arr2[j])
            {
                arr[k] = arr1[i];
                i++;
            }
            else
            {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < size1)
            arr[k++] = arr1[i++];
        while (j < size2)
            arr[k++] = arr2[j++];
    }
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int len = 6;
    merge_sort(arr,len);
    for (int i = 0; i< len; i++) cout << arr[i] << " ";
    cout << endl;


    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int len2 = 7;
    merge_sort(arr2,len2);
    for (int i = 0; i< len2; i++) cout << arr2[i] << " ";
    cout << endl;
}
