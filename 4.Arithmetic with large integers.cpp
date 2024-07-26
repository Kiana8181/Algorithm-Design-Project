#include <iostream>
#include<math.h>
using namespace std;

int tedad_ragham(long long x) {
    int count = 0;
    while (x >= 1)
    {
        count++;
        x /= 10;
    }
    return count;
}

long long LG_prod(long long u, long long v, int n, int m) {
    long long x, y, w, z, r, p, q;
    int t, o;
    if (n >= m) t = n;
    else t = m;
    if (u == 0 || v == 0) return 0;
    else if (t <= 2) return u * v;
    else {
        o = t / 2;
        long long l = pow(10, o);
        x = u / l;
        y = u % l;
        w = v / l;
        z = v % l;
        int n1 = tedad_ragham(x + y);
        int m1 = tedad_ragham(w + z);
        r = LG_prod(x + y, w + z, n1, m1);
        int n2 = tedad_ragham(x);
        int m2 = tedad_ragham(w);
        p = LG_prod(x, w, n2, m2);
        int n3 = tedad_ragham(y);
        int m3 = tedad_ragham(z);
        q = LG_prod(y, z, n3, m3);
        long long l1 = pow(10, o);
        int k = 2 * o;
        long long l2 = pow(10, k);
        return (p * l2) + ((r - p - q) * l1) + q;
    }
}

int main() {
    long long x, y;
    cin >> x >> y;
    int n = tedad_ragham(x);
    int m = tedad_ragham(y);
    cout << LG_prod(x, y, n, m);
}



