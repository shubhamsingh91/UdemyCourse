#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <iostream>

class Point2D {

    private:
        uint16_t m_x,m_y;

    public:
        Point2D():m_x{0},m_y{0}{};
        Point2D(uint16_t x, uint16_t y):m_x{x},m_y{y}{};

        friend std::ostream & operator<<(std::ostream &out, const Point2D& p) {
            out << "(" << p.m_x << "," << p.m_y << ")";
            return out;
        }

        void setpoint(uint16_t x, uint16_t y) {
            m_x = x; m_y = y;
        }
        ~Point2D(){};

};










#endif