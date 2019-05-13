#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

#include <gtk/gtk.h>
#include <iostream>
#include "smth.h"
#include "consts.h"

GtkBuilder* builder;

const char *rWord = "";
const char *wHint = "";
gint score = 0;
gint tempScore = 0;

struct Game
{
    GtkWidget *word_label;
    GtkWidget *score_label;
    GtkWidget *win_label;
    GtkWidget *fail_label;
    GtkWidget *entry;

    Game()
    {
        word_label = GTK_WIDGET(gtk_builder_get_object(builder, "word_label"));
        score_label = GTK_WIDGET(gtk_builder_get_object(builder, "score_label"));
        win_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        fail_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    }

    /*const char *rWord = "";
    const char *wHint = "";
    gint *score = 0;
    gint *tempScore = 0;*/

    void set_word(std::string &jumble)
    {
        gchar fullWordText[255] = "";
        const gchar *halfText = "The word is: ";
        const gchar *jumbl = jumble.c_str();

        strcat(fullWordText, halfText);
        strcat(fullWordText, jumbl);

        gtk_label_set_text(GTK_LABEL(this->word_label), fullWordText);
    }

    void set_score()
    {
        gchar fullScoreText[255] = "";
        const gchar *halfText = "Score: ";
        const gchar *scr;

        gchar buf[255];
        sprintf(buf, "%d", score);

        scr = buf;

        strcat(fullScoreText, halfText);
        strcat(fullScoreText, scr);

        gtk_label_set_text(GTK_LABEL(this->score_label), fullScoreText);
    }

    void set_win()
    {
        gtk_label_set_text(GTK_LABEL(this->win_label), "You're right!");
    }

    void set_fail()
    {
        gtk_label_set_text(GTK_LABEL(this->fail_label), "Fail. Try again");
    }

    void clear_display()
    {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }

    void play()
    {
        //choose(rWord, wHint);

        srand(time(NULL));

        int choice = rand() % NUM_WORDS;

        rWord = WORDS[choice][WORD].c_str();
        wHint = WORDS[choice][HINT].c_str();

        std::string jumble = rWord;
        int length = jumble.size();
        tempScore = length;

        jumbling(jumble, length);
        set_word(jumble);
    }
};

#endif //UNTITLED2_GAME_H
