#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;
template <class T>
void msort(T* v, int start, int end, int r) {
    int size1 = end - start + 1;
    int size2 = r - end;
    vector<T> L(size1);
    vector<T> R(size2);
    
    for (int i = 0; i < size1; i++) {
        L[i] = v[start + i];
    }
    for (int j = 0; j < size2; j++) {
        R[j] = v[end + j + 1];
    }
    
    int i = 0, j = 0;
    int k;
    for (k = start; k <= r && i < size1 && j < size2; k++) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
    }
    for (i = i; i < size1; ++i) {
        v[k] = L[i];
        k++;
    }
    
    for (j = j; j < size2; j++) {
        v[k] = R[j];
        k++;
    }
}
template <class T>
void mergesort(T* v, int front, int back) {
    if (front < back) {
        int middle = (front + back) / 2;
        mergesort(v, front, middle);
        mergesort(v, middle + 1, back);
        msort(v, front, middle, back);
    }
}

bool sorted(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main(int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    
    //Needs three parameters
    //The vector, front, and back
    mergesort(a, 0, 999);
    assert(sorted(a, 1000));
    
    int b[1001];
    for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
    
    //Needs three parameters
    //The vector, front, and back
    mergesort(b, 0, 1000);
    assert(sorted(b, 1001));
    
    int c[] = { 2 };
    
    //Needs three parameters
    //The vector, front, and back
    mergesort(c, 0, 0);
    assert(sorted(c, 1));
    
    int d[] = { 1, 2, 3, 4, 5 };
    
    //Needs three parameters
    //The vector, front, and back
    mergesort(d, 0, 4);
    assert(sorted(d, 5));
    
    cout << "All tests passed." << endl;
    return 0;
}
