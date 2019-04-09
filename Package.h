//
// Created by SHERRY on 2019/4/7.
//

#ifndef TRUNK_PACKAGE_H
#define TRUNK_PACKAGE_H
#include"Box.h"
using SharedBox = std::shared_ptr<Box>;
class Package
{
private:
    Package *pnext_;
    SharedBox pBox_;
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
        pBox_->listBox();
    }

};

#endif //TRUNK_PACKAGE_H
