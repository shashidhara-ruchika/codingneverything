# https://www.codechef.com/COOK117B/problems/LIFTME
 
t = int(input())
for z in range(t):
    n,q = list(map(int, input().split()))
    l = [0]
    for y in range(q):
        l.extend(list(map(int, input().split())))
    #print(l)
    sumarr = [abs(l[i] - l[i+1]) for i in range(len(l) - 1)]
    print(sum(sumarr))