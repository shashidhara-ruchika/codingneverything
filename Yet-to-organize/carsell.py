# https://www.codechef.com/APRIL20B/problems/CARSELL

t = int(input())
for z in range(t):
    profit = 0
    n = int(input())
    p = list(map(int, input().split()))
    p = sorted(p, reverse=True)
    s = [p[i] - i if(p[i] - i > 0) else 0 for i in range(n)]
    print(sum(s)%1000000007)
    