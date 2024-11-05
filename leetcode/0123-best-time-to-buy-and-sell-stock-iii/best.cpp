#include <stdio.h>
#include <vector>

typedef struct TransactionResult {
    int profit;
    int start_index;
    int end_index;
} TransactionResult;


TransactionResult findBestTransactionInRange(std::vector<int> values,
                                             const int start_index,
                                             const int end_index )
{
    TransactionResult retval;
    retval.start_index = 0;
    retval.end_index = 0;
    retval.profit = 0;


    int start_point = start_index;
    while( start_point < end_index )
    {
        int end_point = end_index;
        for(auto index=start_point+1;index<end_point;index++)
        {
            auto buy_price = values[start_point];
            auto sell_price = values[index];
            auto profit = sell_price -  buy_price;
            if( profit > retval.profit )
            {
                retval.profit      = profit;
                retval.start_index = start_point;
                retval.end_index   = index;
            }
        }
        start_point++;
    }
    return retval;
}
    


int main( int argc, char **argv)
{
    printf("Leetcode #0123 - Best Time to Buy and Sell Stock III\n");

    { // test case 1
        TransactionResult transaction_one;
        transaction_one.start_index = 0;
        transaction_one.end_index = 0;
        transaction_one.profit = 0;
        
        TransactionResult transaction_two;
        transaction_two.start_index = 0;
        transaction_two.end_index = 0;
        transaction_two.profit = 0;
    
        std::vector<int> prices =  {3,3,5,0,0,3,1,4};

        long unsigned int pivot_point = 1;

        while( pivot_point <= prices.size() )
        {

            TransactionResult transaction_candidate_one;
            transaction_candidate_one.start_index = 0;
            transaction_candidate_one.end_index = 0;
            transaction_candidate_one.profit = 0;
            
            TransactionResult transaction_candidate_two;
            transaction_candidate_two.start_index = 0;
            transaction_candidate_two.end_index = 0;
            transaction_candidate_two.profit = 0;

            
            transaction_candidate_one = findBestTransactionInRange(prices, 0, pivot_point );
            if( pivot_point < prices.size() -1 )
                transaction_candidate_two = findBestTransactionInRange(prices, pivot_point+1, prices.size() );

            if (( transaction_candidate_one.profit + transaction_candidate_two.profit ) > ( transaction_one.profit + transaction_two.profit ) )
            {
                transaction_one.start_index = transaction_candidate_one.start_index;
                transaction_one.end_index = transaction_candidate_one.end_index;
                transaction_one.profit = transaction_candidate_one.profit;
                
                transaction_two.start_index = transaction_candidate_two.start_index;
                transaction_two.end_index = transaction_candidate_two.end_index;
                transaction_two.profit = transaction_candidate_two.profit;
            }
            pivot_point++;
        }
        printf("\n\nBest Transations \n");
        printf("Transaction One -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_one.profit, transaction_one.start_index, transaction_one.end_index );
        printf("Transaction Two -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_two.profit, transaction_two.start_index, transaction_two.end_index );
        printf("Total Profit : %d\n", ( transaction_one.profit + transaction_two.profit ));
    }
    { // test case 1
        TransactionResult transaction_one;
        transaction_one.start_index = 0;
        transaction_one.end_index = 0;
        transaction_one.profit = 0;
        
        TransactionResult transaction_two;
        transaction_two.start_index = 0;
        transaction_two.end_index = 0;
        transaction_two.profit = 0;
    
        std::vector<int> prices =  {1,2,3,4,5};

        long unsigned int pivot_point = 1;

        while( pivot_point <= prices.size() )
        {

            TransactionResult transaction_candidate_one;
            transaction_candidate_one.start_index = 0;
            transaction_candidate_one.end_index = 0;
            transaction_candidate_one.profit = 0;
            
            TransactionResult transaction_candidate_two;
            transaction_candidate_two.start_index = 0;
            transaction_candidate_two.end_index = 0;
            transaction_candidate_two.profit = 0;

            
            transaction_candidate_one = findBestTransactionInRange(prices, 0, pivot_point );
            if( pivot_point < prices.size() -1 )
                transaction_candidate_two = findBestTransactionInRange(prices, pivot_point+1, prices.size() );

            if (( transaction_candidate_one.profit + transaction_candidate_two.profit ) > ( transaction_one.profit + transaction_two.profit ) )
            {
                transaction_one.start_index = transaction_candidate_one.start_index;
                transaction_one.end_index = transaction_candidate_one.end_index;
                transaction_one.profit = transaction_candidate_one.profit;
                
                transaction_two.start_index = transaction_candidate_two.start_index;
                transaction_two.end_index = transaction_candidate_two.end_index;
                transaction_two.profit = transaction_candidate_two.profit;
            }
            pivot_point++;
        }
        printf("\n\nBest Transations \n");
        printf("Transaction One -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_one.profit, transaction_one.start_index, transaction_one.end_index );
        printf("Transaction Two -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_two.profit, transaction_two.start_index, transaction_two.end_index );
        printf("Total Profit : %d\n", ( transaction_one.profit + transaction_two.profit ));
    }
    { // test case 1
        TransactionResult transaction_one;
        transaction_one.start_index = 0;
        transaction_one.end_index = 0;
        transaction_one.profit = 0;
        
        TransactionResult transaction_two;
        transaction_two.start_index = 0;
        transaction_two.end_index = 0;
        transaction_two.profit = 0;
    
        std::vector<int> prices =  {7,6,4,3,1};

        long unsigned int pivot_point = 1;

        while( pivot_point <= prices.size() )
        {

            TransactionResult transaction_candidate_one;
            transaction_candidate_one.start_index = 0;
            transaction_candidate_one.end_index = 0;
            transaction_candidate_one.profit = 0;
            
            TransactionResult transaction_candidate_two;
            transaction_candidate_two.start_index = 0;
            transaction_candidate_two.end_index = 0;
            transaction_candidate_two.profit = 0;

            
            transaction_candidate_one = findBestTransactionInRange(prices, 0, pivot_point );
            if( pivot_point < prices.size() -1 )
                transaction_candidate_two = findBestTransactionInRange(prices, pivot_point+1, prices.size() );

            if (( transaction_candidate_one.profit + transaction_candidate_two.profit ) > ( transaction_one.profit + transaction_two.profit ) )
            {
                transaction_one.start_index = transaction_candidate_one.start_index;
                transaction_one.end_index = transaction_candidate_one.end_index;
                transaction_one.profit = transaction_candidate_one.profit;
                
                transaction_two.start_index = transaction_candidate_two.start_index;
                transaction_two.end_index = transaction_candidate_two.end_index;
                transaction_two.profit = transaction_candidate_two.profit;
            }
            pivot_point++;
        }
        printf("\n\nBest Transations \n");
        printf("Transaction One -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_one.profit, transaction_one.start_index, transaction_one.end_index );
        printf("Transaction Two -> Profit: %d, Buy At: %d, Sell At %d\n", transaction_two.profit, transaction_two.start_index, transaction_two.end_index );
        printf("Total Profit : %d\n", ( transaction_one.profit + transaction_two.profit ));
    }
    return 0;



    
}
