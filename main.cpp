/**
 * CS-2413
 * project1.cpp
 * Purpose: Create line segments given x and y values for points and
 * then calculate various mathematical functions regarding the line segments.
 *
 * @author Hunter Darr
 * @Version 1.0 2/3/2020
 */


#include <iostream>
using namespace std;


/**
 * Description:
 * The Point class is used to store the values of x and y in a point that can be
 * accessed by different functions/methods.
 * x and y are provided by input in the main method.
 *
 *
 * Constructors:
 * - Point(); Default constructor.
 * - Point(double xvalue, double yvalue); Non-default constructor.
 *   Sets the protected class variables, x and y, to the xvalue and yvalue parameters.
 *
 * Methods:
 * - setLocation(double xvalue, double yvalue); Sets the x and y class variables.
 * - getXValue(); A getter function/method for the x class variable.
 * - getYValue(); A getter function/method for the y class variable.
 * - display(); Uses cout to print the formatted point to the console.
 */
class Point {
protected:
    double x; //x coordinate value
    double y; //y coordinate value
public:
    Point (); //default constructor; x = 0.0 and y = 0.0
    Point (double xvalue, double yvalue); //no-default constructor
    void setLocation (double xvalue, double yvalue); // set x = xvalue and y = yvalue
    double getXValue(); //return x
    double getYValue(); //return y
    void display(); // Print (0.0, 0.0)
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
    cout<< "(" << x << ", " << y << ")" << endl; // Formatted in this manner (x, y)
}


/**
 * Description:
 * The Math class is used to simplify the math calculations throughout the project.
 * To find the square root of a number write "Math::square root(numberToTakeSquareRootOf)".
 * To round a number write "Math::round(numberToRound)".
 *
 *
 * Constructors:
 * - N/A
 *
 * Methods:
 * - squareroot(double number); Calculates the square root of a double.
 * - round(double var); Rounds a double.
 */
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
    double result = (double)value / 100.0;
    return result;
}


/**
 * Description:
 * The LineSegment class is as its name implies. The LineSegment class represents a line segment by containing
 * two Point values. These point values are stored as class variables for the various functions/methods to use.
 * x1 represents the x value in P1.
 * x2 represents the x value in P2.
 * y1 represents the y value in P1.
 * y2 represents the y value in P2.
 *
 *
 * Constructors:
 * - LineSegment (); Default constructor. Should not be used.
 * - LineSegment (Point one, Point two); Sets the class variables P1 and P2 to the given points.
 *
 * Methods:
 * - length(); Calculates the length of the line segment
 * - midpoint (); Calculates the midpoint of the line segment.
 * - xIntercept (); Calculates the xIntercept of the line segment.
 * - yIntercept (); Calculates the yintercept of the line segment.
 * - slope (); Calculates the slope of the line segment.
 * - itIntersects (LineSegment L); Determines (true or false) whether or not the line segment and
 *   a given line segment intersect.
 * - intersectionPoint (LineSegment L); Calculates the intersection point of the line segment
 *   and a given line segment.
 * - isParallel (LineSegment L); Determines (true or false) whether or not the line segment and
 *   a given line segment are parallel.
 * - displayEquation (); Prints the equation of the line segment in the format of y = mx + b.
 * - getP1 (); A getter function/methed for class variable P1. Returns the first point
 *   of the line segment.
 * - getP2 (); A getter function/method for class variable P2. Returns the second point
 *   of the line segment.
 */
class LineSegment {
protected:
    Point P1;
    Point P2;
    double x1; // x in P1
    double x2; // x in P2
    double y1; // y in P1
    double y2; // y in P2
public:
    LineSegment (); //default constructor
    LineSegment (Point one, Point two);
    double length(); //return the length of the line segment
    Point midpoint (); //return the midpoint of the line segment
    double xIntercept (); //return the x-intercept of the line segment
    double yIntercept (); //return the y-intercept of the line segment
    double slope (); //return the slope of the line segment
    bool itIntersects (LineSegment L); //returns true if L intersects with the line segment
    Point intersectionPoint (LineSegment L); // returns the point in which two line segments intersect
    bool isParallel (LineSegment L); //check if slopes are same
    void displayEquation (); // Prints in the format y=mx+b
    Point getP1 ();
    Point getP2 ();
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
    length = Math::squareroot(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
    return length;
}

Point LineSegment::midpoint() {
    double xValue = Math::round((x1 + x2)/2);
    double yValue = Math::round((y1 + y2)/2);
    Point midPoint(xValue, yValue);
    return midPoint;
}

double LineSegment::xIntercept() {
    double xIntercept;
    xIntercept = x1 - (((x2-x1)/(y2-y1))*(y1));
    return xIntercept;

}

double LineSegment::yIntercept() {
    double yIntercept;
    yIntercept = y1 - (((y2 - y1)/(x2 - x1))*x1);
    return yIntercept;
}

double LineSegment::slope() {
    double slope =(y2 - y1)/(x2-x1);
    return slope;
}

void LineSegment::displayEquation() {
    cout << "y=" << Math::round(slope()) << "*x+" << Math::round(yIntercept()) << endl;
    //Formatted in this manner y=mx+b
}

bool LineSegment::isParallel(LineSegment L) {
    double slopeOne = Math::round(slope());
    double slopeTwo = Math::round(L.slope());
    if ( slopeOne == slopeTwo )   { // If the slopes of the two lines are the same the they are parallel
        return true;
    }
    else   {
        return false;
    }
}

Point LineSegment::intersectionPoint(LineSegment L) {
    double x = Math::round((L.yIntercept() - yIntercept())/(slope() - L.slope()));
    double y = Math::round(((yIntercept()*L.slope())-(L.yIntercept()*slope()))/(L.slope() - slope()));
    Point intersection ( x, y ); //Puts the x and y values in to a point to be returned
    return intersection;
}

bool LineSegment::itIntersects(LineSegment L) {
    bool doesIntersect;

    double d1u1 = getP2().getXValue() - getP1().getXValue();
    double d1v1 = getP2().getYValue() - getP1().getYValue();
    double d1u2 = L.getP1().getXValue() - getP1().getXValue();
    double d1v2 = L.getP1().getYValue() - getP1().getYValue();

    double d1 = (d1u1 * d1v2) - (d1u2 * d1v1); // d1 = P1->P2 x P1->Q1

    double d2u1 = getP2().getXValue() - getP1().getXValue();
    double d2v1 = getP2().getYValue() - getP1().getYValue();
    double d2u2 = L.getP2().getXValue() - getP1().getXValue();
    double d2v2 = L.getP2().getYValue() - getP1().getYValue();

    double d2 = (d2u1 * d2v2) - (d2u2 * d2v1); //d2 = P1->P2 x P1->Q2

    double d3u1 = L.getP2().getXValue() - L.getP1().getXValue();
    double d3v1 = L.getP2().getYValue() - L.getP1().getYValue();
    double d3u2 = getP1().getXValue() - L.getP1().getXValue();
    double d3v2 = getP1().getYValue() - L.getP1().getYValue();

    double d3 = (d3u1 * d3v2) - (d3u2 * d3v1); //d3 = Q1->Q2 x Q1->P1

    double d4u1 = L.getP2().getXValue() - L.getP1().getXValue();
    double d4v1 = L.getP2().getYValue() - L.getP1().getYValue();
    double d4u2 = getP2().getXValue() - getP1().getXValue();
    double d4v2 = getP2().getYValue() - getP1().getYValue();

    double d4 = (d4u1 * d4v2) - (d4u2 * d4v1); //d4 = Q1->Q2 x P1->P2

    if ( ((d1 * d2 ) <= 0 ) && ((d3 * d4) <= 0))   { //Intersects if d1d2 <= 0, d3d4 <= 0
        doesIntersect = true;
    }
    else   {
        doesIntersect = false;
    }
    return doesIntersect;
}

Point LineSegment::getP1() {
    return P1;
}

Point LineSegment::getP2() {
    return P2;
}


/**
 * Description:
 * The Intervals class holds an array of line segments in order for the line segments
 * to be organized, displayed, added to, and rotated through for calculations in main().
 *
 *
 * Constructors:
 * - Intervals (); Default constructor.
 * - Intervals (int size); Initializes the line segment array, sets count to 0,
 *   and maxSize to the given size.
 *
 * Methods:
 * - addLineSegment (LineSegment L); Adds a line segment to the array and increases count by 1.
 * - display(); Displays the name, points, slope, midpoint, intercepts, length,
 *   and equation of a line segment.
 * - getLine (int arrayIndex); A getter function/method for returning a line segment at the
 *   given index of the array.
 */
class Intervals {
protected:
    LineSegment* segments;
    int count;
    int maxSize;
public:
    Intervals (); //Defualt constructor
    Intervals (int size); //non-default constructor
    void addLineSegment (LineSegment L);
    void display();
    LineSegment getLine (int arrayIndex);
};


Intervals::Intervals () {
    segments = NULL;
    count = 0;
    maxSize = 0;
}

Intervals::Intervals (int size) {
    segments = new LineSegment [size]; //Assigns an array to the pointer segments.
    count = 0;
    maxSize = size;
}

void Intervals::addLineSegment(LineSegment L) {
    segments[count] = L; //Adds a new line segment in the array at index count.
    count = count + 1; //Increases count by 1.
}

void Intervals::display() {
    int segmentCounter = 1; // Keeps count of what line segment is being displayed
    for ( int i = 0; i < count; i++ )   {
        cout << "Line Segment " << segmentCounter << ":" << endl; // Line Segment #:
        cout << "(" << Math::round(segments[i].getP1().getXValue()) << ", " << Math::round(segments[i].getP1().getYValue()) << "),(" <<
        Math::round(segments[i].getP2().getXValue()) << ", " << Math::round(segments[i].getP2().getYValue()) << ")" << endl;
        // (x, y),(x, y)

        cout << "Slope:" << Math::round(segments[i].slope()) << endl; // Slope:m

        cout << "Midpoint:";
        segments[i].midpoint().display(); //Midpoint:(x, y)

        cout << "X Intercept:" << Math::round(segments[i].xIntercept()) << endl; // X Intercept:x
        cout << "Y Intercept:" << Math::round(segments[i].yIntercept()) << endl; // Y Intercept:y

        cout << "Length:" << Math::round(segments[i].length()) << endl; // Length:#

        segments[i].displayEquation(); // y=mx+b
        segmentCounter = segmentCounter + 1;
    }
}

LineSegment Intervals::getLine(int arrayIndex) {
    return segments[arrayIndex];
}

/**
 * Description:
 * main() is the main method of this program. It handles all of the inputs and structures the outputs.
 * main() also contains the nested for loop responsible for comparing line segments.
 * main() calls upon the functions/methods in different classes and brings everything together.
 * @return
 */
int main() {
    double linePoint1; // x value of a point
    double linePoint2; // y value of a point
    double linePoint3; // x value of a point
    double linePoint4; // y value of a point
    int numberOfLines; // Number of line segments to be input

    cin >> numberOfLines; // Inputs the number of line segments to be input

    Intervals interval (numberOfLines); // Constructor for Intervals

    for ( int i = 0; i < numberOfLines; i++ )   {
        cin >> linePoint1 >> linePoint2 >> linePoint3 >> linePoint4; // Inputs the x and y values of a line segment
        Point pointOne (linePoint1, linePoint2);
        Point pointTwo (linePoint3, linePoint4);
        LineSegment line (pointOne, pointTwo);
        interval.addLineSegment(line); // Adds the new line segment to the Interval class's array
    }

    interval.display(); // Displays the information about the line segments

    bool doesIntersect = false;
    int jCounter = 1; /* Keeps track of j so that every time j's for loop is called
 * it starts 1 higher than the previous time */

    for ( int i = 0; i < numberOfLines; i++ )   {
        for ( int j = jCounter; j < numberOfLines; j++ )   { // j's for loop compares line segments to i's line segment
            if (!(i == j))   {
                doesIntersect = interval.getLine(i).itIntersects(interval.getLine(j));
                if (doesIntersect)   {
                    cout << "The line segments compared are segments[" << i << "] and segments[" << j <<
                    "]: Intersection Point :";
                    interval.getLine(i).intersectionPoint(interval.getLine(j)).display();
                }
                else if (!doesIntersect && !interval.getLine(i).isParallel(interval.getLine(j)))   {
                    cout << "The line segments compared are segments[" << i << "] and segments[" << j <<
                         "]: Not Parallel and not Intersecting" << endl;
                }
                else {
                    cout << "The line segments compared are segments[" << i << "] and segments[" << j <<
                         "]: Lines are Parallel" << endl;
                }
            }
        }
        jCounter = jCounter + 1;
    }
    return 0;
}

