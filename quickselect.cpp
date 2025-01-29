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

int quickselect(int arr[], int k, int l, int r) {
    if(l == r) {
        return arr[l];
    }
    
    int x = partition(arr, l, r);

    if(k <= x){
        return quickselect(arr, k, l, x);
    }
    
    return quickselect(arr, k, x + 1, r);
}

int main() {
  int arr[] = {4, 1, 3, 9, 7};
  int n = sizeof(arr) / sizeof(int);
  int idx = 3;
  int element = quickselect(arr, idx, 0, n - 1);

  cout << idx + 1 << "th smallest element is " << element;
}