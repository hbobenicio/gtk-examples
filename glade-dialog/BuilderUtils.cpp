#include "BuilderUtils.h"

#include <iostream>

Glib::RefPtr<Gtk::Builder> BuilderUtils::create(const std::string& dialogName)
{
  auto builder = Gtk::Builder::create();

  try
  {
    builder->add_from_file(dialogName);
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << '\n';
    exit(1);
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << '\n';
    exit(1);
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << '\n';
    exit(1);
  }

  return builder;
}

std::unique_ptr<Gtk::Window> BuilderUtils::getMainWindow(Glib::RefPtr<Gtk::Builder> builder)
{
  Gtk::Window* mainWindow = nullptr;
  builder->get_widget("main_window", mainWindow);

  if(!mainWindow) {
    std::cerr << "Couldn't get Main Window.\n";
    exit(1);
  }

  return std::unique_ptr<Gtk::Window>{mainWindow};
}

Gtk::Button* BuilderUtils::getButton(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring& name)
{
  Gtk::Button* openButton = nullptr;
  builder->get_widget(name, openButton);

  if (!openButton) {
    std::cerr << "Couldn't get Open Button.\n";
    exit(1);
  }

  return openButton;
}
