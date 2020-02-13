#include "Helper.hpp"

std::string strReplace(std::string sentence,
    std::string src,
    std::string dst)
{
    int pos = 0;
    while ((pos = sentence.find(src, pos)) != std::string::npos)
    {
        sentence.replace(pos, src.length(), dst);
        pos = pos + dst.length();
    }
    return sentence;
}

void split_byContent(const std::string& src,
    const std::string& pattern,
    std::vector<std::string>& vecctorResult)
{
    std::string::size_type lastpos = src.find_first_not_of(pattern, 0);
    std::string::size_type pos = src.find_first_of(pattern, lastpos);
    while (std::string::npos != pos || std::string::npos != lastpos)
    {
        vecctorResult.push_back(src.substr(lastpos, pos - lastpos));
        lastpos = src.find_first_not_of(pattern, pos);
        pos = src.find_first_of(pattern, lastpos);
    }
}

void split_byLength(const std::string& src,
    const int& special_length,
    std::vector<std::string>& vecctorResult)
{
    int total_len = src.length();
    int split_len = total_len / special_length;
    int remainder = total_len % special_length;
    if (remainder > 0) {
        split_len = split_len + 1;
    }

    for (int i = 0; i < split_len; i++) {
        vecctorResult.push_back(src.substr(i * special_length, special_length));
    }
}