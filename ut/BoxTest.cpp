#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include"../Box.h"
#include"TestTrunkLoad.hpp"

// g++ BoxTest.cpp -lgtest -lgmock -lpthread to compile

TEST(BoxTestShould, ReturnFaseWhwnBoxIsSmall)
{
    Box box {1, 2, 5};
    Box another{1, 1, 1};
    EXPECT_EQ(box.GetSurface(), 34);
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
