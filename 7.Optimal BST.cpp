#include <iostream>
using namespace std;

float sum(float frequency[], int i, int j){
    float sum = 0;
    for (int x = i; x <= j; x++)
        sum += frequency[x];
    return sum;
}

float optimalCost(float frequency[], int i, int j){
    if (j < i)
        return 0;
    if (j == i)
        return frequency[i];

    float frequencySum = sum(frequency, i, j);

    float min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        float cost = optimalCost(frequency, i, r - 1) + optimalCost(frequency, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + frequencySum;
}

float optimalSearchTree(int keys[], float frequency[], int n){
    return optimalCost(frequency, 0, n - 1);
}

int main(){
    cout << "Please enter the number of keys: " << endl;
    int n;
    cin >> n;
    int* keys = new int[n];
    cout << "Please enter keys: " << endl;
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    cout << "Please enter the frequency of each key: " << endl;
    float* frequency = new float[n];
    for (int i = 0; i < n; i++)
        cin >> frequency[i];

    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n);

    return 0;
}
