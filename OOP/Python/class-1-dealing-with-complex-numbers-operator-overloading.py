# https://www.hackerrank.com/challenges/class-1-dealing-with-complex-numbers/problem

from math import pow

class Complex(object):
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
    
    def __add__(self, no):
        real_part = self.real + no.real
        imag_part = self.imaginary + no.imaginary
        return Complex(real_part, imag_part)        
    
    def __sub__(self, no):
        real_part = self.real - no.real
        imag_part = self.imaginary - no.imaginary
        return Complex(real_part, imag_part) 
        
    def __mul__(self, no):
        real_part = (self.real * no.real) - (self.imaginary * no.imaginary)
        imag_part = (self.real * no.imaginary) + (self.imaginary * no.real)
        return Complex(real_part, imag_part)

    def __truediv__(self, no):
        try:
            denominator = (no.real * no.real) + (no.imaginary * no.imaginary)
            real_part = ((self.real * no.real) + (self.imaginary * no.imaginary)) / denominator
            imag_part = ((self.imaginary * no.real) - (self.real * no.imaginary)) / denominator
            return Complex(real_part, imag_part)
        except ZeroDivisionError as e:
            print(e)
            return None
        
    def mod(self):
        real_part = pow(((self.real * self.real) + (self.imaginary * self.imaginary)), 0.5)
        return Complex(real_part, 0)

    def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result

"""
Sample Input:

2 1
5 6

Sample Output:

7.00+7.00i
-3.00-5.00i
4.00+17.00i
0.26-0.11i
2.24+0.00i
7.81+0.00i
"""        

if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n')