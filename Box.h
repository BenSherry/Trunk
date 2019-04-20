//
// Created by SHERRY on 2019/4/7.
//

#ifndef TRUNK_BOX_H
#define TRUNK_BOX_H
#include<iostream>
#include<iomanip>
class Box
{
public:
   // Box()= default;
   Box()
   {
       std::cout<<"From base"<<std::endl;
   }
    Box(double lv,double hv,double wv):length_{lv},height_{hv},width_{wv}{}
    double volume () const
    {
        return length_*height_*width_;
    }
    Box(Box &box):length_{box.length_},width_{box.width_},height_{box.height_}{}
    void listBox() const
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
    friend std::ostream &operator <<(std::ostream & stream,const Box &box);
    friend std::istream &operator >>(std::istream & stream, Box &box);
private:
    double length_{1};
    double height_{1};
    double width_{1};
};
inline bool operator<(double value, const Box& aBox)
{
    std::cout<<"from 2 binary function"<<std::endl;
    return value < aBox.GetSurface();
}
inline bool operator<(const Box abox,double value)
{
    return abox.GetSurface()<value;
}
std::ostream &operator <<(std::ostream & stream,const Box &box)
{
    stream << "Box(" << std::setw(2) << box.length_ << ','
           << std::setw(2) << box.height_ << ','
           << std::setw(2) << box.width_<< ')';
    return stream;
}
std::istream &operator >>(std::istream & stream, Box &box)
{
    
}

#endif //TRUNK_BOX_H
