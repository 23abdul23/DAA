/*
Basic Question: Sort an unsorted array using Quick Sort with a randomly chosen pivot.
Topic: Divide and Conquer
Idea Used: Randomize the pivot, partition the array around it, and recursively sort the two partitions.
*/
#include <bits/stdc++.h>
using namespace std;

int partitionVec(vector<int> &v, int l, int h) {
    int pivot = v[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[h]);
    return i + 1;
}

int partition(vector<int> &v, int l, int h) {
    int r = l + rand() % (h - l + 1);
    swap(v[r], v[h]);
    return partitionVec(v, l, h);
}

void QS(vector<int> &v, int l, int h) {
    if (l < h) {
        int pi = partition(v, l, h);
        QS(v, l, pi - 1);
        QS(v, pi + 1, h);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    QS(v, 0, n - 1);

    for (int x : v) {
        cout << x << " ";
    }
}
