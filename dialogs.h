#ifndef UNTITLED2_DIALOGS_H
#define UNTITLED2_DIALOGS_H

#include <gtk/gtk.h>
#include "game.h"

struct DialogInterface
{
    GtkWidget* neutral_label;
    GtkWidget* neutral_button;

    DialogInterface()
    {
        neutral_label = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_label"));
        neutral_button = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_button"));
    }

    void set_lose()
    {
        gtk_label_set_text(GTK_LABEL(neutral_label), "Oops, you lose. Bye!");
        gtk_button_set_label(GTK_BUTTON(neutral_button), "Bye");
    }

    void set_hint(const gchar* hint)
    {
        gtk_label_set_text(GTK_LABEL(neutral_label), hint);
        gtk_button_set_label(GTK_BUTTON(neutral_button), "OK");
    }

    void set_stop()
    {
        gchar fullStopText[255] = "";
        const gchar* halfText = "Thanks for playing! Your final score: ";
        const gchar* scr;

        gchar buf[255];
        sprintf(buf, "%d", score);

        scr = buf;

        strcat(fullStopText, halfText);
        strcat(fullStopText, scr);

        gtk_label_set_text(GTK_LABEL(neutral_label), fullStopText);
        gtk_button_set_label(GTK_BUTTON(neutral_button), "Bye");
    }
};
#endif //UNTITLED2_DIALOGS_H
