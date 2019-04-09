//
// Created by SHERRY on 2019/4/7.
//

#ifndef TRUNK_TRUNKLOAD_H
#define TRUNK_TRUNKLOAD_H
#include"Package.h"
#include<vector>


class TrunkLoad {
private:
    Package *phead_{nullptr};
    Package *pcurr_{nullptr};
    Package *ptail_{nullptr};
public:
    TrunkLoad()=default;
    TrunkLoad( SharedBox box)
    {
        phead_=ptail_= new Package{box};
    }
    TrunkLoad(const std::vector<SharedBox>& Boxes)
    {
        for(const auto & Box:Boxes)
        {
            addbox(Box);
        }
    }
    void addbox(SharedBox box)
    {
        auto package = new Package(box);
        if(ptail_)
            ptail_->SetNext(package);
        else
            phead_=package;
        ptail_= package;
    }
    void ShowAllBox()
    {
        Package *pCurr {phead_};
        while(nullptr != pCurr)
        {
            pCurr->ListPackage();
            pCurr = pCurr->GetNext();
        }
    }
    TrunkLoad(const TrunkLoad & src)
    {
        for(Package *package{src.phead_};package;package = package->GetNext())
            addbox(package->GetCurrentBox());
    }
   bool RemoveBox(SharedBox box2Remove)
   {
        Package *pCurr {phead_};
        Package *pPrev {nullptr};
        while(pCurr)
        {
            if(*(pCurr->GetCurrentBox())==*box2Remove)
            {
                if(pPrev)
                {
                    pPrev->SetNext(pCurr->GetNext());
                }
                else
                {
                    std::cout<<"find head"<<std::endl;
                    phead_= pCurr->GetNext();
                }
                pCurr->SetNext(nullptr);
                delete pCurr;
                return true;
            }
            else
            {
                pPrev = pCurr;
                pCurr = pCurr->GetNext();
            }
        }
        return false;
   }
    TrunkLoad& operator = (const TrunkLoad& src)
    {
        phead_ = pcurr_ = ptail_ = nullptr;
        for(Package *package{src.phead_};package;package = package->GetNext())
            addbox(package->GetCurrentBox());
    }

};


#endif //TRUNK_TRUNKLOAD_H
