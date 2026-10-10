#include <iostream>
using namespace std;

int partitionArray(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionArray(A, low, high);

        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int* A = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    delete[] A;

    return 0;
}