#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

#include <gtk/gtk.h>
#include <iostream>
#include "consts.h"

void jumbling(std::string &jumble, int length);

GtkBuilder* builder;

const char* randomWord = "";
const char* wordHint = "";
gint score = 0;
gint tempScore = 0;

struct GameInterface
{
    GtkWidget* word_label;
    GtkWidget* score_label;
    GtkWidget* win_label;
    GtkWidget* fail_label;
    GtkWidget* entry;

    GameInterface()
    {
        word_label = GTK_WIDGET(gtk_builder_get_object(builder, "word_label"));
        score_label = GTK_WIDGET(gtk_builder_get_object(builder, "score_label"));
        win_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        fail_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    }

    void set_word(std::string &jumble)
    {
        gchar fullWordText[255] = "";
        const gchar* halfText = "The word is: ";
        const gchar* jumbl = jumble.c_str();

        strcat(fullWordText, halfText);
        strcat(fullWordText, jumbl);

        gtk_label_set_text(GTK_LABEL(word_label), fullWordText);
    }

    void set_score()
    {
        gchar fullScoreText[255] = "";
        const gchar* halfText = "Score: ";
        const gchar* scr;

        gchar buf[255];
        sprintf(buf, "%d", score);

        scr = buf;

        strcat(fullScoreText, halfText);
        strcat(fullScoreText, scr);

        gtk_label_set_text(GTK_LABEL(score_label), fullScoreText);
    }

    void set_win()
    {
        gtk_label_set_text(GTK_LABEL(win_label), "You're right!");
    }

    void set_fail()
    {
        gtk_label_set_text(GTK_LABEL(fail_label), "Fail. Try again");
    }

    void clear_display()
    {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }

    void play()
    {
        srand(time(NULL));

        int choice;
        int length;
        std::string jumble;

        choice = rand() % NUM_WORDS;

        randomWord = WORDS[choice][WORD].c_str();
        wordHint = WORDS[choice][HINT].c_str();

        jumble = randomWord;
        length = jumble.size();

        tempScore = length;

        jumbling(jumble, length);

        set_word(jumble);
        //set_score();
    }
};

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

#endif //UNTITLED2_GAME_H
