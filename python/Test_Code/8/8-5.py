def my_func(x):
    result =0
    while True:
        if x % 5 == 0:
            x /= 5
        elif x % 3 == 0:
            x /=3
        elif x % 2 == 0:
            x /=2
        else:
            x -=1

        if x ==1:
            break
        print(x)
        result+=1

    print(x)
    print(result)

def answer_func(x):
    d = [0] * 30001

    for i in range(2, x+1):
        d[i] = d[i-1] +1
        if i % 2 == 0:
            d[i] = min(d[i], d[i //2] +1)
        if i% 3 ==0:
            d[i] = min(d[i],d[i//3]+1)
        if i%5 ==0:
            d[i]=min(d[i],d[i //5]+1)
    print(d[x])




x = int(input())

my_func(x)
answer_func(x)



