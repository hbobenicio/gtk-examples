/**
 * # glade-dialog
 * 
 * ## Description
 * 
 * A simple gtkmm-3.0 example on using a glade file and GtkBuilder.
 * 
 * ## Build
 * 
 * ```
 * g++ -Wall -pedantic -g -O0 -c BuilderUtils.cpp `pkg-config gtkmm-3.0 --cflags` -std=c++14
 * g++ -Wall -pedantic -g -O0 BuilderUtils.o main1.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs` -std=c++14
 * ```
 */
#include <gtkmm.h>
#include <iostream>
#include <memory>

#include "BuilderUtils.h"

static void on_open_button_clicked() {
  std::cout << "Open it!\n";
}

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "hbobenicio.examples.gtk-examples");
  auto builder = BuilderUtils::create("dialog.glade");

  // Top-level Windows from Gtk::Builder should be deallocated (the owner is the caller)
  std::unique_ptr<Gtk::Window> mainWindow = BuilderUtils::getMainWindow(builder);

  // Other widgets from Gtk::Builder are destroyed when the Gtk::Builder is destroyed (the owner is the Gtk::Builder)
  // So, this weak reference should not live longer than the builder lifecycle.
  Gtk::Button* openButton = BuilderUtils::getButton(builder, "open_button");
  
  openButton->signal_clicked().connect(sigc::ptr_fun(on_open_button_clicked));

  return app->run(*mainWindow);
}
