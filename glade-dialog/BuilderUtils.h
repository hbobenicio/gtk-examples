#ifndef BUILDER_UTILS_H
#define BUILDER_UTILS_H

#include <gtkmm.h>

class BuilderUtils
{
public:
  static Glib::RefPtr<Gtk::Builder> create(const std::string& dialogName);

  static std::unique_ptr<Gtk::Window> getMainWindow(Glib::RefPtr<Gtk::Builder> builder);

  static Gtk::Button* getButton(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring& name);
};

#endif
