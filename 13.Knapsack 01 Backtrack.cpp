#include <stdio.h>
#include <conio.h>
#include<iostream>
using namespace std;
int n;//product amount
double c;//Backpack capacity
double v[100];//The value of each item
double w[100];//The weight of each item
double cw = 0.0;//Current backpack weight
double cp = 0.0;//Current value of items in the backpack
double bestp = 0.0;//Current best value
double perp[100];//After the unit item value is sorted
int order[100];//product code
int put[100];//Set whether to load

//Sort by unit value
void knapsack(){
    int i, j;
    int temporder = 0;
    double temp = 0.0;

    for (i = 1; i <= n; i++)
        perp[i] = v[i] / w[i];
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
            if (perp[i] < perp[j])
            {
                temp = perp[i];
                perp[i] = perp[i];
                perp[j] = temp;

                temporder = order[i];
                order[i] = order[j];
                order[j] = temporder;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
    }
}

void backtrack(int i){
    double bound(int i);
    if (i > n){
        bestp = cp;
        return;
    }
    if (cw + w[i] <= c){
        cw += w[i];
        cp += v[i];
        put[i] = 1;
        backtrack(i + 1);
        cw -= w[i];
        cp -= v[i];
    }
    if (bound(i + 1) > bestp)
        backtrack(i + 1);
}

double bound(int i){
    double leftw = c - cw;
    double b = cp;
    while (i <= n && w[i] <= leftw){
        leftw -= w[i];
        b += v[i];
        i++;
    }
    if (i <= n)
        b += v[i] / w[i] * leftw;
    return b;

}

int main(){
    int i;
    cout << "Please enter the quantity and capacity of the item:";
    cin >> n >> c;
    cout << "Please enter the weight and value of the item:" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "Weight of item" << i << " : ";
        cin >> w[i];
        cout << "The value is:";
        cin >> v[i];
        order[i] = i;
    }
    knapsack();
    backtrack(1);
    cout << "The most valuable is: " << bestp << endl;
    cout << "The item number to be loaded is:";
    for (i = 1; i <= n; i++){
        if (put[i] == 1)
            cout << order[i];
    }
    return 0;
}
