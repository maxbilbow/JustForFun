//
//  main.cpp
//  InterviewQuestions
//
//  Created by Max Bilbow on 13/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//template <typename T>
//class vector {
//    
//    public:
//    T array[8];
//    
//    vector (T * array) {
//        
//    }
//};


typedef struct _equation {
    int lhs;
    int rhs;
    int P;
    vector<int> A;
    
    _equation(vector<int> V) {
        A = V;
    }
    
    bool equilibrium() {
        int n = 0;
        cout << "BEGIN: P == " << P << endl;
        vector<int>::iterator i = A.begin();
        while (n <= P-1) {
            lhs += *i.base();
            i++;
            n++;
            cout << ", " << n;
        }
        cout << " == ";
        while (n >= 0) {
            rhs += *i.base();
            i--;
            n--;
            cout << n << ", ";
        }
        cout << endl << lhs << " == "<< rhs << endl;
        return lhs == rhs;
    }
} Equation;

Equation getSides(vector<int> &A, int P) {
    Equation e = Equation(A);
    e.P = P;
    e.lhs = 0;
    e.rhs = 0;
    return e;
}

int solution(vector<int> &A) {
    // write your code in C++11
    unsigned long N = A.size();
    cout << "N = " << N << endl;
    
    for (int i = 0; i<N; ++i) {
        if (getSides(A,i).equilibrium())
            return i;
    }
    
    return -1;
}

int test(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> v =  vector<int>(8);
    vector<int>::iterator i = v.begin();
    i.operator*() = -1;
    ++i.operator*() = 2;
    ++i.operator*() = 5;
    ++i.operator*() = -2;
    ++i.operator*() = 4;
    ++i.operator*() = 1;
    ++i.operator*() = 6;
    ++i.operator*() = 2;
    
    const int sol = solution(v);
    cout << "Solution: " << sol << endl;
    return 0;
}
