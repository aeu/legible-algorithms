// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#ifndef TRADE_H
#define TRADE_H

class Trade
{
 public:
    Trade(const int buy_day,
          const int sell_day,
          const int profit);

    bool doesConflict(Trade &trade);
    void dumpTrade();

    bool operator==(const Trade &other);

    int getProfit();
    
 protected:
 private:
    int _buy_day;
    int _sell_day;
    int _profit;
};


#endif
