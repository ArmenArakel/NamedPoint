#ifndef NAMED_POINT_NAMEDPOINT_H
#define NAMED_POINT_NAMEDPOINT_H

/**
 * @class NamedPoint class
 * 
 * @brief A class with 2D coordinates & name representing things(cities, battlefields, etc) in flat world 
 */
class NamedPoint {

private:
    float x;
    float y;
    char* name;

    void copyName(const char* name);
public:
    /**
     * Constructor
     * @param x - x coordinate
     * @param y - y coordinate
     * @param name - name of point
     */
    NamedPoint(const float& x, const float& y, const char* name);
    /**
     * Copy Constructor
     */
    NamedPoint(const NamedPoint& namedPoint);
    /**
     * Destructor
     */
    ~NamedPoint();

    /**
     * Setting the specified X coordinate
     */
    void setX(const float& x);
    /**
     * Getting the X coordinate
     */
    float getX() const;
    /**
     * Setting the specified Y coordinate
     */
    void setY(const float& y);
    /**
     * Getting the Y coordinate
     */
    float getY() const;
    /**
     * Setting the specified name
     */
    void setName(const char* name);
    /**
     * Getting the name
     */
    const char* getName() const;
    /**
     * Assignment operator
     */
    NamedPoint& operator=(const NamedPoint& namedPoint);
    /**
     * Checks if two NamedPoints are equal
     * @param namedPoint
     * @return true if two NamedPoints are equal, false otherwise
     */
    bool operator==(const NamedPoint& namedPoint) const;
    /**
     * Moves NamedPoint to the (x, y) coordinate
     * @param x
     * @param y
     */
    void moveTo(const float& x, const float& y);
    /**
     * Calculates direct distance between two NamedPoints
     * @param namedPoint
     * @return direct distance between two NamedPoints
     */
    double distance(const NamedPoint& namedPoint) const;

};


#endif //NAMED_POINT_NAMEDPOINT_H
