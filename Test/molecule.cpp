#include<map>

#include"molecule.hpp"
#include"../Helper.hpp"
#include"atom.hpp"

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
