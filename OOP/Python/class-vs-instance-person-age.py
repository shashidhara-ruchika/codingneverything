# https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=false

class Person:    
    def __init__(self,initialAge):
        # Add some more code to run some checks on initialAge
        if (initialAge > 0):
            self.__age = initialAge
        else:
            self.__age = 0
            print("Age is not valid, setting age to 0.")
            
    def amIOld(self):
        # Do some computations in here and print out the correct statement to the console
        if (self.__age < 13):
            print("You are young.")
        elif (self.__age >= 18):
            print("You are old.")
        else:
            print("You are a teenager.")  
        
    def yearPasses(self):
        # Increment the age of the person in here
        self.__age = self.__age + 1
        
"""
Sample Input

4
-1
10
16
18
Sample Output

Age is not valid, setting age to 0.
You are young.
You are young.

You are young.
You are a teenager.

You are a teenager.
You are old.

You are old.
You are old.
"""

t = int(input())
for i in range(0, t):
    age = int(input())         
    p = Person(age)  
    p.amIOld()
    for j in range(0, 3):
        p.yearPasses()       
    p.amIOld()
    print("")