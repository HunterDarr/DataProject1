#include <iostream>
using namespace std;


class Point {

protected:
    double x; //x coordinate value
    double y; //y coordinate value
public:
    Point (); //default constructor; x = 0.0 and y = 0.0
    Point (double xvalue, double yvalue); //no-default constructor
    void setLocation (double xvalue, double yvalue); // set x = xvalue and
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

void Point::setLocation(double xvalue, double yvalue) { //Originally returned int. I changed it to return nothing(void)
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
    static double squareroot(double number);
    static double round(double var);
};

double Math::squareroot(double number) {
    double eps = 1e-6;
    double k = number;
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
    double x1;
    double x2;
    double y1;
    double y2;
public:
    LineSegment (); //default constructor
    LineSegment (Point one, Point two);
    double length(); //return the length of the line segment
    Point midpoint (); //return the midpoint of the line segment
    double xIntercept (); //return the x-intercept of the line segment
    double yIntercept (); //return the y-intercept of the line segment
    double slope (); //return the slope of the line segment
    bool itIntersects (LineSegment L); //returns true if L intersects
//    //with this line segment
    Point intersectionPoint (LineSegment L);
    bool isParallel (LineSegment L); //check if slopes are same
    void displayEquation (); // you will print in the format
    Point getP1 ();
    Point getP2 ();
//    // y = m * x + c where m is the slope
//    // and c is the y-intercept
//    //other methods that are necessary
};

LineSegment::LineSegment() {
    //Shouldn't be used.
}

LineSegment::LineSegment(Point one, Point two) {
    P1 = one;
    P2 = two;
    x1 = P1.getXValue();
    x2 = P2.getXValue();
    y1 = P1.getYValue();
    y2 = P2.getYValue();
}

double LineSegment::length() {
    double length;
//    double x1 = P1.getXValue();
//    double x2 = P2.getXValue();
//    double y1 = P1.getYValue();
//    double y2 = P2.getYValue();
    length = Math::squareroot(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2))); //FIX
    return Math::round(length);
}

Point LineSegment::midpoint() {
//    double x1 = P1.getXValue();
//    double x2 = P2.getXValue();
//    double y1 = P1.getYValue();
//    double y2 = P2.getYValue();
    double xValue = Math::round((x1 + x2)/2);
    double yValue = Math::round((y1 + y2)/2);
    Point midPoint(xValue, yValue);
    return midPoint;
}

double LineSegment::xIntercept() {  //Finish
//    double x1 = P1.getXValue();
//    double x2 = P2.getXValue();
//    double y1 = P1.getYValue();
//    double y2 = P2.getYValue();

    double xIntercept;

    if (y1 + y2 <= y1)   { //Probably wrong
        xIntercept = y1 - (slope()*(x1));
    }
    else if ( y2 + y1 <= y2)   {
        xIntercept = x1 - (slope()*(y1));
    }
    else   {
        //No x intercept
    }

    return Math::round(xIntercept);

}

double LineSegment::yIntercept() {  //Finish
//    double x1 = P1.getXValue();
//    double x2 = P2.getXValue();
//    double y1 = P1.getYValue();
//    double y2 = P2.getYValue();
    double yIntercept;
    yIntercept = y1 - slope()*x1;
    return Math::round(yIntercept);
}

double LineSegment::slope() {
//    double x1 = P1.getXValue();
//    double x2 = P2.getXValue();
//    double y1 = P1.getYValue();
//    double y2 = P2.getYValue();
    double slope = Math::round((y2 - y1)/(x2-x1));
    return slope;
}

void LineSegment::displayEquation() {
    cout << "y=" << slope() << "*x+" << yIntercept() << endl;
}

bool LineSegment::isParallel(LineSegment L) {
    double slopeOne = slope();
    double slopeTwo = L.slope();
    if ( slopeOne == slopeTwo )   {
        return true;
    }
    else   {
        return false;
    }
}

Point LineSegment::intersectionPoint(LineSegment L) {
    double x = Math::round((L.yIntercept() - yIntercept())/(slope() - L.slope()));
    double y = Math::round(((yIntercept()*L.slope())-(L.yIntercept()*slope()))/(L.slope() - slope()));
    Point intersection ( x, y );
    return intersection;
}

bool LineSegment::itIntersects(LineSegment L) {
    bool doesIntersect = !isParallel(L);
    return doesIntersect;
}

Point LineSegment::getP1() {
    return P1;
}

Point LineSegment::getP2() {
    return P2;
}


class Intervals {
protected:
    LineSegment* segments;  //FIX THIS
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

Intervals::Intervals (int size) {
    segments = new LineSegment [size];
    count = 0; //currently there is none
    maxSize = size;
}

void Intervals::addLineSegment(LineSegment L) {
    segments[count] = L;
    count = count + 1;
}

void Intervals::display() {
    int segmentCounter = 1;
    int testCounter = 0;
    for ( int i = 0; i < count; i++ )   {
        cout << "Line segment " << segmentCounter << ":" << endl;

        cout << "(" << segments[i].getP1().getXValue() << ", " << segments[i].getP1().getYValue() << "),(" <<
        segments[i].getP2().getXValue() << ", " << segments[i].getP2().getYValue() << ")" << endl;

        cout << "Slope:" << segments[i].slope() << endl;

        cout << "Midpoint:";
        segments[i].midpoint().display();

        cout << "X Intercept:" << segments[i].xIntercept() << endl;
        cout << "Y Intercept:" << segments[i].yIntercept() << endl;

        cout << "Length:" << segments[i].length() << endl;

        segments[i].displayEquation();
        segmentCounter = segmentCounter + 1;
        testCounter = testCounter + 1;
    }
}




int main() {

    int test = 25;
    int *test2 = &test;
    int test3 = *test2;
    double number = 1e-6;
    cout << test2 << ": " << number << endl;
    Point pointOne (0, 0);
    Point pointTwo(5.23, 5.23);
    LineSegment line (pointOne, pointTwo);
    Point a (0,5.23);
    Point b (5.23,0);
    LineSegment lines (a, b);
    double answer = lines.length();
    cout << "Testing the length function:" << endl;
    cout << answer << endl;

    double square = Math::squareroot(6745);
    cout << "Testing the squareroot function:" << endl;
    cout << square << endl;

    cout << "Testing the midpoint:" << endl;
    lines.midpoint().display();

    cout << "Testing the slope:" << endl;
    cout << lines.slope() << endl;

    cout << "Testing the xIntercept:" << endl;
    cout << lines.xIntercept() << endl;

    cout << "Testing the yIntercept:" << endl;
    cout << lines.yIntercept() << endl;

    cout << "Testing Display Equation:" << endl;
    lines.displayEquation();

    cout << "Testing parallel boolean:" << endl;
    if (!lines.itIntersects(line))   {
        cout << "The lines are parallel" << endl;
        cout << "Lines slope: " << lines.slope() << " Line slope: " << line.slope() << endl;
    }
    else   {
        cout << "The lines are not parallel" << endl;
        cout << "Lines slope: " << lines.slope() << " Line slope: " << line.slope() << endl;
        cout << "Testing intersection point:" << endl;
        lines.intersectionPoint(line).display();
    }
    cout << "Testing Intervals and Interval display:" << endl;
    Intervals testing (3);

    Point point1 (0, 0);
    Point point2(5.23, 5.23);
    LineSegment line1 (pointOne, pointTwo);
    Point point3 (0, 5.23);
    Point point4(5.23, 0);
    LineSegment line2 (pointOne, pointTwo);
    Point point5 (0, 6.52);
    Point point6(6.52, 0);
    LineSegment line3 (pointOne, pointTwo);

    testing.addLineSegment(line1);
    testing.addLineSegment(line2);
    testing.addLineSegment(line3);
    testing.display();




    return 0;
}

