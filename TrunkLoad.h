#pragma once

#include<vector>

#include"Package.h"



class TrunkLoad {
private:
    Package *phead_{nullptr};
    Package *pcurr_{nullptr};
    Package *ptail_{nullptr};
    int numOfBox_;
public:
    TrunkLoad():numOfBox_(0){};

    TrunkLoad(SharedBox box)
    {
        phead_= ptail_= new Package{box};
    }

    TrunkLoad(const std::vector<SharedBox>& Boxes)
    {
        for(const auto &Box:Boxes)
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
            phead_= package;
        ptail_= package;
        numOfBox_++;
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

    TrunkLoad(const TrunkLoad& src)
    {
        for(Package *package{src.phead_}; package; package = package->GetNext())
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
                numOfBox_--;
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
        return *this;
    }

    int getBoxNum() const
    {
        return numOfBox_;
    }

};
