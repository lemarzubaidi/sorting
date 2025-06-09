#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int Partition(int arr[], int left, int right) {
    int povit = arr[right];
    int i = left - 1;
    for (int j = left; j <= right-1; j++)
    {
        if (arr[j] <= povit) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
int RandomPartition(int arr[], int left, int right) {
    int i = left+rand()%(right-left+1);
    swap(arr[right], arr[i]);
    return Partition(arr, left, right);
}
int Randomize_Select(int arr[], int left, int right, int i) {
    if (left == right) {
        return arr[left];
    }
    int q = RandomPartition(arr, left, right);
    int k = q - left+1;
    if (i == k)
        return arr[q];
    if (i <= k)
      return  Randomize_Select(arr, left, q - 1, i);
    else
       return Randomize_Select(arr, q + 1, right, i - k);

}


