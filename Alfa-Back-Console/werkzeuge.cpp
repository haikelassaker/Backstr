#include "stdafx.h"
#include "werkzeuge.h"


werkzeuge::werkzeuge()
{
}

const vector<string> werkzeuge::split(const string & s, const char & c)
{
    string buff{ "" };
    vector<string> v;
    for (auto n : s)
    {
        if (n != c)
        {
            buff += n;
        }
        else
        {
            if (n == c && buff != "")
            {
                v.push_back(buff);
                buff = "";
            }
        }
    }
    if (buff != "")
    {
        v.push_back(buff);
    }

    return v;
}


string werkzeuge::join(const string & delimiter, const vector<string>& v)
{
    string out;
    for (unsigned int i = 0; i < v.size(); i += 1)
    {
        out += v[i];
        if((i + 1) < v.size()) {
            out.append(delimiter);
        }
    }
    return out;
}

werkzeuge::~werkzeuge()
{
}
