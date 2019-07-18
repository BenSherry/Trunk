#include <iostream>
#include <memory>
#include"TrunkLoad.h"
#include"Carton.h"
#include<algorithm>
#include"Array.h"
#include<map>
#include"Helper.hpp"
#include<execution>
void TestClassPackage();
void TestClassBox();
void TestTrunkv1();
void TestTrunkv2();
void TestClassBox2();
void TestArray1();
void TestCarton();
void Testpolymorphism();
void UseSmartptr();
void pArray();
void TestShowAllData();
void SplitLine()
{
    std::cout<<"-------------------------"<<std::endl;
}
void ReferenceWay(Box &box)
{
    box.ShowVolume();
}
void TestFunctor();
void TestOdd()
{
    std::vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> odd_numbers(numbers.size());
    // cpoy_if return the one past the last element copied. 
    auto end_odd_numbers = std::copy_if(std::execution::par, begin(numbers), end(numbers), begin(odd_numbers),[](int n) { return n % 2 == 1; });
    showData<std::vector<int>, int>(odd_numbers); // 1 3 5 7 9 0 0 0 0 0
    std::cout<<" end_odd_numbers:"<<*end_odd_numbers<<std::endl; // 0
    odd_numbers.erase(end_odd_numbers, end(odd_numbers));
    showData<std::vector<int>, int>(odd_numbers);

    // another way
    std::vector<int> odd_numbers_ex;
    std::copy_if(std::execution::par, begin(numbers), end(numbers), std::back_inserter(odd_numbers_ex), [](int n) {return n %2 == 1;});
    showData<std::vector<int>, int>(odd_numbers_ex);



}
int main() {
    TestOdd();
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
void TestCarton()
{
    Carton carton{"Iron"};
    carton.listBox();
    std::cout<<carton.Getmaterial()<<std::endl;
    Carton carton1{1,2,3,"Golden"};
    carton1.listBox();
    SplitLine();
    Box source{11,22,33};
    Box source2{source};
    source2.listBox();
    SplitLine();
    Carton carton2{carton1};
    //carton2.ShowCarton();
    carton2.listBox();
    SplitLine();
    carton2.Box::listBox();
}
void Testpolymorphism()
{
    Carton carton1{1,2,3,"Golden"};
    Box box{1,2,3};
    Box *pbox{&box};
    pbox->ShowVolume();

    pbox=&carton1;
    pbox->ShowVolume();
    //pbox->add(2,3);
    SplitLine();
    //ReferenceWay(box);
    //ReferenceWay(carton1);

}
void UseSmartptr()
{
    std::vector<std::unique_ptr<Box>> pboxes;
    Carton carton1{1,2,3,"Golden"};
    Box box1{3,2,3};
    std::map<int, std::unique_ptr<Box>> box_map;
    box_map[6] = std::make_unique<Carton>(carton1);
    box_map[7] = std::make_unique<Box>(box1);

    pboxes.push_back(std::make_unique<Carton>(carton1));
    pboxes.push_back(std::make_unique<Box>(box1));

    for (const auto&[id,p_map]:box_map)
    {
        std::cout<< id <<" ";
        p_map->ShowVolume();
    }
    for(auto &p:pboxes)
    {
        p->listBox();
        p->ShowVolume();
        SplitLine();
    }
// backlog：
// 1.父类中的非虚函数A调用虚函数B，也可以发生多态，例如本例中通过Box的ShowVolume 调用虚函数volume()
// 2.vector如果直接测试存储Box 以及子类的对象，之后直接调用虚函数，会发生对象的分片(不会发生多态)
// 3.注意vector 使用make_unique 使用了不同的模板类型
// 4.析构函数和构造函数里调用的虚函数只会调用析构函数或者构造函数所在类的那个虚函数(不会发生多态).
}

void TestFunctor()
{
    std::vector<Box> boxes;
    boxes.push_back(Box(1,2,3,4)); // 直接push_back一个object会调用拷贝构造函数
    boxes.push_back(Box(2,3,4,5));
    boxes.push_back(Box(3,4,5,6));

    auto it = std::find_if(boxes.begin(),boxes.end(),Is_SameBox(6));

    /*auto it = std::find_if(boxes.begin(),boxes.end(),baseline);
    auto baseline {Is_SameBox(6)};*/

    /*int m{6};
     auto it = std::find_if(boxes.begin(),boxes.end(),[m](Box box){
        std::cout<<"Hello"<<std::endl;
        return box.GetId() == m;
    });*/

    it->listBox(); // equal (*it).listBox();

    // now, Test another function in IsSameBox
    SharedBox pbox1 {new Box(1,2,3,4)};
    SharedBox pbox2 {new Box(2,3,4,5)};
    SharedBox pbox3 {new Box(3,4,5,6)};
    SharedBox pbox99 {new Box(4,5,6,7)};
    std::vector<SharedBox> pSharedboxes;
    pSharedboxes.push_back(pbox1);
    pSharedboxes.push_back(pbox2);
    pSharedboxes.push_back(pbox3);
    pSharedboxes.push_back(pbox99);
   auto itbox = std::find_if(pSharedboxes.begin(),pSharedboxes.end(),Is_SameBox(5));
    (*itbox)->listBox(); // itbox is something like a pointer to a pointer

    // if not find ,return the end of of the range, that's mean not always be pSharedboxes.end() example
     auto can_find = std::find_if(pSharedboxes.begin(),pSharedboxes.begin()+1,Is_SameBox(99));
     std::cout<< "no this box:";
     (*can_find)->listBox(); // box 2,3 4
     /* 
     in set or map, use find instead of std::find
     in general, whenever a container offers member functions that are functionally equivalent to an algorithm,
     you should always use the former
     */

    // test the original pointer func
    std::vector<Box*> pbox;
    auto pbox4 {new Box(5,6,7,8)};
    auto pbox5 {new Box(6,7,8,9)};
    pbox.push_back(pbox4);
    pbox.push_back(pbox5);
    pbox.push_back(pbox1.get());
    auto itoriginal = std::find_if(std::execution::par, pbox.begin(), pbox.end(), Is_SameBox(4));
    (* itoriginal)->listBox();
}
void TestArray1()
{
    Array<double> arr_d{2}, arr_d2{1};
    arr_d[0] = 1 ;
    arr_d[1] = 2;
    arr_d[0] = 6;
    arr_d.swap(arr_d2);
    std::cout<< "size:"<<arr_d.getsize()<<std::endl;
    arr_d.show_data();
}
void pArray()
{
    int * num1 = new int[5];
    num1[0] = 1;
    num1[2] = 2;
    std::cout<<num1[2]<<std::endl;
}

void TestShowAllData()
{
    std::vector<Box> boxes;
    boxes.push_back(Box(1,2,3,4)); // 直接push_back一个object会调用拷贝构造函数
    boxes.push_back(Box(2,3,4,5));
    boxes.push_back(Box(3,4,5,6));
    showData<std::vector<Box>, Box>(boxes);
    auto [minbox, maxbox] = std::minmax_element(boxes.begin(), boxes.end(),[](Box &x, Box &y){return x<y;});
    //auto maxbox = std::max_element(boxes.begin(), boxes.end(),[](Box &x, Box &y){return x<y;});
    std::cout<<"min:"<< *minbox<<std::endl;
    std::cout<<"max:"<< *maxbox<<std::endl;
    //std::for_each(boxes.begin(),boxes.end(),[](Box &box){std::cout<<box<<" ";});
}
