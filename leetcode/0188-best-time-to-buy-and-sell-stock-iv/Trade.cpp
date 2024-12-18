// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <stdio.h>
#include "Trade.h"

Trade::Trade(const int buy_day,
             const int sell_day,
             const int profit)
{
    _buy_day  = buy_day;
    _sell_day = sell_day;
    _profit = profit;
}

void Trade::dumpTrade()
{
    printf("Trade: buy day %d, end day %d, profit %d\n",
           _buy_day+1,
           _sell_day+1,
           _profit);
}

bool Trade::doesConflict(Trade &trade)
{
    if(( trade._buy_day >= _buy_day ) && ( trade._buy_day <= _sell_day ))
    {
        return true;
    }
    if(( trade._sell_day >= _buy_day ) && ( trade._sell_day <= _sell_day ))
    {
        return true;
    }
    if(( _buy_day >= trade._buy_day ) && ( _buy_day <= trade._sell_day ))
    {
        return true;
    }
    if(( _sell_day >= trade._buy_day ) && ( _sell_day <= trade._sell_day ))
    {
        return true;
    }
    return false;
}

int Trade::getProfit()
{
    return _profit;
}

bool Trade::operator==(const Trade &other)
{
    if(( _buy_day == other._buy_day )
       && ( _sell_day == other._sell_day )
       && ( _profit == other._profit ))
        return true;
    return false;
}
