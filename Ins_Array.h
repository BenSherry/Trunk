//
// Created by SHERRY on 2019/4/11.
//

#ifndef TRUNK_INS_ARRAY_H
#define TRUNK_INS_ARRAY_H
#include"Box.h"
#include<stdexcept>
#include<string>
class Array
{
private:
    Box *element_;
    size_t size_;
public:
    explicit Array(size_t size); // 构造函数
    Array(const Array &array); // 复制构造函数
    ~Array();
    //Array& operator=(Array array);
    //Box &operator[](size_t index);
    const Box &operator[](size_t index) const;
    size_t  GetSize()const {return size_;}
   // void swap(Array &other) noexcept ;
};
Array::Array(size_t size) :size_ {size},element_{new Box[size]}{}
Array::Array(const Array &array):Array(array.size_) {
    for(size_t i{};i<size_;i++)
    {
        element_[i]= array.element_[i];
    }
}
Array::~Array() {
    delete [] element_;
}
const Box& Array::operator[](size_t index) const {
    if(index>= size_)
        throw std::out_of_range {"index out od range,"+std::to_string(index)+"not  small than"+std::to_string(size_)};
    return element_[index];
}


#endif //TRUNK_INS_ARRAY_H
