#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H

#include <gtk/gtk.h>
#include "dialogs.h"

void enter_clicked(GtkEntry* entry, gpointer data)
{
    auto* gameInterface = new GameInterface();
    auto* dialog = new DialogInterface();
    const gchar* currentText = gtk_entry_get_text(GTK_ENTRY(GTK_WIDGET(gtk_builder_get_object(builder, "entry"))));

    if (strcmp(currentText, randomWord) == 0)
    {
        gameInterface->set_win();
        gameInterface->clear_display();

        score = score + tempScore;
        gameInterface->set_score();

        gameInterface->play();
    }
    else
    {
        gameInterface->set_fail();
        gameInterface->clear_display();

        tempScore--;

        if (tempScore <= 0)
        {
            GtkWidget* lose_dialog;

            lose_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_dialog"));
            dialog->set_lose();

            gtk_widget_show_all(lose_dialog);

            if (gtk_dialog_run(GTK_DIALOG(lose_dialog)) == GTK_RESPONSE_OK)
                gtk_main_quit();
        }
    }

    delete gameInterface;
    delete dialog;
}

void hint_button_clicked(GtkButton* btn, gpointer data)
{
    auto* dialogInterface = new DialogInterface();
    GtkWidget* hint_dialog;

    hint_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_dialog"));
    dialogInterface->set_hint(wordHint);

    gtk_widget_show_all(hint_dialog);

    if (gtk_dialog_run(GTK_DIALOG(hint_dialog)) == GTK_RESPONSE_OK)
        gtk_widget_hide(hint_dialog);

    delete dialogInterface;
}

void stop_button_clicked(GtkButton* btn, gpointer data)
{
    auto* dialogInterface = new DialogInterface();
    GtkWidget* stop_dialog;

    stop_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_dialog"));
    dialogInterface->set_stop();

    gtk_widget_show_all(stop_dialog);

    if (gtk_dialog_run(GTK_DIALOG(stop_dialog)) == GTK_RESPONSE_OK)
        gtk_main_quit();

    delete dialogInterface;
}

void skip_button_clicked(GtkButton* btn, gpointer data)
{
    auto* gameInterface = new GameInterface();
    auto* dialog = new DialogInterface();

    if (score == 0)
        gameInterface->play();
    else if (score > 0)
    {
        gameInterface->play();
        score--;
        gameInterface->set_score();
    }
    else
    {
        GtkWidget* lose_dialog;

        lose_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "neutral_dialog"));
        dialog->set_lose();

        gtk_widget_show_all(lose_dialog);

        if (gtk_dialog_run(GTK_DIALOG(lose_dialog)) == GTK_RESPONSE_OK)
            gtk_main_quit();
    }

    delete gameInterface;
    delete dialog;
}

#endif //UNTITLED2_EVENTHANDLER_H
