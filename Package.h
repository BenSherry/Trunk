#pragma once

#include"Box.h"
using SharedBox = std::shared_ptr<Box>;
class Package
{
private:
    SharedBox pBox_;
    Package *pnext_;
    
public:
    Package(SharedBox pbox):pBox_{pbox},pnext_{nullptr}{}

    Package()= default;

    void SetNext(Package *package)
    {
        pnext_=package;
    }

    Package * GetNext()
    {
        return pnext_;
    }

    SharedBox GetCurrentBox()
    {
        return pBox_;
    }

    ~Package()
    {
        delete pnext_;
    }
    
    void ListPackage()
    {
        // TO DO This function should list all packahe later
        pBox_->listBox();
    }

};
