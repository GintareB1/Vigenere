#include <iostream>
#include <string>


using namespace std;

//(' ' to '~')
const int START =32;
const int END =126;
const int RANGE =END-START;

string encryptText(const string& text, const string& keyword) {
    string cipher_text;
    int keyIndex =0;
    int keyLength =keyword.length();

    for (char X : text) {
        if (X >=START && X <=END) {
            char keyChar =keyword[keyIndex % keyLength];
            char encryptedChar =(X-START+(keyChar-START))%RANGE+START;
            cipher_text +=encryptedChar;
            keyIndex++;
        }
        else {
            cipher_text +=X;
        }
    }
    return cipher_text;
}

string decryptText(const string& cipher_text, const string& keyword) {
    string real_text;
    int keyIndex = 0;
    int keyLength = keyword.length();

    for (char X : cipher_text) {
        if (X >=START && X <=END) {
            char keyChar = keyword[keyIndex % keyLength];
            char decryptedChar = (X-START-(keyChar-START)+RANGE)%RANGE+START;
            real_text +=decryptedChar;
            keyIndex++;
        }
        else {
            real_text +=X;
        }
    }
    return real_text;
}

int main() {
    string text, keyword;



    cout << "Enter text to encrypt: ";
    getline(cin, text);

    cout << "Keyword: ";
    getline(cin, keyword);

    string cipher_text = encryptText(text, keyword);
    cout << "Encrypted text: " << cipher_text << endl;

    string decrypted_text = decryptText(cipher_text, keyword);
    cout << "Decrypted text: " << decrypted_text << endl;


    cout << "Character to value:" <<endl;
    for (char c : text) {
        cout << c << " - " << (int)c << endl;
    }
    return 0;
}


