# https://www.codechef.com/COOK116B/problems/GIFTSRC

def moveL(l):
    l[0] -= 1
    #print(l)
    return l
def moveR(l):
    l[0] += 1
    #print(l)
    return l
def moveU(l):
    l[1] += 1
    #print(l)
    return l
def moveD(l):
    l[1] -= 1
    #print(l)
    return l

t = int(input())
for z in range(t):
    n = int(input())
    s = input()
    #print(s)
    l = [0,0]
    prev = 'J'
    for i in s:
            if(i == 'L' and prev != 'L' and prev != 'R'):
                l = moveL(l)
            if(i == 'R' and prev != 'L' and prev != 'R'):
                l = moveR(l)
            if(i == 'U' and prev != 'U' and prev != 'D'):
                l = moveU(l)
            if(i == 'D' and prev != 'U' and prev != 'D'):
                l = moveD(l)
            prev = i
    print(l[0], l[1])
            
    