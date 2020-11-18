#include "RegularLine.h"

#include <vector>
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iostream>

bool RegularLine::are_x_coordinates_equal(const std::vector<int> &points)
{
    if (points.size() == 0)
        throw std::runtime_error("No points");
    if (points.size() % 2 == 1)
        throw std::runtime_error("Odd quantity input value");
    if (points.size() == 2)
        throw std::runtime_error("Only one point was received");
    bool are_x_coordinates_equal = true;
    double first_point = points[0];

    for(int i = 2; i < points.size(); i += 2)
    {
        double difference = abs(points[i] - first_point);
        if (difference > std::numeric_limits<double>::epsilon())
        {
            are_x_coordinates_equal = false;
            break;
        }
    }
    return are_x_coordinates_equal;
}

void RegularLine::calculate_sum(const std::vector<int> &points)
{
    if (points.size() == 0)
        throw std::runtime_error("No points");
    if (points.size() % 2 == 1)
        throw std::runtime_error("Odd quantity input value");
    if (points.size() == 2)
        throw std::runtime_error("Only one point was received");
    sum_x = 0;
    sum_y = 0;
    sum_x_square = 0;
    sum_x_multiply_y = 0;
    quantity_points = points.size() / 2;
    for(int i = 0; i < points.size(); i+= 2)
    {
        double x_i = points[i];
        double y_i = points[i+1];
        sum_x += x_i;
        sum_x_square += x_i * x_i;
        sum_y += y_i;
        sum_x_multiply_y += x_i * y_i;
    }
}
void RegularLine::calculate_abc(const std::vector<int> &points, bool are_x_coordinates_equal)
{
    if (are_x_coordinates_equal == true)
    {
        a = 0;
        b = 1;
        c = - points[0];
    }
    else
    {
        a = 1;
        b = (sum_x * sum_y - quantity_points * sum_x_multiply_y) /
            (quantity_points * sum_x_square - sum_x * sum_x);
        c = (-b * sum_x - sum_y) / quantity_points;
    }
}

RegularLine::RegularLine(const std::vector<int> &points)
{
    calculate_sum(points);
    calculate_abc(points, are_x_coordinates_equal(points));
}

RegularLine::RegularLine(const std::vector<int> &points,const RegularLine &regline)
{
    calculate_sum(points);
    sum_x += regline.sum_x;
    sum_y += regline.sum_y;
    sum_x_square += regline.sum_x_square;
    sum_x_multiply_y += regline.sum_x_multiply_y;
    quantity_points += regline.quantity_points;
    if (abs(regline.a) < std::numeric_limits<double>::epsilon())
    {
        std::vector<int> points_add = points;
        points_add.push_back(-regline.c);        // adding a point to check belong points and regline points one line
        points_add.push_back(1);                // adding 1 for even number points
        calculate_abc(points, are_x_coordinates_equal(points_add));
    }
    else
        calculate_abc(points, false);
}

Line RegularLine::getLine()
{
    Line output;
    output.a = a;
    output.b = b;
    output.c = c;
    return output;
}
