#include <stdio.h>
void m_sort(int arr[], int beg, int end)
{
    int mid;
    mid = (beg + end) / 2;
    if (beg < end)
    {
        m_sort(arr, beg, mid);
        m_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, k = beg, temp[10];
    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = beg; k < end; k++)
    {
        arr[k] = temp[k];
    }
}
int main()
{
    int n, i, j, k, arr[10];
    printf("Enter the size :");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    m_sort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
