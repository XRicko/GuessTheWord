#ifndef UNTITLED1_SMT_H
#define UNTITLED1_SMT_H

#include <iostream>
#include <string>
#include <ctime>

void jumbling(std::string &jumble, int length)
{
    srand(time(NULL));

    std::string word = jumble;

    for (int i = 0; i < length; i++)
    {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumble[index1];

        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    if (jumble == word)
        jumbling(jumble, length);
}

/*void choose(std::string *rWord, std::string *wHint)
{
    srand(time(NULL));

    int choice = rand() % NUM_WORDS;

    *rWord = WORDS[choice][WORD];
    *wHint = WORDS[choice][HINT];
}*/

/*void game(GtkBuilder* builder)
{
    std::string rWord;
    std::string wHint;

    choose(rWord, wHint);

    std::string jumble = rWord;
    int length = jumble.size();
    int score;
    int tempScore = length;

    jumbling(jumble, length);
    //set_word(builder, jumble);
}
*/
#endif //UNTITLED1_SMT_H
