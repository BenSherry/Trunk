#pragma once

#include<algorithm>
#include<iostream>
template<typename T, typename T2>
void showData(T data)
{
    std::for_each(data.begin(),data.end(),[](T2 &element){std::cout<<element<<" ";});
    std::cout<< std::endl;
}
