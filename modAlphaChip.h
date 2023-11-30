#ifndef MODALPHACHIP_H
#define MODALPHACHIP_H

#include <string>
#include <stdexcept>

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};

class modAlphaChip
{
private:
    int key;
    std::string getValidText(const std::string & s);
public:
    modAlphaChip()=delete;
    modAlphaChip(const int & k):key(k) {}
    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};

#endif // MODALPHACHIP_H