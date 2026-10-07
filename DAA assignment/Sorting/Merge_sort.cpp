#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    // Compare elements from both halves
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid)
    {
        temp[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= high)
    {
        temp[k] = A[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        A[i] = temp[k];
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Divide
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        // Merge
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}