#include <iostream>
#include <string>
#include <time.h>
#include <conio.h> //hit any key
#include <thread> //sleep
#include <chrono> //sleep
#include <vector>
#include <algorithm>
using namespace std;

//Choose nine letters
string getLetters()
{
    char cons[] = "BCDFGHJKLMNPQRSTVWXYZ";
    char vowels[] = "AEIOU";

    std::cout << "Choose a vowel [v] or a consonant [c]\n";
    string value {};
    std::cin >> value;

    string letter;
    srand (time(NULL) * rand() % 21413421); //relying on time alone for rndm is not good
    if (value == "c")
        letter = cons[rand() % 21]; //RNDM SEED - https://stackoverflow.com/questions/20132650/how-to-select-random-letters-in-c
    if (value == "v")
        letter = vowels[rand() % 5];

    return letter;
}

//Countdown 30 seconds
int countdown()
{
    for (int cnt{ 30 }; cnt > -1; --cnt)
        {
            std::cout << "Counting down!! " << cnt << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second sleep = 1000
        }

    return 0;
}

//Check if words are valid (i.e. only use letters from selection)
std::vector<std::string> checkWords(std::vector<std::string> words, std::string letters)
{
    std::vector<std::string> newwords {};
    for (size_t i = 0; i < words.size(); ++i) { //https://www.fluentcpp.com/2018/10/26/how-to-access-the-index-of-the-current-element-in-a-modern-for-loop/
        std::cout << "\nWord: " << words[i] << "\n";
        int swch {1};
        for (auto& w : words[i]) {
            if (letters.find(w) != string::npos)
                continue;
            else
                {
                std::cout << "Player " << i+1 << ", '" << w << "' not in selection!\n";
                newwords.push_back( "" ); //give zero scoring string if word is unacceptable
                swch = 0;
                break;}
            }
        if (swch == 1) //only add word to new list if word is acceptable
            {std::cout << "Word OK\n";
            newwords.push_back( words[i] );}
        }

    return newwords; // rtn a vector ( as called at start of function
}

int main()
{
    string letters;

    for (int count{ 0 }; count < 9; ++count)
        {
        letters = letters + getLetters() + " ";
        std::cout << letters << "\n";
        }

    std::cout << "\n\nYOU'RE CHOSEN LETTERS ARE: *** " << letters << " ***\n\n";
    std::cout << "\n\nHIT ANY KEY TO START 30 SECONDS COUNTDOWN\n";

    getch(); //hit any key

    std::cout << "\nCOUNTDOWN!!!\n\n";

    //TIMER
    countdown();

    std::cout << "\n\nTIME'S UP - STOP THINKING!!!\n\nWhat's your words from: " << letters;
    std::cout << "\n\nPlayer #1, what's your word?\n";
    string p1 {};
    std::cin >> p1;

    std::cout << "\n\nPlayer #2, what's your word?\n";
    string p2 {};
    std::cin >> p2;

    std::vector<std::string> words {p1, p2};
    words = checkWords(words, letters);

    //Decide winner
    if (words[0].length() > words[1].length())
        std::cout << "\n\nCongratulations player 1, you win with " << p1.length() << " points!\n";
    else if (words[0].length() < words[1].length())
        std::cout << "\n\nCongratulations player 2, you win with " << p2.length() << " points!\n";
    else
        std::cout << "\n\nA tie! Both players score " << words[0].length() << " points!\n";

    return 0;
}
