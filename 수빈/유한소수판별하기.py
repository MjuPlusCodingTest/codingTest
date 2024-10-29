def make (a, b):
    if (a > b):
        for i in range(2, a+1):
            if (a % i == 0 and b % i == 0):
                a = int(a / i)
                b = int(b / i)
                return make(a, b)
        return a, b
    if (b > a):
        for i in range(2, b+1):
            if (a % i == 0 and b % i == 0):
                a = int(a / i)
                b = int(b / i)
                return make(a, b)
        return a, b

def solution(a, b):
    a, b = make(a, b)
    
    while (b % 2 == 0):
        b = int(b / 2)
    while (b % 5 == 0):
        b = int(b / 5)
    
    if (b == 1):
        return 1
    else:
        return 2