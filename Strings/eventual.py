# https://www.codechef.com/COOK120B/problems/EVENTUAL

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    d = dict()
    flag = 1
    if(len(s) % 2):
        flag = 0
    else:
        for i in s:
            if i in d:
                if(d[i] == 0):
                    d[i] = 1 
                else:
                    d[i] = 0
            else:
                d[i] = 1
        #print(d)  
        for i in d.values():
            if i == 1:
                flag = 0
                break
    if(flag == 0):
        print("NO")
    else:
        print("YES")
    #print()        
    

