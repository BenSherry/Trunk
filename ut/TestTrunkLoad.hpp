#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<memory>

#include"../TrunkLoad.h"

// g++ BoxTest.cpp -lgtest -lgmock -lpthread to compile
using namespace  testing;


class TestTrunkLoad : public Test
{
    protected:
    virtual void SetUp()
    {
        trunkloadptr_ = std::make_shared<TrunkLoad>();
        auto boxptr = std::make_shared<Box>(1,2,3,4);
        trunkloadptr_->addbox(boxptr);

    };
    void TearDown()
    {

    };

    std::shared_ptr<TrunkLoad> trunkloadptr_;

};

TEST_F(TestTrunkLoad, Addboxsuccess)
{
    auto boxptr = std::make_shared<Box>(2,2,3,4);
    trunkloadptr_->addbox(boxptr);
    EXPECT_EQ(trunkloadptr_->getBoxNum(), 2);
}

TEST_F(TestTrunkLoad, Removeboxsuccess)
{
    auto boxptr = std::make_shared<Box>(2,2,3,4);
    trunkloadptr_->addbox(boxptr);
    EXPECT_EQ(trunkloadptr_->getBoxNum(), 2);
    trunkloadptr_->RemoveBox(boxptr);
    EXPECT_EQ(trunkloadptr_->getBoxNum(), 1);
}

TEST_F(TestTrunkLoad, Removeunexitbox)
{
    auto boxptr = std::make_shared<Box>(2,2,3,4);
    trunkloadptr_->RemoveBox(boxptr);
    EXPECT_EQ(trunkloadptr_->getBoxNum(), 1);
}
