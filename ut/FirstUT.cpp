//
// Created by SHERRY on 2019/4/26.
//

#ifndef TRUNK_FIRSTUT_H
#define TRUNK_FIRSTUT_H
#include"../Box.h"
#include<gtest/gtest.h>
#include<iostream>
int add(int m,int n)
{
    return m+n;
}
TEST(CalculateShould,add)
{
    EXPECT_EQ(3,add(1,2));
}
GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif //TRUNK_FIRSTUT_H