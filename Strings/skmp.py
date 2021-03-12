# https://www.codechef.com/AUG20B/problems/SKMP

t = int(input())
for _ in range(t):
    s = input()
    p = input()
    sl = list(s)
    pl = list(p)
    for i in pl:
        if(i in sl):
            sl.remove(i)
    sl.sort()
    l = 0
    n = sl.count(pl[0])
    for i in range(len(pl)):
        if(ord(pl[0]) > ord(pl[i])):
            l = 1 
            break
        elif(ord(pl[0]) < ord(pl[i])):
            l = 0 
            break
    s0 = ""
    for i in range(n):
        s0 = s0 + pl[0]
    s1 = ""
    s2 = ""
    for i in range(len(sl)):
        if(ord(pl[0]) > ord(sl[i])):
            s1 = s1 + sl[i]
        elif(ord(pl[0]) < ord(sl[i])):
            s2 = s2 + sl[i]
    if(l == 1):
        print(s1 + p + s0 + s2)
    else:
        print(s1 + s0 + p + s2)
    
    