// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <memory>
#include <algorithm>
#include <stdio.h>
#include "Trade.h"


int buildPossibleTrades(std::vector<std::shared_ptr<Trade> > &possible_trades, std::vector<int> &prices)
{
    std::shared_ptr<Trade> current_trade;
    // first build a list of all the possible profitable trades
    for(int start_day = 0; start_day < prices.size(); start_day++)
    {
        for(int end_day = start_day + 1; end_day < prices.size(); end_day++ )
        {
            int profit = prices[end_day] - prices[start_day];
            if( profit > 0 )
            {
                current_trade = std::make_shared<Trade>(start_day, end_day, profit);
                possible_trades.push_back( current_trade );
            }
        }
    }
    return possible_trades.size();
}

bool doConflictsExist(std::shared_ptr<Trade> current_trade,
                      std::vector<std::shared_ptr<Trade> > &current_sequence )
{
    for( auto candidate : current_sequence )
    {
        if( candidate->doesConflict( *current_trade ))
            return true;
    }
    return false;
}

int profitForSequence(std::vector<std::shared_ptr<Trade> > &current_sequence )
{
    int profit = 0;
    for( auto candidate : current_sequence )
    {
        profit += candidate->getProfit() ;
    }
    return profit;
}


void buildAllTradePermutations(const int max_trades,
                               std::vector<std::shared_ptr<Trade> > &possible_trades,
                               std::vector<std::shared_ptr<Trade> > &current_sequence,
                               std::vector<std::vector<std::shared_ptr<Trade> > > &all_sequences)
{
    all_sequences.push_back( current_sequence );
    for(auto current_trade : possible_trades )
    {
        if( current_sequence.size() < max_trades )
        {
            if( find ( current_sequence.begin(), current_sequence.end(), current_trade ) == current_sequence.end())
            {
                if( ! doConflictsExist( current_trade, current_sequence ))
                {
                    current_sequence.push_back( current_trade );
                    buildAllTradePermutations( max_trades, possible_trades, current_sequence, all_sequences );
                    current_sequence.pop_back();
                }
            }
        }
    }
}

void dumpSequence(std::vector<std::shared_ptr<Trade> > &current_sequence)
{
    printf("Sequence length: %lu\n", current_sequence.size());
    std::shared_ptr<Trade> current_trade;
    for(auto current_trade : current_sequence )
    {
        printf("\t");
        current_trade->dumpTrade();
    }
    printf("\n");
}

void dumpPrices( std::vector<int> &prices )
{
    printf("[");
    bool first = true;
    for(auto current_price : prices )
    {
        if( first )
            first = false;
        else
            printf(", ");
        
        printf("%d", current_price );
    }
    printf("]\n");
}


int maxProfit(const int max_trades, std::vector<int> &prices )
{
    dumpPrices(prices);
    std::vector<std::shared_ptr<Trade> > possible_trades;
    int num_trades = buildPossibleTrades( possible_trades, prices );
    printf("There are %lu profitable trades\n", possible_trades.size());


    std::vector<std::shared_ptr<Trade> > current_sequence;
    std::vector<std::vector<std::shared_ptr<Trade> > > all_possible_sequences;
    
    buildAllTradePermutations( max_trades, possible_trades, current_sequence, all_possible_sequences );

    printf("There are %lu possible trade sequences\n",all_possible_sequences.size());

    int best_profit = 0;
    int current_profit;
    std::vector<std::shared_ptr<Trade> > best_sequence;
    
    for(auto current_sequence : all_possible_sequences )
    {
        current_profit = profitForSequence( current_sequence );
        if( current_profit > best_profit )
        {
            best_profit = current_profit;
            best_sequence = current_sequence;
        }
    }
    printf("Best sequence had profit of %d\n", best_profit );
    dumpSequence( best_sequence );
    return 0;
}


int main(int argc, char **argv)
{
    printf("Leetcode 0188 - Best Time to Buy and Sell Stock IV\n");

    {
        int max_trades = 2;
        std::vector<int> prices = { 2,4,1 };
        maxProfit( max_trades, prices );
    }
    {
        int max_trades = 2;
        std::vector<int> prices = { 3,2,6,5,0,3 };
        maxProfit( max_trades, prices );
    }
}
