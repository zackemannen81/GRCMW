/*
 Copyright (c) 2016 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef USB_CON_H_
#define USB_CON_H_

#include <gimxcontroller/include/defs.h>

int usb_init(int usb_number, e_controller_type type);
int usb_close(int usb_number);
int usb_send_control(int usb_number, void * buf, unsigned int count);
int usb_send_interrupt_out(int usb_number, void * buf, unsigned int count);
int usb_handle_events(int unused);
int usb_poll_interrupts();
int usb_get_joystick(int usb_number);

#endif /* USB_CON_H_ */
