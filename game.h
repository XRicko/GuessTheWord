#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

#include <gtk/gtk.h>
#include <iostream>
#include "smth.h"
#include "consts.h"

struct Game
{
    GtkWidget *word_label;
    GtkWidget *score_label;
    GtkWidget *win_label;
    GtkWidget* fail_label;
    GtkWidget *entry;

    const char *rWord = "";
    const char *wHint = "";
    gint score = 0;
    gint tempScore = 0;

    void set_word(GtkBuilder *builder, std::string &jumble)
    {
        gchar fullWordText[255] = "";
        const gchar *halfText = "The word is: ";
        const gchar *jumbl = jumble.c_str();

        strcat(fullWordText, halfText);
        strcat(fullWordText, jumbl);

        word_label = GTK_WIDGET(gtk_builder_get_object(builder, "word_label"));
        gtk_label_set_text(GTK_LABEL(word_label), fullWordText);
    }

    void set_score(GtkBuilder *builder)
    {
        gchar fullScoreText[255] = "";
        const gchar *halfText = "Score: ";
        const gchar *scr;

        gchar buf[255];
        sprintf(buf, "%d", score);

        scr = buf;

        strcat(fullScoreText, halfText);
        strcat(fullScoreText, scr);

        score_label = GTK_WIDGET(gtk_builder_get_object(builder, "score_label"));
        gtk_label_set_text(GTK_LABEL(score_label), fullScoreText);
    }

    void set_win(GtkBuilder *builder)
    {
        win_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        gtk_label_set_text(GTK_LABEL(win_label), "You're right!");
    }

    void set_fail(GtkBuilder *builder)
    {
        fail_label = GTK_WIDGET(gtk_builder_get_object(builder, "win_fail_label"));
        gtk_label_set_text(GTK_LABEL(fail_label), "Fail. Try again");
    }

    void clear_display(GtkBuilder *builder)
    {
        entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }

    void play(GtkBuilder* builder)
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
        set_word(builder, jumble);
    }
};

#endif //UNTITLED2_GAME_H
