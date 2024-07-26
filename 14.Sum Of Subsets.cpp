#include <iostream>
#include <stack>

using namespace std;

int numberOfElements, sum;
int* set = new int[numberOfElements];

class SubSet {
public:
    stack<int> solutionSet;
    bool hasSolution;

    void solve(int s, int idx) {
        if (s > sum)
            return;
        if (s == sum) {
            hasSolution = true;
            displaySolutionSet();
            return;
        }

        for (int i = idx; i < numberOfElements; i++) {
            solutionSet.push(set[i]);
            solve(s + set[i], i + 1);
            solutionSet.pop();
        }
    }

    void displaySolutionSet() {
        stack<int> temp;

        while (!solutionSet.empty()){
            cout << solutionSet.top() << " ";
            temp.push(solutionSet.top());
            solutionSet.pop();
        }
        cout << '\n';
        while (!temp.empty()){
            solutionSet.push(temp.top());
            temp.pop();
        }
    }
};

int main(){
    cout << "Enter the number of elements in the set" << endl;
    cin >> numberOfElements;
    cout << "Enter the values" << endl;
    for (int i = 0; i < numberOfElements; i++)
        cin >> set[i];
    cout << "Enter the value of sum" << endl;
    cin >> sum;
    SubSet ss;
    ss.solve(0, 0);
    if (ss.hasSolution == false)
        cout << "No Solution";
    return 0;
}
