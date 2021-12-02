//DISCLAIMER: BEFORE READING THE CODE YOU NEED TO KNOW THAT THERE IS A MUCH SIMPLER WAY TO MAKE ALL OF THIS, I JUST WENT WITH THE GET IT DONE WITH APPROACH...
//I ALSO TRIED TO COMMENT OUT MOST OF THE CODE SO THAT YOU CAN TRY TO UNDERSTAND IT... PLEASE READ THEM, IT WILL MAKE WAY MORE SENSE
//CODE ONLY CREATED ON GIVEN ASSUMPTIONS THAT ALL MESSAGES ARE IN SMALL LETTERS a-z AND ALL PASSWORDS ARE CAPITALIZED A-Z. (All other forms might have bugs(features)).//

#include <iostream>
#include <string.h>

using namespace std;

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
/**
* Returns a string in all uppercase letters
* @param str The string to be converted
* @return Returns a string fully in uppercase letters
*/

    string toUpper (string str) {
        for (char& c : str) {
            if (c == ' ');
            else {
                c = c - 32; }                                                  
        }
    return str;
}

/**
* Returns a string in all lowercase letters
* @param str The string to be converted
* @return Returns a string fully in lowercase letters
*/
string toLower (string str) {
        for (char& c : str) {
            if (c == ' ');
            else {
                c = c + 32; }
        }
    return str;
}

/**
* Generates a key for the encryption
* @param input The message to be encrypted
* @param keyword The entered keyword to be used as a password for the encryption
* @return The generated encryption key
*/
string keyGen(string input, string keyword) {
    int keySize = input.size();
    string key;
        if(input.size() <= keyword.size()){
            keyword.resize(keyword.size()-(keyword.size()-input.size()));
            key = keyword;
        }

        else {                                                                 
            int timeFit = input.size() / keyword.size();
            int remain = input.size() % keyword.size();
            for (int i = 0; i < timeFit; i++) {
                key = key + keyword; }
            keyword.resize(keyword.size() - (keyword.size()-remain) );
            key = key + keyword;
        }
    return key;
}

/**
* Encrypts the given message using the key previously generated
* @param input The message to be encrypted
* @param key The previously generated key
* @return The encrypted message
*/

string encrypt(string input, string key){
    input = toUpper(input);
    string encrypted = input;
        for (int i = 0; i < input.size(); i++) {
            int space = isspace(input[i]);
            if (space != 0) continue;
            else
            encrypted[i] = alphabet[(input[i]+key[i]) % 26];
    }
    return encrypted;
}

/**
* Decrypts the recieved message using the key that was previously generated
* @param encrypted The recieved encrypted message
* @param key The previously generated encryption key
* @return The decrypted original message
*/

string decrypt (string encrypted, string key) {
    string decrypted = encrypted;
    for (int i = 0; i < encrypted.size(); i++) { 
        int space = isspace(encrypted[i]);
            if (space != 0) continue
        else{
            int rank = encrypted[i] - key[i];
            if (rank < 0) rank = rank + 26;
            decrypted[i] = alphabet[rank];}
    }
    decrypted = toLower(decrypted);
    return decrypted;
}

//TEST ENVIRONMENT//

int main(){
    string input, password;
    cout << "Input message to encrypt: ";
    getline(cin, input, '\n');
    cout << "Input encryption password: ";
    getline(cin, password, '\n');
    cout << "The Original Text is --> " << input << endl;
    string key = keyGen(input, password);
    cout << "The Generated Key Is --> " << key << endl;
    string patata = encrypt(input, key);
    cout << "Encrypted Text --> " << patata << endl;
    cout << "Decrypted Text --> " << decrypt(patata, key);
    return 0;
} 