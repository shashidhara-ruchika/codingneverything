# https://www.codechef.com/OCT20B/problems/POSAND

def posand(n):
    
    if n == 1:
        print(1)
        return
    
    if n == 3:
        print(2, 3, 1)
        return
    
    if (n != 0) and (n & (n-1) == 0):
        print(-1)
        return
    
    p = [2, 3, 1] + list(range(4, n + 1))
    i = 3
    while i < len(p):
        if (p[i] != 0) and (p[i] & (p[i]-1) == 0):
            p[i], p[i+1] = p[i+1], p[i]
            i += 1 
        i += 1 
    print(*p)
    return
    

t = int(input())
for _ in range(t):
    n = int(input())
    posand(n)
