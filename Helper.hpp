#pragma once

#include<algorithm>
#include<iostream>
#include<string>
#include<array>
#include<numeric>

template<typename T>
void showData(T data)
{
    std::for_each(data.begin(), data.end(), [](decltype(*data.begin()) element) {std::cout << element << " "; });
    std::cout<<"\n";
}

std::string strReplace(std::string sentence,
    std::string src,
    std::string dst);

void split_byContent(const std::string& src,
    const std::string& pattern,
    std::vector<std::string>& vecctorResult);

void split_byLength(const std::string& src,
    const int& special_length,
    std::vector<std::string>& vecctorResult);

namespace TimeHelper
{
    class Time
    {
    public:
        Time(int day, int month, int year) :
            day_{ day },
            month_{ month },
            year_{ year },
            isLeap_{isLeapYear()}{};

        Time(const Time& other)
        {
            day_ = other.getDay();
            month_ = other.getMonth();
            year_ = other.getYear();
            isLeap_ = other.getLeap();
        }

        int getDay() const { return day_; };

        int getMonth() const { return month_; };

        int getYear() const { return year_; };

        bool getLeap() const { return isLeap_; }

        int operator-(const Time& other)
        {
            return TimeDiffBase() - other.TimeDiffBase();
        }
        Time& operator=(const Time& other)
        {
            day_ = other.getDay();
            month_ = other.getMonth();
            year_ = other.getYear();
            isLeap_ = other.getLeap();
            return *this;
        }
    private:
        int TimeDiffBase() const
        {
            /*******************************************************
            make 0001-01-01 as base;
            1.there is 97 leap years and 403 nonleap year in 400 years
            century4Inyear * (97 * 366 + 303 * 365)

            2.getYear() % 400 is the rest part.
            in this part,rest/4 - rest/100 is leap years

            nocice, after this,we get days about whole year, include
            some uncome days in this year
            ***********************************************************/
            int century4Inyear = getYear() / 400;
            int rest = getYear() % 400;
            int leapsInRest = rest / 4 - rest / 100;
            int nonleapInRest = rest - leapsInRest;
            int daysofwholeYears = century4Inyear * (97 * 366 + 303 * 365) +
                (leapsInRest * 366 + nonleapInRest * 365);
            int daysInThisYear = 365;
            if (getLeap())
            {
                daysInThisYear = 366;
            }
            int uncomeDay = daysInThisYear - getPastThisYear();
            int day = daysofwholeYears - uncomeDay;

            return day;
        }

        int getPastThisYear() const
        {
            std::array<int, 12> dayMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (getLeap())
            {
                dayMonth[1] = 29;
            }
            if (getMonth() == 1)
            {
                return getDay();
            }
            int pastDay = std::accumulate(dayMonth.begin(),
                dayMonth.begin() + getMonth() - 1,
                0);
            return pastDay + getDay();
        }

        bool isLeapYear() const
        {
            if ((year_ % 400 == 0) ||
                (year_ % 4 == 0 && year_ % 100 != 0))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int day_;
        int month_;
        int year_;
        bool isLeap_;
    };
} // namespace TimeHelper
