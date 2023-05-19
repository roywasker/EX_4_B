#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

namespace ariel {
    class Point{
    public:
        Point(double x_c= 0 , double y_c = 0);
        double distance(Point point) const;
        std::string print();
        static Point moveTowards(Point src , Point des, double distance);
        void setx(double x_c);
        void sety(double y_c);
        double getx() const;
        double gety() const;

    private:
        double x_c;
        double y_c;
    };
}
#endif //POINT_HPP
