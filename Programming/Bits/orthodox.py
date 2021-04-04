# https://www.codechef.com/COOK120B/problems/ORTHODOX

def OR(a, n):
    ans = a[0]
    for i in range(1, n):
        ans = ans | a[i]
    return ans    
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    d = dict()
    flag = 1
    for i in a:
        if i in d:
            d[i] = 0
            flag = 0
            break
        else:
            d[i] = 1
    if(flag == 0):
        print("NO")
    else:  
        for i in range(2, n+1):
            #print(a, OR(a, i))
            orr = OR(a, i)
            if orr in d:
                d[orr] = 0
                flag = 0
                break
            else:
                d[orr] = 1
        #print(d)        
        if(flag == 0):
            print("NO")
        else:
            print("YES")
    