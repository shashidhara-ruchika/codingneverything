/*
https://www.hackerrank.com/challenges/overload-operators/problem
*/

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex

//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
// Throws an error for - Complex Complex :: operator + (const Complex& n1, const Complex& n2) 
Complex operator + (const Complex& n1, const Complex& n2) {
    
    Complex temp_complex_num_sum;
    temp_complex_num_sum.a = n1.a + n2.a;
    temp_complex_num_sum.b = n1.b + n2.b;
    return temp_complex_num_sum;
}

//<< should print a complex number in the format "a+ib"
// Throws an error for - ostream& Complex :: operator << (ostream& ostream_cout, const Complex& n)
ostream& operator << (ostream& ostream_op, const Complex& n) {
    
    if (n.b > 0)
        ostream_op << n.a << "+i" << n.b;
        
    else if (n.b < 0)
        ostream_op << n.a << "-i" << n.b;
    
    else 
        ostream_op << n.a;
    
    return ostream_op;
}

/*
Sample Input

3+i4
5+i6

Sample Output

8+i10
*/

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
