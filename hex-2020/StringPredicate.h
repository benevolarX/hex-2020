#pragma once

#include <string>
#include <regex>
#include "Predicate.h"

namespace hex
{

    struct StringPredicate : public Predicate<std::string>
    {
    public:
        StringPredicate() : Predicate<std::string>() {}
        StringPredicate(std::string& s) : Predicate<std::string>(s) {}
        StringPredicate(const std::string& s) : Predicate<std::string>(s) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de StringPredicate";
        }
        virtual ~StringPredicate() {}
    };

    struct Regex : public StringPredicate
    {
    public:
        Regex(std::string& expr) : StringPredicate(expr) {}
        Regex(const std::string& expr) : StringPredicate(expr) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Regex";
        }
    protected:
        virtual bool test(const std::string& chaine) const {
            return std::regex_match(chaine, std::regex(this->get_val()));
        }
    };

    struct Upper : public Regex
    {
    public:
        Upper() : Regex("([^[:lower:]])+") {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Upper";
        }
    protected:
        virtual bool test(const std::string& chaine) const {
            std::string s = chaine;
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); });
            return s != chaine;
        }
    };

    struct Lower : public Regex
    {
    public:
        Lower() : Regex("([^[:upper:]])+") {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Lower";
        }
    };

    struct Digit : public Regex
    {
    public:
        Digit() : Regex("(\\+|-)?[[:digit:]]+") {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Digit";
        }
    };

    struct Number : public Regex
    {
    public:
        Number() : Regex("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?") {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Number";
        }
    };

    struct AtN : public StringPredicate
    {
    public:
        AtN(char c, unsigned int n = 0) : StringPredicate(), lettre(c), place(n) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de AtN";
        }
    protected:
        virtual bool test(const std::string& chaine) const {
            return (chaine.size() > place) && chaine[place] == lettre;
        }
        char lettre;
        unsigned int place;
    };

    struct First : public AtN
    {
    public:
        First(char c) : AtN(c) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de First";
        }
    };

    struct Last : public AtN
    {
    public:
        Last(char c) : AtN(c) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Last";
        }
    protected:
        virtual bool test(std::string& chaine) {
            return (!chaine.empty()) && chaine[chaine.size() - 1] == lettre;
        }
    };

}