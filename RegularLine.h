#ifndef REGULARLINE_H
#define REGULARLINE_H

#include <vector>

struct Line
{
    double a;
    double b;
    double c;
};

class RegularLine   //line ax + by + c = 0
{
public:
    Line getLine();
    RegularLine(const std::vector<int> &points);
    RegularLine(const std::vector<int> &points, const RegularLine &regline);
private:
    bool are_x_coordinates_equal(const std::vector<int> &points);
    void calculate_sum(const std::vector<int> &points);  // calculate: sum_x, sum_y, sum_x_square, sum_x_multiply_y, quantity_points
    void calculate_abc(const std::vector<int> &points, bool are_x_coordinates_equal);  // calculate coefficients (a, b, c)  by  (sum_x, sum_y, sum_x_square, sum_x_multiply_y, quantity_points)
    double a;
    double b;
    double c;
    double sum_x;
    double sum_y;
    double sum_x_square;
    double sum_x_multiply_y;
    int quantity_points;
};

#endif
