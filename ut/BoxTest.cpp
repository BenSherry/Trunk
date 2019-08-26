#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include"../Box.h"

// g++  BoxTest.cpp -lgtest -lgmock -lpthread to compile

TEST(BoxTestShould, ReturnFaseWhwnBoxIsSmall)
{
    Box box {1, 2, 5};
    Box another{1, 1, 1};
    EXPECT_EQ(box.GetSurface(), 46);
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
