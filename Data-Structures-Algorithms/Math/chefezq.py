# https://www.codechef.com/OCT20B/problems/CHEFEZQ

t = int(input())
for _ in range(t):
    n, k = input().split()
    n = int(n)
    k = int(k)
    l = [int(i) for i in input().split()]
    checkans = False
    for i in range(n):
        if l[i] < k:
            print(i + 1)
            checkans = True
            break
        try:
            l[i+1] += l[i] - k;
        except:
            continue
    if not checkans:    
        print(l[n - 1]//k + n)