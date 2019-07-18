//
// Created by SHERRY on 2019/5/28.
//

#ifndef TRUNK_ARRAY_H
#define TRUNK_ARRAY_H
#include <stdexcept>
#include <string>
#include <utility>
#include<algorithm>
template<typename T>
class Array
{
private:
    size_t size_;
    T * elements_;
public:
    explicit Array(size_t size);
    Array(const Array&);
    ~Array();
    size_t getsize(){return size_;}
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    void swap(Array &other) noexcept ;
    void show_data();
};

template<typename T>
Array<T>::Array(size_t size):size_ {size},elements_{new T[size]}{}

template<typename T>
Array<T>::Array(const Array & array):Array{array.size_}
{
    for(size_t i{};i<size_;i++)
    {
        elements_[i] = array.elements_[i];
    }
}
template <typename T>
Array<T>::~Array() {
    delete [] elements_;
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= size_)
        throw std::out_of_range {"Index too large: " + std::to_string(index)};
    return elements_[index];
}
template<typename T>
T& Array<T>::operator[](size_t index)
{
    std::cout<< typeid(*this).name()<<std::endl;
    return const_cast<T&>(std::as_const(*this)[index]);
}

template<typename T>
void Array<T>::swap(Array &other) noexcept
{
    std::swap(size_,other.size_);
    std::swap(elements_,other.elements_);
}
template<typename T>
void Array<T>::show_data() {

}
#endif //TRUNK_ARRAY_H
