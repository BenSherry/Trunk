#pragma once

#include<algorithm>
#include<iostream>
template<typename T>
void showData(T data)
{
    std::for_each(data.begin(), data.end(), [](decltype(*data.begin()) element) {std::cout << element << " "; });
    std::cout<<"\n";
}
