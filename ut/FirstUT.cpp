//
// Created by SHERRY on 2019/4/26.
//

#ifndef TRUNK_FIRSTUT_H
#define TRUNK_FIRSTUT_H
#include"../Box.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>
int add(int m,int n)
{
    return m+n;
}
TEST(CalculateShould,add)
{
    EXPECT_EQ(3,add(1,2));
}
#endif //TRUNK_FIRSTUT_H