# https://www.codechef.com/MAY20B/problems/COVID19

t = int(input())
for z in range(t):
    n = int(input())
    li = list(map(int, input().split()))
    #print("list", li)
    max = -1
    min = 3000
    count = 1
    for i in range(1,n-1):
        if(li[i] - li[i - 1] <= 2):
            count+= 1
        else:
            new_count = 1
            if(count < min):
                min = count
            if(count > max):
                max = count
            count = 1
    #print(li, count, min, max)
    if(li[n-1] - li[n-2] <= 2):
        count += 1
    else:
        if(count < min):
            min = count
        if(count > max):
            max = count
        count = 1
    if(count < min):
        min = count
    if(count > max):
        max = count
    #print(li, count, min, max)
    print(min, max)
        
    