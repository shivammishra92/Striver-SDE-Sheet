class Solution{
public:
long long int merge(long long arr[], long long int low,long long int mid,long long int high) {
    vector<long long int> temp; // temporary array
    long long int left = low;      // starting index of left half of arr
    long long int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    long long int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

long long int mergeSort(long long arr[],long long int low,long long int high) {
    long long int cnt = 0;
    if (low >= high) return cnt;
    long long int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}


    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr,0,n-1);
    }

};