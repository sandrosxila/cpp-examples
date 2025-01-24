#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int l, int r) {
  int mid = (l + r) / 2;
  int mn = min({arr[l], arr[mid], arr[r]});
  int mx = max({arr[l], arr[mid], arr[r]});

  int pivot = arr[l] + arr[mid] + arr[r] - mn - mx;

  arr[l] = mn;
  if (r - l > 1)
    arr[mid] = pivot;
  arr[r] = mx;

  int i = l, j = r;
  while (true)
  {
    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      return j;

    swap(arr[i], arr[j]);
  }
}

void quicksort(int arr[], int l, int r) {
  if (l >= r)
    return;

  int pivot_index = partition(arr, l, r);

  quicksort(arr, l, pivot_index);
  quicksort(arr, pivot_index + 1, r);
}

int main() {
  int arr[] = {4, 1, 3, 9, 7};
  int n = sizeof(arr) / sizeof(int);

  quicksort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}