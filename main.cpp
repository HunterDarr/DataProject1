#include <iostream>
using namespace std; //might be the fix for cout.

int main() {

    return 0;
}

class Point {
protected:
    double x; //x coordinate value
    double y; //y coordinate value
public:
    Point (); //default constructor; x = 0.0 and y = 0.0
    Point (double xvalue, double yvalue); //no-default constructor
    int setLocation (double xvalue, double yvalue); // set x = xvalue and
    // y = yvalue
    double getXValue(); //return x
    double getYValue(); //return y
    void display(); // Print (0.0, 0.0)
    //other methods that are necessary
};

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double xvalue, double yvalue) {
    x = xvalue;
    y = yvalue;
}

int Point::setLocation(double xvalue, double yvalue) {
    x = xvalue;
    y = yvalue;
}

double Point::getXValue() {
    return x;
}

double Point::getYValue() {
    return y;
}

void Point::display() {
    cout<< "(" << x << ", " << y << ")" << endl;  //FIX THIS. IT HAS PROBLEMS. Might be broken still?
}



class LineSegment {
protected:
    Point P1;
    Point P2;
public:
    LineSegment (); //default constructor
    LineSegment (Point one, Point two);
    double length(); //return the length of the line segment
    Point midpoint (); //return the midpoint of the line segment
    Point xIntercept (); //return the x-intercept of the line segment
    Point yIntercept (); //return the y-intercept of the line segment
    double slope (); //return the slope of the line segment
    bool itIntersects (LineSegment L); //returns true if L intersects
    //with this line segment
    Point intersectionPoint (LineSegment L);
    bool isParallel (LineSegment L); //check if slopes are same
    void displayEquation (); // you will print in the format
    // y = m * x + c where m is the slope
    // and c is the y-intercept
    //other methods that are necessary
};

class Intervals {
protected:
    LineSegment* segments;
    int count;
    int maxSize;
public:
    Intervals (); //segments = NULL; count = 0; maxSize = 0;
    Intervals (int size); //non-default constructor
    void addLineSegment (LineSegment L);
    void display();
/* display all line segment stored in
 the y=mx+c format; see display for LineSegment and print points, length,
 midpoint, x-intercept, y-intercept, for example:
Line Segment: 1
P1 = (3.0, 9.0); P2 = (8.0, 16.0)
slope = 1.4
equation = y = 1.4*x + 4.8
length = 8.60
mid point = (10.5, 12.5)
x-intercept = ...
y-intercept = ...
Line Segment: 2
P1 = (...); P2 = (...)
slope = ...
equation = y = ...
length = ...
mid point = ...
x-intercept = ...
y-intercept = ...
...
*/
};
//some extra help below: in case you need it
Intervals::Intervals () {
    segments = NULL;
    count = 0;
    maxSize = 0;
}
Intervals:: Intervals (int size) {
    segments = new LineSegment [size];
    count = 0; //currently there is none
    maxSize = size;
}


