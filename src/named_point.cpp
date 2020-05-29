#include <math.h>
#include <string.h>

#include "named_point.hpp"

NamedPoint::NamedPoint(const float& x, const float& y, const char* name)
{
    this->x = x;
    this->y = y;
    copyName(name);

}

NamedPoint::NamedPoint(const NamedPoint& namedPoint)
{
    this->x = namedPoint.x;
    this->y = namedPoint.y;
    copyName(namedPoint.name);
}

NamedPoint::~NamedPoint()
{
    if(NULL != name) {
        delete [] name;
        name = NULL;
    }
}

void NamedPoint::setX(const float& x)
{
    this->x = x;
}

float NamedPoint::getX() const
{
    return this->x;
}

void NamedPoint::setY(const float& y)
{
    this->y = y;
}

float NamedPoint::getY() const
{
    return this->y;
}

void NamedPoint::copyName(const char* name)
{
    if(NULL != name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    } else {
        this->name = NULL;
    }
}

void NamedPoint::setName(const char* name)
{
    if(NULL != this->name) {
        delete [] this->name;
    }
    copyName(name);
}

const char* NamedPoint::getName() const
{
    return this->name;
}

NamedPoint& NamedPoint::operator=(const NamedPoint& namedPoint)
{
    this->x = namedPoint.x;
    this->y = namedPoint.y;
    setName(namedPoint.name);

    return *this;
}

bool NamedPoint::operator==(const NamedPoint& namedPoint) const
{
    if(this->x == namedPoint.x && this->y == namedPoint.y &&
       NULL != this->name && NULL != namedPoint.name &&
       0 == strcmp(this->name, namedPoint.name)) {
        return true;
    }
    return false;
}

void NamedPoint::moveTo(const float& x, const float& y)
{
    this->x = x;
    this->y = y;
}

double NamedPoint::distance(const NamedPoint& namedPoint) const
{
    return sqrt(pow((this->x - namedPoint.x),2) +
                pow((this->y - namedPoint.y), 2));
}
