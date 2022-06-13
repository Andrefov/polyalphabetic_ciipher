#include <iostream>
#include <string>

std::string generateKey(std::string str, std::string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}


std::string cipherText(std::string str, std::string key)
{
    std::string cipher_text;

   
    for (int i = 0; i < str.size(); i++)
    {
        char x = (str[i] + key[i]) % 26;

        x += 'A';
        cipher_text.push_back(x);
    }
    return cipher_text;
}


std::string originalText(std::string cipher_text, std::string key)
{
    std::string orig_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x = (cipher_text[i] - key[i] + 26) % 26;

        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

// Driver program to test the above function
int main()
{
    std::cout << "Welcome to polyalphabetic cipher, please type a word you want to encrypt: \n";
    std::string str;
    std::cin >> str;
    std::cout << "Please type keyword to create cipher:\n";
    std::string keyword;
    std::cin >> keyword;

    std::string key = generateKey(str, keyword);
    std::string cipher_text = cipherText(str, key);

    std::cout << "Ciphertext : "
        << cipher_text << "\n";

    std::cout << "Original/Decrypted Text : "
        << originalText(cipher_text, key);
    return 0;
}