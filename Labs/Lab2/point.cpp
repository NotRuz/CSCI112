#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint) : x(X), y(Y), nearestPoint(closestPoint)
{
    // Already declared
}
//Destructor
points::Point::~Point()
{
    // Doesn't need a destructor
}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    // If the nearest point is just itself...
    if (arrSize == 0)
    {
        return nullptr;
    }
    // Making the minimum distance and the nearest point basic
    Point* nearest = nullptr;
    double minDistance = -1.0;
    // looping through the list
    for (unsigned long i = 0; i < arrSize; i++)
    {
        // comparing itself to itself
        if (pointList[i] == nullptr || pointList[i] == this)
        {
            continue;
        }
        // finding the distance between the points
        double distance = distPoints(*pointList[i]);
        // if it's smaller than the minimum distance 
        if (nearest == nullptr || distance < minDistance )
        {
            // then it assigns the values to the nearest point
            minDistance = distance;
            nearest = pointList[i];
        }
    }

    return nearest;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    double dx = point.getX() - x;
    double dy = point.getY() - y;
    return sqrt(dx * dx + dy * dy);
}