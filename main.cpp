#include <gtk/gtk.h>
#include "eventHandler.h"

int main(int argc, char *argv[])
{
    GameInterface* gameInterface;
    GtkWidget* window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gameInterface = new GameInterface();
    gameInterface->play();

    gtk_builder_add_callback_symbols(builder, "enter_clicked", G_CALLBACK(enter_clicked),
                                     "hint_button_clicked", G_CALLBACK(hint_button_clicked),
                                     "stop_button_clicked", G_CALLBACK(stop_button_clicked),
                                     "next_button_clicked", G_CALLBACK(next_button_clicked), NULL);
    gtk_builder_connect_signals(builder, NULL);

    gtk_widget_show_all(window);

    gtk_main();

    delete gameInterface;
}