#include <iostream>

#include"Test/atom.hpp"
#include"Test/molecule.hpp"
#include"Helper.hpp"

int main()
{
    Bind_Lambda_and_Functor();
    use_atom();
    test::box::ListAllBox();
    test::box::OperBoxinPack();
    test::box::BindaBox();
    LetTransform();
    Box Box1{4, 7, 9}, Box2{3, 5, 7};
    std::shared_ptr<Box> sharedBoxptr = std::make_shared<Box>(Box1);
    std::unique_ptr<Box> uniqueBoxptr = std::make_unique<Box>(Box2);
    test::box::ShowBoxbyPtr(sharedBoxptr, std::move(uniqueBoxptr));
    if (uniqueBoxptr == nullptr)
    {
        std::cout << "After removed, uniqueBoxptr is nullprt now\n ";
    }

    test::box::BoxinArray();
    test::box::LetsCast();
    TimeHelper::Time time1{ 10, 12, 2020 };
    TimeHelper::Time time2{ 10, 12, 2021 };
    std::cout << time1 - time2 << "\n";
    return 0;
}
