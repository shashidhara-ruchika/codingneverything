# https://www.codechef.com/FEB20B/problems/SNUG_FIT

t = int(input())
for i in range(0,t):
    n = int(input())
    sum = 0
    a = list(map(int,input().split(' ')))
    a.sort()
    b = list(map(int,input().split(' ')))
    b.sort()
    for i in range(0,n):
        sum += min(a[i], b[i])
    print(sum)