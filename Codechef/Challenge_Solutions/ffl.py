# https://www.codechef.com/LTIME83B/problems/FFL

t = int(input())
for z in range(t):
    n, s = list(map(int, input().split()))
    val = list(map(int, input().split()))
    df = list(map(int, input().split()))
    defender_min = 999999999
    forward_min = 999999999
    for i in range(n):
        if(df[i]):
            if(val[i]) < forward_min:
                forward_min = val[i]
        else:
            if(val[i]) < defender_min:
                defender_min = val[i]
    if(forward_min + defender_min + s <= 100):
        print("yes")
    else:
        print("no")