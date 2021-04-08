# https://www.codechef.com/APRIL20B/problems/COVIDLQ/

t = int(input())
for z in range(t):
    flag = 0
    n = int(input())
    a = list(map(int, input().split()))
    #print(a)
    if(len(a) < 6):
        #print(a, sum(a))
        if(sum(a) > 1):
            flag = 1
    else:
        for i in range(len(a)-5):
            #print(a[i:i+6], sum(a[i:i+6]))
            if(sum(a[i:i+6]) > 1):
                flag = 1
    if(flag):
        print("NO")
    else:
        print("YES")
