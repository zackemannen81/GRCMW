/*
 Copyright (c) 2010 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <gimxinput/include/ginput.h>
#include <gimxcontroller/include/controller.h>
#include <haptic/haptic_core.h>

#define MAX_BUFFERSIZE 256

typedef enum
{
  E_MOUSE_MODE_AIMING = 0, //default mode
  E_MOUSE_MODE_DRIVING
}e_mouse_mode;

typedef enum
{
  E_DEVICE_TYPE_UNKNOWN,
  E_DEVICE_TYPE_KEYBOARD,
  E_DEVICE_TYPE_MOUSE,
  E_DEVICE_TYPE_JOYSTICK,
  E_DEVICE_TYPE_NB = E_DEVICE_TYPE_JOYSTICK
}e_device_type;

typedef enum
{
  E_EVENT_TYPE_UNKNOWN,
  E_EVENT_TYPE_BUTTON,
  E_EVENT_TYPE_AXIS,
  E_EVENT_TYPE_AXIS_DOWN,
  E_EVENT_TYPE_AXIS_UP
}e_event_type;

typedef enum
{
    E_SHAPE_CIRCLE,
    E_SHAPE_RECTANGLE
}e_shape;

typedef struct
{
  double x;
  double y;
}s_vector;

typedef struct
{
  int change;
  int changed;
  s_vector merge[MAX_BUFFERSIZE];
  int index;
  s_vector motion;
  s_vector residue;
  int postpone[GE_MOUSE_BUTTONS_MAX];
}s_mouse_control;

typedef struct
{
  unsigned int buffer_size;
  double filter;
  e_mouse_mode mode;
}s_mouse_options;

typedef struct
{
  int axis;
  int coef[4];
} s_js_corr;

typedef struct
{
  double* mx;
  double* my;
  double* ex;
  double* ey;
  int rd;
  int vel;
  int* dzx;
  int* dzy;
  e_shape* dzs;
  s_mouse_options options;
  unsigned int dpi;
}s_mouse_cal;

typedef struct _mapper
{
  int button;
  int axis;
  int threshold;
  double multiplier;
  double exponent;
  e_shape shape;
  int dead_zone;

  s_axis_props axis_props;

  // if the mapper destination is a stick axis,
  // this indicates the mapper for the other axis of the stick
  struct _mapper * other;
}s_mapper;

typedef struct
{
  int nb_mappers;
  s_mapper* mappers;
} s_mapper_table;

typedef struct
{
  unsigned int controller_id;
  unsigned int profile_id;
  struct
  {
    e_device_type type;
    int id;
  } device;
  struct
  {
    e_event_type type;
    int id;
  } event;
  union
  {
    s_mapper mapper;
    struct
    {
      int switch_back;
      int delay;
    } trigger;
    s_mouse_options mouse_options;
    s_js_corr joystick_correction;
    struct
    {
      int invert;
      struct
      {
        int rumble;
        int constant;
        int spring;
        int damper;
      } gain;
    } ffb_tweaks;
  } params;
}s_config_entry;

typedef struct
{
  struct
  {
    struct
    {
      int type;
      int id;
    } device;
    int button; // -1 means no down button
  } down;
  struct
  {
    struct
    {
      int type;
      int id;
    } device;
    int button; // -1 means no up button
  } up;
  struct
  {
    unsigned int dead_zone;
    e_shape shape;
    unsigned int steps;
  } params;
  double value;
  double max_value;
  double step;
  double dead_zone;
}s_intensity;

void cfg_trigger_init();
void cfg_trigger_lookup(GE_Event*);
void cfg_profile_activation();
void cfg_intensity_lookup(GE_Event*);
void cfg_process_event(GE_Event*);
s_mouse_control* cfg_get_mouse_control(int);
void cfg_process_rumble_event(GE_Event* event);
void cfg_process_rumble();
int cfg_is_joystick_used(int);
void cfg_process_motion_event(GE_Event*);
void cfg_process_motion();
void cfg_set_trigger(s_config_entry* entry);
void cfg_set_controller_dpi(int controller, unsigned int dpi);
void cfg_set_axis_intensity(s_config_entry* entry, int axis, s_intensity* intensity);
void cfg_intensity_init();
int cfg_add_binding(s_config_entry* entry);
s_mapper_table* cfg_get_mouse_axes(int, int, int);
void cfg_clean();
void cfg_read_calibration();
int cfg_add_js_corr(int joystick, s_js_corr * corr);
void cfg_set_ffb_tweaks(const s_config_entry * entry);
const s_haptic_core_tweaks * cfg_get_ffb_tweaks(int controller);
void cfg_init_ffb_tweaks();
void cfg_pair_mouse_mappers();
void cfg_set_profile(int controller, int profile);

#endif /* CONFIG_H_ */
