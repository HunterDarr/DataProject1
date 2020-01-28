#include <iostream>
using namespace std;


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
    cout<< "(" << x << ", " << y << ")" << endl;
}


class Math {
public:
    double squareroot();
    double round(double var);
};

double Math::squareroot() {
    double eps = 1e-6;
    double k;
    double l = 0.0, r, mid;

    if (k>=1) {
        r = k;
    }
    if (k<1)  {
        r = 1;
    }

    while (l-k/l > eps || l-k/l < -eps)
    {
        mid = l + (r - l) /2 ;
        if (mid<k/mid)
        {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}

double Math::round(double var) {
    double value = (int)(var * 100.0);
    return (double)value / 100.0;
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

LineSegment::LineSegment() {
    //Shouldn't be used.
}

LineSegment::LineSegment(Point one, Point two) {
    P1 = one;
    P2 = two;
}

double LineSegment::length() {
    double length;
    double x1 = P1.getXValue();
    double x2 = P2.getXValue();
    double y1 = P1.getYValue();
    double y2 = P2.getYValue();
    length =
}
//
//class Intervals {
//protected:
//    LineSegment* segments;
//    int count;
//    int maxSize;
//public:
//    Intervals (); //segments = NULL; count = 0; maxSize = 0;
//    Intervals (int size); //non-default constructor
//    void addLineSegment (LineSegment L);
//    void display();
///* display all line segment stored in
// the y=mx+c format; see display for LineSegment and print points, length,
// midpoint, x-intercept, y-intercept, for example:
//Line Segment: 1
//P1 = (3.0, 9.0); P2 = (8.0, 16.0)
//slope = 1.4
//equation = y = 1.4*x + 4.8
//length = 8.60
//mid point = (10.5, 12.5)
//x-intercept = ...
//y-intercept = ...
//Line Segment: 2
//P1 = (...); P2 = (...)
//slope = ...
//equation = y = ...
//length = ...
//mid point = ...
//x-intercept = ...
//y-intercept = ...
//...
//*/
//};
////some extra help below: in case you need it
//Intervals::Intervals () {
//    segments = NULL;
//    count = 0;
//    maxSize = 0;
//}
//Intervals:: Intervals (int size) {
//    segments = new LineSegment [size];
//    count = 0; //currently there is none
//    maxSize = size;
//}

int main() {

    int test = 25;
    int *test2 = &test;
    int test3 = *test2;
    cout << test2 << ": " << test3 << endl;
    Point* test4 = new Point(10.0, 10.0);
    test4->display();


    return 0;
}

