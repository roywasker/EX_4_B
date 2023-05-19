#include "Point.hpp"

using namespace ariel;

/**
 * Constructor for point
 * @param x X coordinate
 * @param y Y coordinate
 */
Point::Point(double x_c, double y_c) : x_c(x_c), y_c(y_c){}

/**
 *  Calculation of distance between 2 points
 * @param p destination points
 * @return the distance
 */
double Point::distance(Point point) const {
    double distance = sqrt(pow(this->x_c-point.getx(),2)+pow(this->y_c-point.gety(),2));
    return distance;
}

/**
 * Print the values of the point
 * @return A string that contains the values
 */
std::string Point::print() {
    std::string print ="("+ to_string(this->getx())+","+ to_string(this->gety())+")";
    return print;
}

/**
 * The function calculates the closest point that can be reached to the target point using the obtained distance
 * @param src source points
 * @param des destination points
 * @param distance the distance that can be move
 * @return the point where you can go
 */
Point Point::moveTowards(Point src, Point des, double distance) {
    if (distance <0){
        throw std::invalid_argument("distance can not be a negative");
    } else if (distance==0){
        return src;
    }
    if(src.distance(des)<=distance){
        return des;
    }else{ //https://stackoverflow.com/questions/1250419/finding-points-on-a-line-with-a-given-distance
        double ratio = distance / src.distance(des);
        double movepointx = (1 - ratio) * src.getx() + ratio * des.getx();
        double movepointy = (1 - ratio) * src.gety() + ratio * des.gety();
        return Point(movepointx,movepointy);
    }
}

/**
 * Setter for x coordinate
 * @param x x coordinate
 */
void Point::setx(double x_c) { this->x_c=x_c;}

/**
 * Setter for x coordinate
 * @param y y coordinate
 */
void Point::sety(double y_c) { this->y_c=y_c;}

/**
 * getter for x coordinate
 * @return x coordinate
 */
double Point::getx() const {return this->x_c;}

/**
 *  getter for y coordinate
 * @return y coordinate
 */
double Point::gety() const {return this->y_c;}