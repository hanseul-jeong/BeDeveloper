from math import add, minus

if __name__ == "__main__":
    # $ g++ -c -fPIC math.cpp -o math.o
    # $ g++ -shared -Wl,-soname,libmath.so -o libmath.so math.o

    print(add(1, 2))
    print(minus(3,4))