/*
https://www.hackerrank.com/challenges/rectangle-area/problem
*/

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
 
class Rectangle {
    protected:
    int width;
    int height;
    
    public:
    virtual void display();
};

class RectangleArea : public Rectangle {
    private:
    int calcArea();
    
    public:
    void display();
    void read_input();    
};

void Rectangle :: display() {
    cout << this -> width << " " << this -> height << endl;
}

int RectangleArea :: calcArea() {
    return this -> width * this -> height;
}

void RectangleArea :: display() {
    int area = this -> calcArea();
    cout << area << endl;   
}

void RectangleArea :: read_input() {
    int w, h;
    cin >> w >> h;
    this -> width = w;
    this -> height = h;
}

/*
Sample Input

10 5

Sample Output

10 5
50
*/

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}