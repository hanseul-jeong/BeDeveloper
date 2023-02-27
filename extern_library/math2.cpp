#include "cal.h"
#include "math2.h"


// 1) 사용되는 파일들 빌드
// $ g++ -fPIC -c math2.cpp math.cpp
// 2) 공유 라이브러리 (.so) 생성
// $ g++ -shared -Wl,-soname,libcal_library.so -o libcal_library.so math2.o math.o


int multiply(int a, int b) {
    int result = 0;
    for (int i=0;i<b;i++)
    {
        // math.cpp 파일에 구현된 add 함수 사용
        result = add(result, a);
    }
    return result;
}

// c로 재선언하는 역할
// c++로 구현된 함수, 변수가 naming mingling 되지 않도록 함.
extern "C"
{
    // 새로운 c 함수와 c++ 함수를 연결해주는 작업 필요
    int c_multiply(int a, int b) {return multiply(a, b);}
}
