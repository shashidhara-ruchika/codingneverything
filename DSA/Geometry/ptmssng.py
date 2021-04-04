
# https://www.codechef.com/JULY20B/problems/PTMSSNG


t = int(input())
for t_ in range(t):
    n = int(input())
    dx = dict()
    dy = dict()
    for _ in range(4*n - 1):
        n1, n2 = input().split()
        n1 = int(n1)
        n2 = int(n2)
        
        if(n1 not in dx):
            #dx[n1] = [1, 1]
            dx[n1] = 1
            
        else:
            """dx[n1][0] += 1
            if(dx[n1][1] == 0):
                dx[n1][1] = 1
            else:
                dx[n1][1] = 0"""
            if(dx[n1] == 1):
                dx[n1] = 0
            else:
                dx[n1] = 1
        if(n2 not in dy):
            #dy[n2] = [1, 1]
            dy[n2] = 1
        else:
            """dy[n2][0] += 1
            if(dy[n2][1] == 0):
                dy[n2][1] = 1 
            else:
                dy[n2][1] = 0 """
            if(dy[n2] == 1):
                dy[n2] = 0
            else:
                dy[n2] = 1
    
    for i in dx:
        #if(dx[i][1] == 1):
        if(dx[i]==1):
            x_coord = i
            break
            
    for i in dy:
        #if(dy[i][1] == 1):
        if(dy[i]==1):
            y_coord = i 
            break
            
            
    
    #print(dx, dy)
    print(x_coord, y_coord)
          
    

