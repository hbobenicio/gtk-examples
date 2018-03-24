/**
 * # glade-dialog
 * 
 * ## Description
 * 
 * A simple gtk+-3.0 example on using a glade file and GtkBuilder.
 * 
 * ## Build
 * 
 * ```
 * g++ -pedantic -Wall -std=c++14 main.cpp -o main `pkg-config --libs --cflags glib-2.0 --cflags gtk+-3.0`
 * ```
 */

#include <gtk/gtk.h>

static void on_open_button_clicked(GtkWidget* widget, gpointer user_data)
{
  g_print("Open it!\n");
}

static GtkBuilder* create_builder(const char* glade_filename)
{
  GtkBuilder* builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, glade_filename, nullptr);

  return builder;
}

static void connect_signals(GtkBuilder* builder)
{
  gtk_builder_add_callback_symbols(builder,
    "on_open_button_clicked", G_CALLBACK(on_open_button_clicked),
    // add more events/callbacks here...
    nullptr
  );

  gtk_builder_connect_signals(builder, nullptr);
}

static GtkWidget* load_main_window(const char* glade_filename)
{
  GtkBuilder* builder = create_builder(glade_filename);
  connect_signals(builder);

  GObject* main_window = gtk_builder_get_object(builder, "main_window");
  return GTK_WIDGET(main_window);
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  GtkWidget* main_window = load_main_window("dialog.glade");

  gtk_widget_show(main_window);
  gtk_main();

  return 0;
}
