# https://www.codechef.com/MARCH20B/problems/CHPINTU       

t = int(input())
for j in range(t):
    n, m = list(map(int,input().split(' ')))
    f = list(map(int,input().split(' ')))
    p = list(map(int,input().split(' ')))
    d = dict()
    
    for i in range(len(f)):
        if f[i] in d:
            d[f[i]] += p[i]
        else:
            d[f[i]] = p[i]
    
    print(min(d.values()))
    
    
    
                
    
    
    