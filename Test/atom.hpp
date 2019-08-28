#pragma once
#include<vector>
#include<string>

void use_atom();
void PrintAdd(int m1, int m2);
void Bind_Lambda_and_Functor();
void Copy_Odd();
void SplitLine();
void LetTransform();

struct SManagerConfiguration
{
    std::string name_;
    std::vector<int> month_salary_;
    SManagerConfiguration(std::string name):name_(name),month_salary_{0}{}

};
