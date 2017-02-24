#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED
#include<utility>
#include<array>
#include<vector>
#include<iostream>
typedef std::pair<int,int> GOODS;
typedef std::vector<GOODS> VECGOODS;
class Knapsack
{
public:
    Knapsack(int p_limitWeight,VECGOODS p_vg);
    ~Knapsack(){};
    int findKnapsack();
    int getValue(int num,int leftWeight);
private:    
    int m_limitWeight;
    VECGOODS m_vg;
};

#endif