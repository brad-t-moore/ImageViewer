// generated by Fast Light User Interface Designer (fluid) version 1.0010

#include "liSpineInterventionConfigurationGUI.h"

inline void SpineInterventionConfigurationGUI::cb_Load_i(Fl_Menu_*, void*) {
  m_Configuration->LoadFluoroscopy();
}
void SpineInterventionConfigurationGUI::cb_Load(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Load1_i(Fl_Menu_*, void*) {
  m_Configuration->LoadVolume();
}
void SpineInterventionConfigurationGUI::cb_Load1(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Load1_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Load2_i(Fl_Menu_*, void*) {
  m_Configuration->LoadSpineModel();
}
void SpineInterventionConfigurationGUI::cb_Load2(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Load2_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Load3_i(Fl_Menu_*, void*) {
  m_Configuration->LoadVesselsModel();
}
void SpineInterventionConfigurationGUI::cb_Load3(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Load3_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Save_i(Fl_Menu_*, void*) {
  m_Configuration->SaveSpineModel();
}
void SpineInterventionConfigurationGUI::cb_Save(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Quit_i(Fl_Menu_*, void*) {
  Hide();
}
void SpineInterventionConfigurationGUI::cb_Quit(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Room_i(Fl_Menu_*, void*) {
  m_Configuration->ShowRoomView();
}
void SpineInterventionConfigurationGUI::cb_Room(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Room_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Fluoroscopy_i(Fl_Menu_*, void*) {
  m_Configuration->ShowFluoroscopyView();
}
void SpineInterventionConfigurationGUI::cb_Fluoroscopy(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Fluoroscopy_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Volume_i(Fl_Menu_*, void*) {
  m_Configuration->ShowVolumeView();
}
void SpineInterventionConfigurationGUI::cb_Volume(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Volume_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Table_i(Fl_Menu_*, void*) {
  m_Configuration->ShowTableControls();
}
void SpineInterventionConfigurationGUI::cb_Table(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Table_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Fluoroscopy1_i(Fl_Menu_*, void*) {
  m_Configuration->ShowFluoroscopyControls();
}
void SpineInterventionConfigurationGUI::cb_Fluoroscopy1(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Fluoroscopy1_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Spine_i(Fl_Menu_*, void*) {
  m_Configuration->ShowSpineControls();
}
void SpineInterventionConfigurationGUI::cb_Spine(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Spine_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Vessels_i(Fl_Menu_*, void*) {
  m_Configuration->ShowVesselsControls();
}
void SpineInterventionConfigurationGUI::cb_Vessels(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Vessels_i(o,v);
}

inline void SpineInterventionConfigurationGUI::cb_Slicer_i(Fl_Menu_*, void*) {
  m_Configuration->ShowVolumeSlicer();
}
void SpineInterventionConfigurationGUI::cb_Slicer(Fl_Menu_* o, void* v) {
  ((SpineInterventionConfigurationGUI*)(o->parent()->user_data()))->cb_Slicer_i(o,v);
}

Fl_Menu_Item SpineInterventionConfigurationGUI::menu_[] = {
 {"File", 0,  0, 0, 64, 0, 0, 14, 0},
 {"Load Fluoroscopy", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Load, 0, 0, 0, 0, 14, 0},
 {"Load Volume", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Load1, 0, 0, 0, 0, 14, 0},
 {"Load Spine Model", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Load2, 0, 0, 0, 0, 14, 0},
 {"Load Vessels Model", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Load3, 0, 128, 0, 0, 14, 0},
 {"Save Spine Model", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Save, 0, 128, 0, 0, 14, 0},
 {"Quit", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Quit, 0, 0, 0, 0, 14, 0},
 {0},
 {"Views", 0,  0, 0, 64, 0, 0, 14, 0},
 {"Room", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Room, 0, 0, 0, 0, 14, 0},
 {"Fluoroscopy", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Fluoroscopy, 0, 0, 0, 0, 14, 0},
 {"Volume", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Volume, 0, 0, 0, 0, 14, 0},
 {0},
 {"Controls", 0,  0, 0, 64, 0, 0, 14, 0},
 {"Table", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Table, 0, 0, 0, 0, 14, 0},
 {"Fluoroscopy", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Fluoroscopy1, 0, 0, 0, 0, 14, 0},
 {"Spine Model", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Spine, 0, 0, 0, 0, 14, 0},
 {"Vessels Model", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Vessels, 0, 0, 0, 0, 14, 0},
 {"Slicer", 0,  (Fl_Callback*)SpineInterventionConfigurationGUI::cb_Slicer, 0, 0, 0, 0, 14, 0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0},
 {0}
};

SpineInterventionConfigurationGUI::SpineInterventionConfigurationGUI() {
  Fl_Window* w;
  { Fl_Window* o = controlWindow = new Fl_Window(301, 103, "Spine Intervention");
    w = o;
    o->user_data((void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(1, 2, 300, 25);
      o->menu(menu_);
    }
    o->end();
  }
}

SpineInterventionConfigurationGUI::~SpineInterventionConfigurationGUI() {
}

void SpineInterventionConfigurationGUI::Show(void) {
  controlWindow->show();
}

void SpineInterventionConfigurationGUI::Hide(void) {
  controlWindow->hide();
m_Configuration->Hide();
}

void SpineInterventionConfigurationGUI::SetConfiguration( li::SpineInterventionConfiguration * configuration ) {
  m_Configuration = configuration;
}
