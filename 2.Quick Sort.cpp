#include <iostream>
using namespace std;

int partition(int A[], int p, int q){
    int temp;
    int x = A[p];
    int i = p;
    for (int j = p + 1; j <= q; j++){
        if (A[j] <= x){
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[i];
    A[i] = A[p];
    A[p] = temp;
    return i;
}

void Quick_sort(int A[], int p, int r){
    int q;
    if (p < r){
        q = partition(A, p, r);
        Quick_sort(A, p, q - 1);
        Quick_sort(A, q + 1, r);
    }
}

int main(){
    int n;
    cout << "Please enter size of array: ";
    cin >> n;
    int* A = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // print array before sort
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    Quick_sort(A, 0, n-1);

    // print array after sort
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
