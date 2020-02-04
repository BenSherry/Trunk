#pragma once
#include<vector>
#include<memory>

#include"../Carton.h"
#include"../Array.hpp"
#include"../Package.h"
#include"../TrunkLoad.h"

namespace test
{
namespace box
{
  
void ListAllBox();
void Array_swap();
void Polymorphism();
void PolymorphismPandR();
void PolymorphismR(Box &box);
void FindBox();
void OperBoxinPack();
void TrunkLoadAdd();
void TrunkLoadAddAndRemove();
void BindaBox();
void ShowBoxbyPtr(std::shared_ptr<Box> sharedBox, std::unique_ptr<Box> uniqueBox);
void BoxinArray();
void LetsCast();

} // namespace box
} // namespace test
