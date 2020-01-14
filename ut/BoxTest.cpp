#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include"../Box.h"
#include"TestTrunkLoad.hpp"

class Foo {
 public:
  virtual bool Transform(int m) = 0;

 protected:
  virtual void Resume() = 0;

 private:
  virtual int GetTimeOut() = 0;
};

class MockFoo : public Foo 
{
 public:
  MOCK_METHOD1(Transform, bool(int m));

  // The following must be in the public section, even though the
  // methods are protected or private in the base class.
  MOCK_METHOD0(Resume, void());
  MOCK_METHOD0(GetTimeOut, int());
  MockFoo(){};
};



// g++ BoxTest.cpp -lgtest -lgmock -lpthread to compile

TEST(BoxTestShould, ReturnFaseWhwnBoxIsSmall)
{
    MockFoo foo;
    // std::shared_ptr<MockFoo> mailService = std::make_shared<MockFoo>();
    Box box {1, 2, 5};
    Box another{1, 1, 1};
    EXPECT_EQ(box.GetSurface(), 34);
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
