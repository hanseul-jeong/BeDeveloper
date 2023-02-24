
from ctypes import CDLL
import ctypes

# shared object 불러오는 역할.
lib = CDLL('./libmath.so')

# python에서 redefine
def add(a, b):
    # 매개변수 type 지정
    # 이 과정이 없으면 default 값은 c_int로 지정됨.
    lib.c_add.argtypes = [ctypes.c_int, ctypes.c_int]
    # return type 지정
    lib.c_add.restype = ctypes.c_int
    return lib.c_add(a,b)

def minus(a, b):
    lib.c_minus.argtypes = [ctypes.c_int, ctypes.c_int]
    lib.c_minus.restype = ctypes.c_int
    return lib.c_minus(a,b)
