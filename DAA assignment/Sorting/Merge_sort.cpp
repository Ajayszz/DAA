#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= mid)
        temp[k++] = A[i++];

    while (j <= high)
        temp[k++] = A[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        A[i] = temp[k];
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Enter a size between 1 and 100.";
        return 1;
    }

    int A[100];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}