#include <iostream>
#include <string>
#include <cctype> // for isalpha to check if x is letter


using namespace std;

string encryptText(const string& text, const string& keyword) {
    string cipher_text;
    int keyIndex = 0;
    int keyLength = keyword.length();

    for (char X : text) {
        if (isalpha(X)) {
            char base = isupper(X) ? 'A' : 'a';
            char keyBase = isupper(keyword[keyIndex % keyLength]) ? 'A' : 'a';
            char encryptedChar = (X - base + (keyword[keyIndex % keyLength] - keyBase)) % 26 + base;
            cipher_text += encryptedChar;
            keyIndex++;
        }
        else {
            cipher_text += X;
        }
    }
    return cipher_text;
}

string decryptText(const string& cipher_text, const string& keyword) {
    string real_text;
    int keyIndex = 0;
    int keyLength = keyword.length();

    for (char X : cipher_text) {
        if (isalpha(X)) {
            char base = isupper(X) ? 'A' : 'a';
            char keyBase = isupper(keyword[keyIndex % keyLength]) ? 'A' : 'a';
            char decryptedChar = (X - base - (keyword[keyIndex % keyLength] - keyBase) + 26) % 26 + base;
            real_text += decryptedChar;
            keyIndex++;
        }
        else {
            real_text += X;
        }
    }
    return real_text;
}

int main() {
    string text, keyword;

    cout << "enter text to encrypt:";
    getline(cin, text);
    cout << "enter keyword:";
    getline(cin, keyword);

    string cipher_text = encryptText(text, keyword);
    cout << "encrypted text:" << cipher_text << endl;
    string decrypted_text = decryptText(cipher_text, keyword);
    cout << "decrypted text:" << decrypted_text << endl;

    return 0;
}
