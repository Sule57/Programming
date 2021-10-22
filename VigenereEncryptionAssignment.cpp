//DISCLAIMER: BEFORE READING THE CODE YOU NEED TO KNOW THAT THERE IS A MUCH SIMPLER WAY TO MAKE ALL OF THIS, I JUST WENT WITH THE GET IT DONE WITH APPROACH...
//I ALSO TRIED TO COMMENT OUT MOST OF THE CODE SO THAT YOU CAN TRY TO UNDERSTAND IT... PLEASE READ THEM, IT WILL MAKE WAY MORE SENSE
//THE CODE IS NOT APPROVED YET BY THE PROFESSOR AND I AM NOT SURE IF HE WILL AGREE WITH SPACES BEING SKIPPED OVER OR IF HE THOUGHT OF SOMETHING ELSE
//ONCE THE CODE HAS BEEN APPROVED I WILL UPDATE THIS --> (Still Not Approved).
//PLEASE IF YOU DECIDE TO USE ANY PART OF THIS CODE, TRY TO CHANGE IT UP A LITTLE SO IT ISN'T OBVIOUS, I WOULD REALLY APPRECIATE THAT SINCE I AM PROVIDING IT HERE FOR
//YOU TO SEE AND EASE IT UP ON YOURSELF A BIT.. BESIDES THAT, HAVE FUN READING!
//CODE ONLY CREATED ON GIVEN ASSUMPTIONS THAT ALL MESSAGES ARE IN SMALL LETTERS a-z AND ALL PASSWORDS ARE CAPITALIZED A-Z. (All other forms might have bugs(features)).//

#include <iostream>
#include <string.h>

using namespace std;

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

                                                                                //since the original algorithm only works for capitalized messages we will be using the functions
                                                                                //toUpper() and toLower() to manipulate the outputs the user sees
    string toUpper (string str) {
        for (char& c : str) {
            if (c == ' ');
            else {
                c = c - 32; }                                                   //takes the value of the character and lowers it by 32 putting it into the capped letter spectre of ASCII
        }
    return str;
}

    //already previously explained//
string toLower (string str) {
        for (char& c : str) {
            if (c == ' ');
            else {
                c = c + 32; }                                                   //takes the value of the character and increases it by 32 putting it into the uncapped letter spectre of ASCII
        }
    return str;
}

//KEY GENERATION//

string keyGen(string input, string keyword) {
    int keySize = input.size();
    string key;
        if(input.size() <= keyword.size()){                                     //In case the keyword (password) is longer than the message itself
            keyword.resize(keyword.size()-(keyword.size()-input.size()));
            key = keyword;
        }

        else {                                                                  //Case where the message is longer than the keyword (password)
            int timeFit = input.size() / keyword.size();                        //Figures out how many times keyword fits into the message
            int remain = input.size() % keyword.size();                         //Figures out how many letters are left after keyword*timeFit
            for (int i = 0; i < timeFit; i++) {
                key = key + keyword; }
            keyword.resize(keyword.size() - (keyword.size()-remain) );          //Resizes the keyword to the bit left and then adds it to the key
            key = key + keyword;
        }
    return key;                                                                 //Function returns a key
}

//ENCRYPTION//
//DISCLAIMER: THE ALGORITHM USED WAS FOUND ON THE WEBSITE https://www.dcode.fr/vigenere-cipher //
//There is no explanation for how it works, because it's literally just implementing the formula from the website before, go and read it you lazy ass//

string encrypt(string input, string key){
    input = toUpper(input);                                                     //The previously mentioned manipulation, since the algo works only on capitalised messages, we make it so
    string encrypted = input;
        for (int i = 0; i < input.size(); i++) {
            int space = isspace(input[i]);                                      //This part is special, in case of a space, it makes the loop skip a turn
            if (space != 0) continue;                                           //Making spaces not encrypted
            else
            encrypted[i] = alphabet[(input[i]+key[i]) % 26];
    }
    return encrypted;                                                           //Function returns the encrypted text in the form of a string
}

//DECRYPTION//
//THE ALGORITHM USED IS ON THE SAME WEBSITE STATED PREVIOUSLY A BIT UNDER ENCRYPTION, PLEASE READ THAT SITE,
//IT IS VERY HELPFUL AND MIGHT HELP YOU SOLVE THE TASK ON YOUR OWN//
//Yet again only explanation on what I added on my own besides what I found on the site//

string decrypt (string encrypted, string key) {
    string decrypted = encrypted;
    for (int i = 0; i < encrypted.size(); i++) { 
        int space = isspace(encrypted[i]);                                      //Same thing as before, skipping over spaces, because they weren't encrypted
            if (space != 0) continue;                                           //So that means we can't decrypt them either... logical
        else{
            int rank = encrypted[i] - key[i];
            if (rank < 0) rank = rank + 26;
            decrypted[i] = alphabet[rank];}
    }
    decrypted = toLower(decrypted);                                             //This is the output manipulation I talked about previously, after the entire code
    return decrypted;                                                           //has been processed we output it again uncapped making the user believe, it wasnt
}                                                                               //capitalised in the first place

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