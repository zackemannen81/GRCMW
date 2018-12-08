/*
 Copyright (c) 2014 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef CONTROLLER2_H_
#define CONTROLLER2_H_

#include "defs.h"
#include "report.h"

#define DEFAULT_MAX_AXIS_VALUE MAX_AXIS_VALUE_8BITS
#define DEFAULT_REFRESH_PERIOD 11250 //=11.25ms

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int axis;
    char props;
} s_axis_props;

typedef struct {
    const char* name;
    s_axis_props axis_props;
} s_axis_name_dir;

#define AXIS_PROP_NONE     0x00
// A button (axis with 1 bit resolution).
#define AXIS_PROP_TOGGLE   0x01
// The axis has positive values only.
// May be combined with AXIS_PROP_CENTERED, to designate the positive side of a centered axis.
#define AXIS_PROP_POSITIVE 0x02
// The axis has negative values only.
// May be combined with AXIS_PROP_CENTERED, to designate the negative side of a centered axis.
#define AXIS_PROP_NEGATIVE 0x04
// The axis has a center.
// The axis has both negative and positive values if AXIS_PROP_NEGATIVE and AXIS_PROP_POSITIVE are not set.
#define AXIS_PROP_CENTERED 0x08

#define AXIS_NAME_MAX_SIZE 16

typedef struct
{
  const char name[AXIS_NAME_MAX_SIZE];
  int max_unsigned_value;
} s_axis;

typedef struct
{
  const char * name;
  unsigned short vid;
  unsigned short pid;
  struct
  {
    int min_value;
    int default_value;
  } refresh_period;
  int auth_required;
  s_axis * axes;
  struct
  {
    int nb;
    s_axis_name_dir * values;
  } axis_name_dirs;
  unsigned int (*fp_build_report)(int axis[AXIS_MAX], s_report_packet report[MAX_REPORTS]);
  void (*fp_init_report)(s_report * report);
  e_controller_axis_index activation_button;
} s_controller;

int clamp(int min, int val, int max);

const char* controller_get_name(e_controller_type type);
e_controller_type controller_get_type(const char* name);

void controller_register(e_controller_type type, s_controller * controller);

int controller_get_min_refresh_period(e_controller_type type);
int controller_get_default_refresh_period(e_controller_type type);

int controller_get_max_signed(e_controller_type, int);
int controller_get_max_unsigned(e_controller_type, int);
int controller_get_mean_unsigned(e_controller_type, int);
double controller_get_axis_scale(e_controller_type, int);

s_axis_props controller_get_axis_index_from_name(const char*);

const char* controller_get_generic_axis_name_from_index(s_axis_props axis_props);

const char* controller_get_specific_axis_name_from_index(e_controller_type type, s_axis_props axis_props);

s_axis_props controller_get_axis_index_from_specific_name(e_controller_type type, const char* name);

unsigned int controller_build_report(e_controller_type type, int axis[AXIS_MAX], s_report_packet report[MAX_REPORTS]);

void controller_init_report(e_controller_type type, s_report * report);

const char * controller_get_axis_name(e_controller_type type, e_controller_axis_index index);

int controller_get_axis_index(const char * name);

int controller_is_auth_required(e_controller_type type);

void controller_get_ids(e_controller_type type, unsigned short * vid, unsigned short * pid);

e_controller_axis_index controller_get_activation_button(e_controller_type type);

#ifdef __cplusplus
}
#endif

#endif /* CONTROLLER2_H_ */
