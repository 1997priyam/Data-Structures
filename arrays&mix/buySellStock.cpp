/* 
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
*/



#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = -1; 
        int sellPrice = -1;
        bool isBuy = true;
        for(int i=0; i<prices.size(); i++) {
            if (isBuy && buyPrice == -1) {
                buyPrice = prices[i];
            } else if (isBuy){
                if(buyPrice >= prices[i]) {
                    buyPrice = prices[i];
                } else {
                    sellPrice = prices[i];
                    isBuy = false;
                    maxProfit += getProfit(buyPrice, sellPrice);
                }
            } else if (!isBuy) {
                if (sellPrice <= prices[i]) {
                    maxProfit += prices[i] - sellPrice;
                    sellPrice = prices[i];
                } else {
                    buyPrice = prices[i];
                    isBuy = true;
                }
            } else {}
            
        }
        return maxProfit;
    }
    
    int getProfit(int buy, int sell) {
        return sell - buy;
    }
};