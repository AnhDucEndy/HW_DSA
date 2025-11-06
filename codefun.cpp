#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int depth = 0) {
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << string(depth * 2, ' ') << "Sau khi chia tại phần tử cuối (" 
             << arr[pi] << "): ";
        printArray(arr);

        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

void merge(vector<int> &arr, int left, int mid, int right, int depth) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << string(depth * 2, ' ') << "Sau khi sort: ";
    printArray(arr);
}

void mergeSort(vector<int> &arr, int left, int right, int depth = 0) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
        merge(arr, left, mid, right, depth);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr1 = {9, 3, 7, 1, 5, 2};
    vector<int> arr2 = arr1;

    cout << " QUICK SORT " << endl;
    cout << "Mảng ban đầu: ";
    printArray(arr1);
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "Kết quả cuối cùng: ";
    printArray(arr1);

    cout << "\n MERGE SORT " << endl;
    cout << "Mảng ban đầu: ";
    printArray(arr2);
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Kết quả cuối cùng: ";
    printArray(arr2);

    return 0;
}

/*
PHÂN TÍCH

1 QUICK SORT:
 Độ phức tạp: Trung bình:  O(n log n)

2 MERGE SORT:
 Độ phức tạp: Mọi trường hợp: O(n log n)

*/
