// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <string>
#include <map>
#include <set>


bool isPointOnLine( std::vector<int> &start_point,
                    std::vector<int> &end_point,
                    std::vector<int> &candidate )
{
    bool retval = false;
    float change_in_y = end_point[1] - start_point[1];
    float change_in_x = end_point[0] - start_point[0];
    float m;
    float c;
    
    if( change_in_x == 0 )
    {
        // line is vertical, so only check to see if the X's match.
        if( candidate[0] == start_point[0] )
            retval = true;
    }
    else if( change_in_y == 0 )
    {
        // line is horizontal, so only check to see if the Y's match.
        if( candidate[1] == start_point[1] )
            retval = true;
    }
    else
    {
        m = ( change_in_y  ) / ( change_in_x  );
        c = end_point[1] - ( m * end_point[0] );

        if( (float) candidate[1] == ( ( m * candidate[0] ) + c ) )
            retval = true;
    }
    return retval;
}
                          


int numberOfPointsOnLine( std::vector<int> &start_point,
                          std::vector<int> &end_point,
                          std::vector<std::vector<int> > &point_list )
{
    int intercept_count = 0;
    bool is_on_line;
    for( auto candidate : point_list )
    {
        is_on_line = isPointOnLine( start_point, end_point, candidate );
        if( is_on_line )
        {
            intercept_count++;
        }
    }
    return intercept_count;
}
                          

int maxPoints(std::vector<std::vector<int> >& points)
{
    std::vector<std::vector<int> >::iterator outer_points_iterator;
    std::vector<std::vector<int> >::iterator inner_points_iterator;
    std::vector<int> start_point;
    std::vector<int> end_point;

    int max_intercept_count = 0;
    int current_intercept_count = 0;

    if( points.size() == 1 )
        return 1;
    
    
    for( outer_points_iterator = points.begin();
         outer_points_iterator != points.end();
         outer_points_iterator++)
    {
        inner_points_iterator = outer_points_iterator;
        inner_points_iterator++;
        for( ;
             inner_points_iterator != points.end();
             inner_points_iterator++ )
        {
            start_point = *outer_points_iterator;
            end_point = *inner_points_iterator;
            current_intercept_count = numberOfPointsOnLine( start_point, end_point, points );
            if( current_intercept_count > max_intercept_count )
                max_intercept_count = current_intercept_count;
        }
    }
    return max_intercept_count;
}


void dumpPoints(std::vector<std::vector<int> >& points)
{
    printf("[");
    bool first_time = true;
    for(auto current : points )
    {
        if( ! first_time )
            printf(",");
        
        printf("[%d,%d]", current[0], current[1] );
        first_time = false;
    }
    printf("]\n");
}


int main(int argc, char **argv)
{
    {
        std::vector<std::vector<int> > point_list;
        std::vector<int> points;
        
        points.push_back(1);
        points.push_back(1);
        point_list.push_back( points );
        
        points.clear();
        points.push_back(3);
        points.push_back(2);
        point_list.push_back( points );
        
        points.clear();
        points.push_back(5);
        points.push_back(3);
        point_list.push_back( points );
        
        points.clear();
        points.push_back(4);
        points.push_back(1);
        point_list.push_back( points );
        
        
        points.clear();
        points.push_back(2);
        points.push_back(3);
        point_list.push_back( points );
        
        
        points.clear();
        points.push_back(1);
        points.push_back(4);
        point_list.push_back( points );
        
        
        dumpPoints( point_list );
        maxPoints( point_list );
    }
    {
        std::vector<std::vector<int> > point_list;
        std::vector<int> points;
        
        points.push_back(1);
        points.push_back(1);
        point_list.push_back( points );
        
        points.clear();
        points.push_back(2);
        points.push_back(2);
        point_list.push_back( points );
        
        points.clear();
        points.push_back(3);
        points.push_back(3);
        point_list.push_back( points );
        
        
        dumpPoints( point_list );
        maxPoints( point_list );
    }
    

}
