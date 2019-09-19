#include<map>
#include<functional>

#include"molecule.hpp"
#include"../Helper.hpp"
#include"atom.hpp"

namespace test
{
namespace box
{

void ListAllBox()
{
    std::vector<Box> boxes;
    boxes.push_back(Box(1, 2, 3, 4)); // 直接push_back一个object会调用拷贝构造函数
    boxes.push_back(Box(2, 3, 4, 5));
    boxes.push_back(Box(3, 4, 5, 6));
    showData<std::vector<Box>, Box>(boxes);
    auto [minbox, maxbox] = std::minmax_element(boxes.begin(), boxes.end(),[](Box &x, Box &y){return x<y;});
    //auto maxbox = std::max_element(boxes.begin(), boxes.end(),[](Box &x, Box &y){return x<y;});
    std::cout<<"min:"<< *minbox<<std::endl;
    std::cout<<"max:"<< *maxbox<<std::endl;
    std::for_each(boxes.begin(),boxes.end(),[](Box &box){std::cout<<box<<" ";});
}

void Array_swap()
{
    Array<double> arr_d{2}, arr_d2{1};
    arr_d[0] = 1;
    arr_d[1] = 2;
    arr_d[0] = 6;
    arr_d.swap(arr_d2);
    std::cout<< "size:"<<arr_d.getsize()<<std::endl;
    arr_d.show_data();
}

void Polymorphism()
{
    std::vector<std::unique_ptr<Box>> pboxes;
    Carton carton1{1, 2, 3, "Golden"};
    Box box1{3,2,3};
    std::map<int, std::unique_ptr<Box>> box_map;
    box_map[6] = std::make_unique<Carton>(carton1);
    box_map[7] = std::make_unique<Box>(box1);

    pboxes.push_back(std::make_unique<Carton>(carton1));
    pboxes.push_back(std::make_unique<Box>(box1));

    for (const auto&[id,p_map]:box_map)
    {
        std::cout<< id <<" ";
        p_map->listBox();
        SplitLine();
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

void PolymorphismPandR()
{
    Carton carton1{1, 2, 3, "Golden"};
    Box box{1, 2, 3};
    Box *pbox{&box};
    pbox->ShowVolume();

    pbox = &carton1;
    pbox->ShowVolume();
    SplitLine();
    PolymorphismR(box);
    PolymorphismR(carton1);
}

void PolymorphismR(Box &box)
{
    // TO DO, pass vector that store Box&
    box.ShowVolume();
}

void FindBox()
{
    std::vector<Box> boxes;
    boxes.push_back(Box(1, 2, 3, 4)); // 直接push_back一个object会调用拷贝构造函数
    boxes.push_back(Box(2, 3, 4, 5));
    boxes.push_back(Box(3, 4, 5, 6));

    auto it = std::find_if(boxes.begin(),boxes.end(),Is_SameBox(6));

    /*auto baseline {Is_SameBox(6)};
    auto it = std::find_if(boxes.begin(),boxes.end(),baseline);
    auto baseline {Is_SameBox(6)};*/

    /*int m{6};
     auto it = std::find_if(boxes.begin(),boxes.end(),[m](Box box){
        std::cout<<"Hello"<<std::endl;
        return box.GetId() == m;
    });*/

    it->listBox(); // equal (*it).listBox();

    // now, Test another function in IsSameBox
    SharedBox pbox1 {new Box(1, 2, 3, 4)};
    SharedBox pbox2 {new Box(2, 3, 4, 5)};
    SharedBox pbox3 {new Box(3, 4, 5, 6)};
    SharedBox pbox99 {new Box(4, 5, 6, 7)};
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
    auto pbox4 {new Box(5, 6, 7, 8)};
    auto pbox5 {new Box(6, 7, 8, 9)};
    pbox.push_back(pbox4);
    pbox.push_back(pbox5);
    pbox.push_back(pbox1.get());
    auto itoriginal = std::find_if(pbox.begin(), pbox.end(), Is_SameBox(4));
    (* itoriginal)->listBox();
}

void OperBoxinPack()
{
    SharedBox pbox1 {new Box(1, 1, 1)};
    SharedBox pbox2 {new Box(2, 2, 2)};
    SharedBox pbox3 {new Box(3, 3, 3)};
    Package *phead = new Package{pbox1};
    Package *pPackage2 = new Package{pbox2};
    phead->SetNext(pPackage2);
    Package *pPackage3 = new Package{pbox3};
    pPackage2->SetNext(pPackage3);
    phead->ListPackage();
    phead->GetNext()->ListPackage();
    phead->GetCurrentBox()->listBox();
}

void TrunkLoadAdd()
{
    SharedBox pbox1 {new Box(1, 1, 1)};
    SharedBox pbox2 {new Box(2, 2, 2)};
    SharedBox pbox3 {new Box(3, 3, 3)};
    SharedBox pbox0 {new Box(4, 4, 4)};
    TrunkLoad trunkload{pbox0};
    trunkload.addbox(pbox1);
    trunkload.addbox(pbox2);
    trunkload.addbox(pbox3);
    trunkload.ShowAllBox();
}

void TrunkLoadAddAndRemove()
{
    SharedBox pbox1 {new Box(1, 1, 1)};
    SharedBox pbox2 {new Box(2, 2, 2)};
    SharedBox pbox3 {new Box(3, 3, 3)};
    SharedBox pbox0 {new Box(4, 4, 4)};
    std::vector<SharedBox> vecBox;
    vecBox.push_back(pbox0);
    vecBox.push_back(pbox1);
    vecBox.push_back(pbox2);
    vecBox.push_back(pbox3);
    TrunkLoad load{vecBox};
    TrunkLoad load2{load};
    load2.ShowAllBox();
    SharedBox pbox5 {new Box(4, 2, 4)};
    std::cout << "delete:"<< load.RemoveBox(pbox5)<< std::endl;
    load.ShowAllBox();
    SharedBox pbox6 {new Box(6, 6, 6)};
    TrunkLoad load3{pbox6};
    SplitLine();
    load3.ShowAllBox();
    load3 = load;
    SplitLine();
    load3.ShowAllBox();
}

void BindaBox()
{
    Box box{1, 2 ,3, 4}, another{2, 3 ,4, 6};
    auto shared_box = std::make_shared<Box>(6, 7, 8, 9);
    auto bindadd = std::bind(&Box::add, &box, 6, std::placeholders::_1);
    std::function<void()> callback = std::bind(&Box::add, shared_box, 7, 8);
    // although std::bind(&Box::add, shared_box, 7, 8) has a return value, but it can convert 2 void
    // in this case, is a void callback()
    callback();
    std::cout<<"after bind:"<<bindadd(9)<<std::endl;
    auto bindoperator = std::bind(&Box::operator<, &box, another);
    std::cout<<bindoperator()<<std::endl;
}

} // namespace box
} // namespace test
