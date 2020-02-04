#pragma once

#include"Box.h"
#include<string>
class Carton:public Box
{
    //using Box::Box;
private:
    std::string material_;
public:
    Carton() = default;

    explicit Carton(std::string mat = "Cardboard") : material_ {mat}{std::cout<<"From derived"<<std::endl;}

    Carton(double lv,double hv,double wv,std::string mat):Box{lv,hv,wv},material_{mat}{}

    Carton(Carton &carton):Box{carton},material_{carton.material_}{}

    std::string Getmaterial() const {
        return material_;
    }

    void ShowCarton()
    {
        listBox();
        std::cout<<"made of "<<material_<<std::endl;
    }

    void listBox() const override
    {
        Box::listBox();
        std::cout<<"made of "<<material_<<std::endl;
    }

    double volume () const
    {
        return Box::volume()*0.8;
    }

    virtual ~Carton()
    {
        std::cout<<"From derived destruct"<<std::endl;
    }
    
    int add(int m,int n) override
    {
        return m+n;
    }

};
