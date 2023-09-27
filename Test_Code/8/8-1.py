def fibo(x):
    if x == 1 or x == 2:
        print(x)
        return 1
    return fibo(x-1)+ fibo(x-2)

print(fibo(100))
