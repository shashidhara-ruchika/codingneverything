# https://www.codechef.com/LTIME85B/problems/CHFMOT18

t = int(input())
for _ in range(t):
    s, n = list(map(int, input().split()))
    val = s
    new = n
    count = 0
    while(val != 0):
        if(val >= new):
            count += int(val/new)
            val = val % new
        else:
            if(val==1):
                count += 1
                val = 0
            elif(val%2):
                count += 1 
                val = 1
            else:
                count += 1 
                val = 0
    print(count)                
                
                
                
        
    