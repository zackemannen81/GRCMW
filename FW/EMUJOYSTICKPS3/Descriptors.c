/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
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
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */

#include "../EMUJOYSTICKPS3/Descriptors.h"

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */
//USB_Descriptor_HIDReport_Datatype_t PROGMEM JoystickReport[] =
//{
//	0x05, 0x01,          /* Usage Page (Generic Desktop)                       */
//	0x09, 0x04,          /* Usage (Joystick)                                   */
//	0xa1, 0x01,          /* Collection (Application)                           */
//	0xa1, 0x02,          /*   Collection (Logical)                             */
//  0x15, 0x00,          /*     Logical Minimum (0)                            */
//  0x25, 0x01,          /*     Logical Maximum (1)                            */
//  0x75, 0x01,          /*     Report Size (1)                                */
//  0x95, 0x13,          /*     Report Count (19)                              */
//  0x05, 0x09,          /*     Usage Page (Button)                            */
//  0x19, 0x01,          /*     Usage Minimum (Button 1)                       */
//  0x29, 0x13,          /*     Usage Maximum (Button 19)                      */
//  0x81, 0x02,          /*     Input (Data, Variable, Absolute)               */
//  0x75, 0x05,          /*     Report Size (5)                                */
//  0x95, 0x01,          /*     Report Count (1)                               */
//  0x05, 0xFF,          /*     Usage Page (null)                              */
//  0x81, 0x01,          /*     Input (Constant)                               */
//	0x15, 0x00,          /*     Logical Minimum (0)                            */
//	0x25, 0xFF,          /*     Logical Maximum (255)                          */
//  0x05, 0x01,          /*     Usage Page (Generic Desktop Controls)          */
//	0x75, 0x08,          /*     Report Size (8)                                */
//  0x95, 0x02,          /*     Report Count (2)                               */
//  0x09, 0x30,          /*     Usage (X)                                      */
//  0x09, 0x31,          /*     Usage (Y)                                      */
//  0x81, 0x82,          /*     Input (Data, Variable, Absolute, Volatile)     */
//	0x15, 0x00,          /*     Logical Minimum (0)                            */
//  0x26, 0xFF, 0x0F,    /*     Logical Maximum (4095)                         */
//  0x05, 0x01,          /*     Usage Page (Generic Desktop Controls)          */
//  0x75, 0x0C,          /*     Report Size (12)                               */
//  0x95, 0x02,          /*     Report Count (2)                               */
//  0x09, 0x32,          /*     Usage (Z)                                      */
//  0x09, 0x35,          /*     Usage (Rz)                                     */
//  0x81, 0x82,          /*     Input (Data, Variable, Absolute, Volatile)     */
//	0xc0,                /*   End Collection                                   */
//	0xc0                 /* End Collection                                     */
//};
const USB_Descriptor_HIDReport_Datatype_t PROGMEM JoystickReport[] =
{
  0x05, 0x01,          /* Usage Page (Generic Desktop)                       */
  0x09, 0x04,          /* Usage (Joystick)                                   */
  0xa1, 0x01,          /* Collection (Application)                           */
  0xa1, 0x02,          /*   Collection (Logical)                             */
  0x15, 0x00,          /*     Logical Minimum (0)                            */
  0x26, 0xFF, 0xFF,    /*     Logical Maximum (65535)                        */
  0x75, 0x10,          /*     Report Size (16)                               */
  0x95, 0x04,          /*     Report Count (4)                               */
  0x09, 0x30,          /*     Usage (X)                                      */
  0x09, 0x31,          /*     Usage (Y)                                      */
  0x09, 0x32,          /*     Usage (Z)                                      */
  0x09, 0x35,          /*     Usage (Rz)                                     */
  0x81, 0x82,          /*     Input (Data, Variable, Absolute, Volatile)     */
  0x25, 0x07,          /*     Logical Maximum (7)                            */
  0x46, 0x3B, 0x01,    /*     Physical Maximum (315)                         */
  0x75, 0x04,          /*     Report Size (4)                                */
  0x95, 0x01,          /*     Report Count (1)                               */
  0x65, 0x14,          /*     Unit (Eng Rot: Degree)                         */
  0x09, 0x39,          /*     Usage (Hat Switch)                             */
  0x81, 0x42,          /*     Input (Data,Var,Abs,NWrp,Lin,Pref,Null,Bit)    */
  0x75, 0x04,          /*     Report Size (4)                                */
  0x95, 0x01,          /*     Report Count (1)                               */
  0x05, 0xFF,          /*     Usage Page (null)                              */
  0x81, 0x01,          /*     Input (Constant)                               */
  0x75, 0x08,          /*     Report Size (8)                                */
  0x95, 0x01,          /*     Report Count (1)                               */
  0x05, 0xFF,          /*     Usage Page (null)                              */
  0x81, 0x01,          /*     Input (Constant)                               */
  0x15, 0x00,          /*     Logical Minimum (0)                            */
  0x25, 0x01,          /*     Logical Maximum (1)                            */
  0x75, 0x01,          /*     Report Size (1)                                */
  0x95, 0x0D,          /*     Report Count (13)                              */
  0x05, 0x09,          /*     Usage Page (Button)                            */
  0x19, 0x01,          /*     Usage Minimum (Button 1)                       */
  0x29, 0x0D,          /*     Usage Maximum (Button 13)                      */
  0x81, 0x02,          /*     Input (Data, Variable, Absolute)               */
  0x75, 0x03,          /*     Report Size (3)                                */
  0x95, 0x01,          /*     Report Count (1)                               */
  0x05, 0xFF,          /*     Usage Page (null)                              */
  0x81, 0x01,          /*     Input (Constant)                               */
  // Begin PS3 vendor page - Thanks UnoJoy!
//  0x75, 0x08, // Report Size (8)
//  0x06, 0x00, 0xff, // USAGE_PAGE (Vendor Specific)
//  0x09, 0x20, // Unknown
//  0x09, 0x21, // Unknown
//  0x09, 0x22, // Unknown
//  0x09, 0x23, // Unknown
//  0x09, 0x24, // Unknown
//  0x09, 0x25, // Unknown
//  0x09, 0x26, // Unknown
//  0x09, 0x27, // Unknown
//  0x09, 0x28, // Unknown
//  0x09, 0x29, // Unknown
//  0x09, 0x2a, // Unknown
//  0x09, 0x2b, // Unknown
//  0x95, 0x0c, // REPORT_COUNT (12)
//  0x81, 0x02, // INPUT (Data,Var,Abs)
//  0x0a, 0x21, 0x26, // Unknown
//  0x95, 0x08, // REPORT_COUNT (8)
//  0xb1, 0x02, // FEATURE (Data,Var,Abs)*/
  0xc0,                /*   End Collection                                   */
  0xc0                 /* End Collection                                     */
};

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = VERSION_BCD(01.10),
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

	.VendorID               = 0x03EB,
	.ProductID              = 0x2043,
	.ReleaseNumber          = VERSION_BCD(00.01),

	.ManufacturerStrIndex   = 0x01,
	.ProductStrIndex        = 0x02,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
			.TotalInterfaces        = 1,

			.ConfigurationNumber    = 1,
			.ConfigurationStrIndex  = NO_DESCRIPTOR,

			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED),

			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
		},

	.HID_Interface =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

			.InterfaceNumber        = 0x00,
			.AlternateSetting       = 0x00,

			.TotalEndpoints         = 1,

			.Class                  = HID_CSCP_HIDClass,
			.SubClass               = HID_CSCP_NonBootSubclass,
			.Protocol               = HID_CSCP_NonBootProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},

	.HID_JoystickHID =
		{
			.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

			.HIDSpec                = VERSION_BCD(01.11),
			.CountryCode            = 0x00,
			.TotalReportDescriptors = 1,
			.HIDReportType          = HID_DTYPE_Report,
			.HIDReportLength        = sizeof(JoystickReport)
		},

	.HID_ReportINEndpoint =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

			.EndpointAddress        = IN_EPNUM,
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
			.EndpointSize           = EPSIZE,
			.PollingIntervalMS      = 0x01
		}
};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

	.UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the manufacturer's details in human readable
 *  form, and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ManufacturerString =
{
	.Header                 = {.Size = USB_STRING_LEN(11), .Type = DTYPE_String},

	.UnicodeString          = L"Dean Camera"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductString =
{
	.Header                 = {.Size = USB_STRING_LEN(18), .Type = DTYPE_String},

	.UnicodeString          = L"LUFA Joystick Demo"
};

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);

	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case 0x00:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case 0x01:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case 0x02:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
			}

			break;
		case DTYPE_HID:
			Address = &ConfigurationDescriptor.HID_JoystickHID;
			Size    = sizeof(USB_HID_Descriptor_HID_t);
			break;
		case DTYPE_Report:
			Address = &JoystickReport;
			Size    = sizeof(JoystickReport);
			break;
	}

	*DescriptorAddress = Address;
	return Size;
}

