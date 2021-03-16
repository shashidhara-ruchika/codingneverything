# https://www.codechef.com/JULY20B/problems/DRCHEF

t = int(input())
for _ in range(t):
    n, x = input().split()
    n = int(n)
    x = int(x)
    a = list(map(int, input().split()))
    a.sort()
    ma = len(a)
    days = 0
    s = 0
    while(s+1 < ma and a[s] < x):
        s+=1 
    if(s > 0):
        c1 = 0
        temp = x 
        while(temp < a[s]):
            temp = temp << 1 
            c1 += 1 
        temp = a[s-1] * 2
        c2 = 1
        while(temp < a[s]):
            temp = temp << 1 
            c2 += 1 
        if(c2 <= c1):
            s -= 1 
    f = s 
    r = s - 1
    while(f < ma):
        days += 1 
        if(x >= a[f]):
            x = a[f]
            a[f] = 0
            f += 1 
        x = x << 1 
    while(r >= 0):
        days += 1 
        if(x >= a[r]):
            x = a[r]
            a[r] = 0
            r -= 1 
        x = x << 1 
    print(days)    
            
           
        
    

