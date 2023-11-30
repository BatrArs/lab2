#include <string>
#include  "modAlphaChip.h"

void check(const std::string& Text, const std::string& key)
{
    try {
        std::string cipherText;
        std::string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        if (std::stoi(key) > 0) {
            modAlphaChip cipher(std::stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
            std::cout<<"key="<<key<<std::endl;
            std::cout<<"Encrypted text:  "<<cipherText<<std::endl;
            std::cout<<"Decrypted text:  "<<decryptedText<<std::endl;
        } else
            throw cipher_error(std::string("Invalid key ")+key);
    } catch (const cipher_error & e) {
        std::cerr<<"Error:  "<<e.what()<<std::endl;
    }
    std::cout<<""<<std::endl;
}

int main(int argc, char **argv)
{
    check ("SDR","1");
    check ("MENIA","2");
    check ("INFORMATIKA", "3");
    check("I N F O R M A T I K A","4");
    check("585858","5");
}