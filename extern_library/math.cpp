#include "cal.h"

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

// extern에 선언되지 않은 함수가 있을 때에도 잘 동작함
int complicated(int a, int b){
    int c = minus(a, b);
    return add(c, b);
}

// c로 재선언하는 역할
// c++로 구현된 함수, 변수가 naming mingling 되지 않도록 함.
extern "C"
{
    // 새로운 c 함수와 c++ 함수를 연결해주는 작업 필요
    int c_add(int a, int b) {return add(a, b);}
    int c_minus(int a, int b) {return minus(a, b);}
}