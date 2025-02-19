#include <iostream>
#include <string>

using namespace std;

const string SET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[{]};:'\",<.>/?`~ \\|";
const int SET_SIZE = SET.length();

int getCharIndex(char c) {
    size_t index = SET.find(c);
    return (index != string::npos) ? index : -1;
}

string encryptText(const string& text, const string& keyword) {
    string real_text;
    int keyPosition = 0;
    int keyLength = keyword.length();

    for (char X : text) {
        int charIndex = getCharIndex(X);
        int keyIndex = getCharIndex(keyword[keyPosition % keyLength]);

        if (charIndex != -1 && keyIndex != -1) {
            real_text += SET[(charIndex + keyIndex) % SET_SIZE];
            keyPosition++;
        }
        else {
            real_text += X;
        }
    }
    return real_text;
}

string decryptText(const string& encryptedText, const string& keyword) {
    string real_text;
    int keyPosition = 0;
    int keyLength = keyword.length();

    for (char X : encryptedText) {
        int charIndex = getCharIndex(X);
        int keyIndex = getCharIndex(keyword[keyPosition % keyLength]);

        if (charIndex != -1 && keyIndex != -1) {
            real_text += SET[(charIndex - keyIndex + SET_SIZE) % SET_SIZE];
            keyPosition++;
        }
        else {
            real_text += X;
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

    string encryptedText = encryptText(text, keyword);
    cout << "Encrypted text: " << encryptedText << endl;
    string decryptedText = decryptText(encryptedText, keyword);
    cout << "Decrypted text: " << decryptedText << endl;

    
    cout << "Character to numbers:\n";
    for (char c : text) {
        cout << c << " - " << getCharIndex(c) << endl;
    }

    return 0;
}
