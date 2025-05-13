// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


class UndergroundSystem {
public:

    std::unordered_map<int,std::pair<std::string,int>> checkins;
    std::unordered_map<std::string, std::pair<int,int>> times;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, std::string stationName, int t)
    {
        checkins[id] = { stationName,t };
    }
    
    void checkOut(int id, std::string stationName, int t)
    {
        auto cit = checkins.find( id );
        std::pair<std::string,int> checkin = cit->second;
        std::string key = checkin.first;
        key += "--";
        key += stationName;
        auto &entry = times[key];
        entry.first += t - checkin.second;
        entry.second += 1;
    }
    
    double getAverageTime(std::string startStation, std::string endStation)
    {
        int count = 0;
        double total_time = 0;
        double average_time = 0;
        std::string key = startStation + "--" + endStation;
        auto &entry = times[key];
        if( entry.first == 0 )
            return 0.0;

        return (double) entry.first / (double) entry.second ;
    }
};


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {

        UndergroundSystem *undergroundSystem = new UndergroundSystem();
        undergroundSystem->checkIn(45, "Leyton", 3);
        undergroundSystem->checkIn(32, "Paradise", 8);
        undergroundSystem->checkIn(27, "Leyton", 10);
        undergroundSystem->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
        undergroundSystem->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
        undergroundSystem->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
        std::cout << undergroundSystem->getAverageTime("Paradise", "Cambridge") << std::endl; // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
        std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
        undergroundSystem->checkIn(10, "Leyton", 24);
        std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;    // return 11.00000
        undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
        std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    }
    return 0;
}
