// generated by Fast Light User Interface Designer (fluid) version 1.0010

#include "liFluoroscopyUnitViewGUI.h"

FluoroscopyUnitViewGUI::FluoroscopyUnitViewGUI() {
  Fl_Window* w;
  { Fl_Window* o = ViewWindow = new Fl_Window(490, 460, "Fluoroscopy View");
    w = o;
    o->user_data((void*)(this));
    { li::FluoroscopyUnitView* o = fluoroscopyUnitViewWindow = new li::FluoroscopyUnitView(5, 10, 480, 440);
      Fl_Group::current()->resizable(o);
    }
    o->end();
  }
}

FluoroscopyUnitViewGUI::~FluoroscopyUnitViewGUI() {
}

void FluoroscopyUnitViewGUI::Show(void) {
  ViewWindow->show();
fluoroscopyUnitViewWindow->show();
}

void FluoroscopyUnitViewGUI::Hide(void) {
  ViewWindow->hide();
}

fltk::GlWindow * FluoroscopyUnitViewGUI::GetWindow(void) {
  return fluoroscopyUnitViewWindow;
}

void FluoroscopyUnitViewGUI::SetFluoroscopyImage( const li::FluoroscopyUnitView::ImageType * image ) {
  fluoroscopyUnitViewWindow->SetFluoroscopyImage( image );
}

fltk::GlWindow::RedrawCommandType::Pointer FluoroscopyUnitViewGUI::GetRedrawCommand(void) {
  return fluoroscopyUnitViewWindow->GetRedrawCommand();
}
