# https://www.hackerrank.com/challenges/decorators-2-name-directory/problem

import operator

def person_lister(f):
    def inner(people):
        # complete the function
        return map(f, sorted(people, key=lambda x: int(x[2])))
    return inner

@person_lister
def name_format(person):
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]

"""
Sample Input

3
Mike Thomson 20 M
Robert Bustle 32 M
Andria Bustle 30 F

Sample Output

Mr. Mike Thomson
Ms. Andria Bustle
Mr. Robert Bustle
"""

if __name__ == '__main__':
    people = [input().split() for i in range(int(input()))]
    print(*name_format(people), sep='\n')