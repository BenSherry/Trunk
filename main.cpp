#include <iostream>
#include <memory>
#include"TrunkLoad.h"
#include"Ins_Array.h"
void  TestClassPackage();
void TestClassBox();
void TestTrunkv1();
void TestTrunkv2();
void TestClassBox2();
void TestInsv1();

int main() {
    std::cout << "Hello, World!" << std::endl;
    TestInsv1();
    return 0;
}
void TestClassBox()
{
    Box box{1,2,3};
    auto pbox {std::make_shared<Box>(box)};
    // or  auto pbox {std::make_shared<Box>(2,3,4)}; std::shared_ptr<Box> pbox2{std::make_shared<Box>(5,6,7)};
    pbox->listBox();
    std::shared_ptr<Box> pbox2{new Box(9,10,11)};
    pbox2->listBox();
}
void  TestClassPackage()
{
    SharedBox pbox1 {new Box(1,1,1)};
    SharedBox pbox2 {new Box(2,2,2)};
    SharedBox pbox3 {new Box(3,3,3)};
    Package *phead = new Package{pbox1};
    Package *pPackage2 = new Package{pbox2};
    phead->SetNext(pPackage2);
    Package *pPackage3= new Package{pbox3};
    pPackage2->SetNext(pPackage3);
    phead->ListPackage();
    phead->GetNext()->ListPackage();
    phead->GetCurrentBox()->listBox();
}
void TestTrunkv1()
{
    SharedBox pbox1 {new Box(1,1,1)};
    SharedBox pbox2 {new Box(2,2,2)};
    SharedBox pbox3 {new Box(3,3,3)};
    SharedBox pbox0 {new Box(4,4,4)};
    TrunkLoad trunkload{pbox0};
    trunkload.addbox(pbox1);
    trunkload.addbox(pbox2);
    trunkload.addbox(pbox3);
    trunkload.ShowAllBox();
}
void TestTrunkv2()
{
    SharedBox pbox1 {new Box(1,1,1)};
    SharedBox pbox2 {new Box(2,2,2)};
    SharedBox pbox3 {new Box(3,3,3)};
    SharedBox pbox0 {new Box(4,4,4)};
    std::vector<SharedBox> vecBox;
    vecBox.push_back(pbox0);
    vecBox.push_back(pbox1);
    vecBox.push_back(pbox2);
    vecBox.push_back(pbox3);
    TrunkLoad load(vecBox);
    TrunkLoad load2{load};
    load2.ShowAllBox();
    SharedBox pbox5 {new Box(4,2,4)};
    std::cout << "delete:"<< load.RemoveBox(pbox5)<< std::endl;
    load.ShowAllBox();
    SharedBox pbox6 {new Box(6,6,6)};
    TrunkLoad load3{pbox6};
    std::cout<<"________________________________"<<std::endl;
    load3.ShowAllBox();
    load3= load;
    std::cout<<"________________________________"<<std::endl;
    load3.ShowAllBox();
}
void TestClassBox2()
{
    SharedBox pbox1 {new Box(1,2,3)};
    SharedBox pbox2 {new Box(2,3,1)};
   bool res = 36<*pbox2;
   std::cout << res<<std::endl;
   res = *pbox2<36;
   std::cout<<"show box"<<*pbox1<<std::endl;
}
void TestInsv1()
{
    Array array{2};
    Box box1{1,2,3};
    Box box2{2,3,4};
}