//
// Created by SHERRY on 2019/4/7.
//

#pragma once

#include<iostream>
#include<iomanip>
#include<memory>
class Box
{
public:
    Box()= default;
    explicit Box(double lv,double hv,double wv,int id = 0):
            length_{lv},height_{hv},width_{wv},id_{id}{
    }
    virtual double volume () const
    {
        return length_*height_*width_;
    }
    explicit Box(Box  const &box):
            length_{box.length_},width_{box.width_},height_{box.height_},id_{box.id_}{
    }
    virtual void listBox() const
    {
        std::cout<<"Box("<<std::setw(2)<<length_<<','
                         <<std::setw(2)<<height_<<','
                         <<std::setw(2)<<width_<<')'<<std::endl;
    }
    bool operator==(const Box& aBox) const
    {
        if(height_== aBox.height_ && width_ == aBox.width_ && aBox.length_ == length_)
            return true;
        return false;
    }
    bool operator<(const Box& aBox) const
    {
        if(GetSurface()<aBox.GetSurface())
            return true;
        return false;
    }
    double GetSurface() const
    {
        return 2*(length_*width_+length_*height_+width_*height_);
    }
    virtual int add(int m,int n)
    {
        return m*n;
    }
    double GetLength() const
    {
        return length_;
    }
    double GetWidth() const
    {
        return width_;
    }
    double GetHeight()const
    {
        return height_;
    }
    void ShowVolume()
    {
        std::cout<<"volume is:"<<volume()<<std::endl;
    }
    int GetId()
    {
        return id_;
    }
     // An interesting thing, in this project, if declare friend function here and 
     // define it out of class, there is a compile error like this:
     // multiple definition of `operator<<(std::ostream&, Box const&)'; CMakeFiles/Trunk.dir/main.cpp.o:main.cpp:(.text+0x0): first defined here

    friend std::ostream &operator << (std::ostream & stream,const Box &box)
    {
        stream << "Box(" << std::setw(2) << box.length_ << ','
           << std::setw(2) << box.height_ << ','
           << std::setw(2) << box.width_<< ')';
        return stream;
    }
    virtual ~Box() = default;
private:
    double length_{1};
    double height_{1};
    double width_{1};
    int id_{-1};
};
inline bool operator<(double value, const Box& aBox)
{
    return value < aBox.GetSurface();
}
inline bool operator<(const Box& aBox,double value)
{
    return aBox.GetSurface()<value;
}

struct Is_SameBox
{
private:
    int id_;
public:
    Is_SameBox(int id):id_{id}{}
    bool operator()(Box& box)
    {
        return box.GetId() == id_;
    }
    bool operator()(Box *box)
    {
        return box->GetId() == id_;
    }
    bool operator()(std::shared_ptr<Box> pbox)
    {
        return pbox->GetId() == id_;
    }
};
