#ifndef UNTITLED2_EVENTHANDLERS_H
#define UNTITLED2_EVENTHANDLERS_H

#include <gtk/gtk.h>

void enter_clicked(GtkEntry* entry, gpointer data)
{
    Game *game = new Game();
    //GtkBuilder *builder;

    /*builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "project.glade", NULL);*/

    //game->entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));

    const gchar* currentText = gtk_entry_get_text(GTK_ENTRY(GTK_WIDGET(gtk_builder_get_object(builder, "entry"))));

    if (strcmp(currentText, rWord) == 0)
    {
        game->set_win();
        game->clear_display();
        score = score + tempScore;
        game->set_score();
        game->play();
    }
    else
    {
        game->set_fail();
        game->clear_display();
        tempScore--;
    }
}
#endif //UNTITLED2_EVENTHANDLERS_H
