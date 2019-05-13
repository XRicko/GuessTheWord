#include <gtk/gtk.h>
#include "headers.h"

int main(int argc, char *argv[])
{
    //GtkBuilder *builder;
    Game* game;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "project.glade", NULL);

    game = new Game();

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    game->play();

    g_signal_connect(GTK_WIDGET(gtk_builder_get_object(builder, "entry")), "activate", G_CALLBACK(enter_clicked), NULL);

    gtk_widget_show_all(window);

    gtk_main();
}