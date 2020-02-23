#pragma once

#include <exception>
#include <string>

namespace hex
{

    class HexException : public std::exception
    {
    public:
        HexException(std::string& s) : msg(s) {}
        HexException(const std::string& s) : msg(s) {}
        virtual const char* what() const throw()
        {
            return msg.c_str();
        }
    protected:
        std::string msg;
    };

}