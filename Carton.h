//
// Created by SHERRY on 2019/4/20.
//

#ifndef TRUNK_CARTON_H
#define TRUNK_CARTON_H
#include"Box.h"
#include<string>
class Carton:public Box
{
private:
    std::string material_;
public:
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

};
#endif //TRUNK_CARTON_H
