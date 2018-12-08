/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2010  Dean Camera (dean [at] fourwalledcubicle [dot] com)
	  
  Permission to use, copy, modify, distribute, and sell this 
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in 
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting 
  documentation, and that the name of the author not be used in 
  advertising or publicity pertaining to distribution of the 
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

	/* Includes: */
		#include "LUFA/Drivers/USB/USB.h"

		#include <avr/pgmspace.h>

	/* Type Defines: */
		/** Type define for the device configuration descriptor structure. This must be defined in the
		 *  application code, as the configuration descriptor contains several sub-descriptors which
		 *  vary between devices, and which describe the device's usage to the host.
		 */
		typedef struct
		{
			USB_Descriptor_Configuration_Header_t Config;

			USB_Descriptor_Interface_t            Interface00;
      USB_Descriptor_Endpoint_t             I00ReportOUTEndpoint;
      USB_Descriptor_Endpoint_t             I00ReportINEndpoint;

      USB_Descriptor_Interface_t            Interface10;
      USB_Descriptor_Interface_t            Interface11;
      USB_Descriptor_Endpoint_t             I11ReportOUTEndpoint;
      USB_Descriptor_Endpoint_t             I11ReportINEndpoint;

      USB_Descriptor_Interface_t            Interface20;
      USB_Descriptor_Interface_t            Interface21;
      USB_Descriptor_Endpoint_t             I21ReportOUTEndpoint;
      USB_Descriptor_Endpoint_t             I21ReportINEndpoint;

		} USB_Descriptor_Configuration_t;

	/* Macros: */

    #define I00_OUT_EPNUM              (ENDPOINT_DIR_OUT | 2)
    #define I00_IN_EPNUM               (ENDPOINT_DIR_IN  | 2)

    #define I11_OUT_EPNUM              (ENDPOINT_DIR_OUT | 3)
    #define I11_IN_EPNUM               (ENDPOINT_DIR_IN  | 3)

    #define I21_OUT_EPNUM              (ENDPOINT_DIR_OUT | 4)
    #define I21_IN_EPNUM               (ENDPOINT_DIR_IN  | 4)
    
		#define INTERRUPT_EPSIZE              64
    #define ISOCHRONOUS_EPSIZE           64
    #define BULK_EPSIZE                   64

#endif
