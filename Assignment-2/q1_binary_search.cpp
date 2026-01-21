// To implement binary search
// Time Complexity = O log(n)

# include <iostream>
using namespace std;
# define length(arr) sizeof(arr)/sizeof(arr[0])



int binary_search(int arr[], int len, int key) {
    
    int low = 0;
    int high = len-1;
    

    while (low <= high) {
        int mid = (high + low)/2;

        if (key == arr[mid]) return mid;

        if (key < arr[mid]) high = mid-1;

        else low = mid+1;

    }

    return -1;
}


int main() 
{
  
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;
    int length = length(arr);
    sort(arr,arr+length);
    int pos = binary_search(arr, length, key);
    if (pos != -1) cout << "Found at position " << pos << endl;
    else cout << "Not found";

}
