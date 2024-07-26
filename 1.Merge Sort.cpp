#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

void _sort(int low, int high, int[]);
void _merge(int, int, int, int, int[]);
int n;

int main()
{
	cout << "Please enter size of array: ";
	cin >> n;
	int _size = n;
	int* data=new int[_size];

	for (int count = 0; count < _size; count++){
		cin >> data[count];
	}
	cout << "Unsorted Vector : " << endl;
	for (int count = 0; count < _size; count++){
		cout << " " << data[count];
	}
	cout << endl << endl;
	_sort(0, _size - 1, data);

	cout << "Sorted Vector : " << endl;
	for (int count = 0; count < _size; count++){
		cout << " " << data[count];
	}

	cout << endl << endl;

	system("pause");

	return 0;
}


void _sort(int low, int high, int  vec[]){
	if ((high - low) >= 1){
		int mid1 = (high + low) / 2;
		int mid2 = mid1 + 1;

		_sort(low, mid1, vec);
		_sort(mid2, high, vec);

		_merge(low, mid1, mid2, high, vec);
	}
}

void _merge(int left, int mid1, int mid2, int right, int vec[]){
	int _left = left;
	int _right = mid2;
	int flg = left;
	int* comb=new int[n];
	while (_left <= mid1 && _right <= right){
		if (vec[_left] <= vec[_right]){
			comb[flg] = vec[_left];
			flg++;
			_left++;
		}
		else{
			comb[flg] = vec[_right];
			flg++;
			_right++;
		}
	}
	if (_left == mid2){
		while (_right <= right){
			comb[flg] = vec[_right];
			flg++;
			_right++;
		}
	}
	else{
		while (_left <= mid1){
			comb[flg] = vec[_left];
			flg++;
			_left++;
		}
	}
	for (int count = left; count <= right; count++){
		vec[count] = comb[count];
	}
}

