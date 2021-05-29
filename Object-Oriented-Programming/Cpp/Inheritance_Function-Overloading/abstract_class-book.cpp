/*
https://www.hackerrank.com/challenges/30-abstract-classes/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

// Write your MyBook class here
class MyBook : public Book {
    public:
    int price;
    
    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    MyBook(string t, string a, int price) : Book (t, a) {
        this -> price = price;
    }
    
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here
    void display() {
        cout << "Title: " << this -> title << endl <<
                "Author: " << this -> author << endl <<
                "Price: " << this -> price << endl;                
    }
    
// End class
};

/*
Sample Input

The Alchemist
Paulo Coelho
248

Sample Output

Title: The Alchemist
Author: Paulo Coelho
Price: 248
*/
int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
