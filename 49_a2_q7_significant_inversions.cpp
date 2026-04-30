/*
Basic Question: Count significant inversions where i < j and A[i] > 2*A[j] in O(n log n) time.
Topic: Fenwick Tree
Idea Used: Process the array from right to left and use a Fenwick tree over compressed values to count valid smaller elements.
*/

#include <bits/stdc++.h>
using namespace std;

// Count during merge
int merge(vector<int>& arr, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    // Count significant inversions
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[i] > 2LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }

    // Merge step
    vector<int> temp;
    int i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];

    return count;
}

// Merge sort
int mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    int count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << mergeSort(arr, 0, n - 1);
}