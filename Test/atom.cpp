#include <functional>
#include<vector>
#include<iostream>
#include<algorithm>

#include"atom.hpp"
#include"../Helper.hpp"

void use_atom()
{
    std::cout<<"hello from atom.hpp"<<std::endl;
}

void PrintAdd(int m1, int m2)
{
    std::cout<<"m1 and m2 is :"<< m1 + m2 << std::endl;
}
struct AddNum
{
    void operator()(int num)
    {
        std::cout << num +1 << std::endl;
    }
};

void Bind_Lambda_and_Functor()
{
    std::vector<int> nums {9,8,7,6,5};
     // std::bind way
    std::for_each(nums.begin(), nums.end(), std::bind(PrintAdd, std::placeholders::_1, 10));

     // lambda way
    std::for_each(nums.begin(), nums.end(), [](int elementary){std::cout<<elementary<<std::endl;});

    // functor way
    std::for_each(nums.begin(), nums.end(), AddNum());
}

void Copy_Odd()
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> odd_numbers(numbers.size());
    // cpoy_if return the one past the last element copied. 
    auto end_odd_numbers = std::copy_if(begin(numbers), end(numbers), begin(odd_numbers),[](int n) { return n % 2 == 1; });
    showData<std::vector<int>, int>(odd_numbers); // 1 3 5 7 9 0 0 0 0 0
    std::cout<<" end_odd_numbers:"<<*end_odd_numbers<<std::endl; // 0
    odd_numbers.erase(end_odd_numbers, end(odd_numbers));
    showData<std::vector<int>, int>(odd_numbers);

    // another way
    std::vector<int> odd_numbers_ex;
    std::copy_if(begin(numbers), end(numbers), std::back_inserter(odd_numbers_ex), [](int n) {return n %2 == 1;});
    showData<std::vector<int>, int>(odd_numbers_ex);
}

void SplitLine()
{
    std::cout<<"-------------------------"<<std::endl;
}