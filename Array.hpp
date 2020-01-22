#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Array
{
private:
    size_t size_;
    T* elementPtr_;
public:
    explicit Array(size_t arraySize);
    ~ Array();
    Array(const Array& array);
    Array(Array&& array);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    Array<T>& operator=(const Array& rhs);
    Array<T>& operator=(Array&& rhs);
    void swap(Array& other) noexcept;
};

template<typename T>
Array<T>::Array(size_t arraySize):
    size_{arraySize},
    elementPtr_{new T[arraySize]}{}

template<typename T>
Array<T>::~Array()
{
    std::cout << "deconstruct called.\n";
    if (elementPtr_ != nullptr)
    {
        delete[] elementPtr_;
    }
}

template<typename T>
Array<T>::Array(const Array& array):Array{array.size_}
{
    std::cout << "copy construct called.\n";
    for (size_t i{}; i < size_; i++)
    {
        elementPtr_[i] = array.elementPtr_[i];
    }
}

template<typename T>
Array<T>::Array(Array&& moved):
    size_(moved.size_),
    elementPtr_(moved.elementPtr_)
    {
        std::cout << "moved construct called.\n";
        moved.elementPtr_ = nullptr;
    }

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= size_) 
        throw std::out_of_range {"Index too large: " + std::to_string(index)};

    return elementPtr_[index];
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    /********************************************
    Use the const-and-back-again idiom to avoid code
    duplication between the const and non-const
    overloads of a member function.
    ReturnType Class::Function(Arguments)
    {
        return const_cast<ReturnType>(std::as_const(*this).Function(Arguments));
    }
    **********************************************/
    return const_cast<T&>(std::as_const(*this)[index]);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    std::cout << "normal operator == callled\n";
    Array<T> copy{rhs};
    swap(copy); // copy and swap idom
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& rhs)
{
    std::cout << "move operator == callled\n";
    if (this != &rhs)
    {
        delete[] elementPtr_;
        size_ = rhs.size_;
        elementPtr_ = rhs.elementPtr_;
        rhs.elementPtr_ = nullptr;
    }
    return *this;
}

template<typename T>
void Array<T>::swap(Array& other) noexcept
{
    std::swap(size_, other.size_);
    std::swap(elementPtr_,other.elementPtr_);
}

template<typename T>

void swap(Array<T>& one, Array<T>& other) noexcept
{
    one.swap(other);
}
