# https://www.hackerrank.com/challenges/standardize-mobile-number-using-decorators/problem

def wrapper(f):
    def fun(l):
        # complete the function
        # f(["+91 " + str(l[i][-10:-5]) + " " + str(l[i][-5:]) for i in range(len(l))])
        f(['+91 {} {}'.format(n[-10:-5], n[-5:]) for n in l])        
    return fun

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

"""
Sample Input

3
07895462130
919875641230
9195969878

Sample Output

+91 78954 62130
+91 91959 69878
+91 98756 41230
"""

if __name__ == '__main__':
    l = [input() for _ in range(int(input()))]
    sort_phone(l) 



