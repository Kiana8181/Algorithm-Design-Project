#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
    if (W < 0)
        return INT_MIN;
    if (n < 0 || W == 0)
        return 0;
    int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
    int ex = knapSack(v, w, n - 1, W);
    return max(in, ex);
}
int main() {
    int n;
    cout << "Please enter the number of items: ";
    cin >> n;
    int* v = new int[n];
    int* w = new int[n]; 
    int W;
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " Value ";
        cin >> v[i];
        cout << "Enter " << i + 1 << " Weight ";
        cin >> w[i];
    }
    cout << "Enter Knapsack weight \n";
    cin >> W;
    cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
    return 0;
}
