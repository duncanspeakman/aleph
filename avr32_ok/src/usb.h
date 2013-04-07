/* usb.h
   aleph-avr32

   USB declarations
*/
#ifndef _ALEPH_USB_H_
#define _ALEPH_USB_H_

#include "compiler.h"
#include "uhc.h"

// usb mode change callback
void usb_mode_change(bool b_host_mode);
 
// usb Vbus change callback
void usb_vbus_change(bool b_vbus_present);

// usb vbus error callback
void usb_vbus_error(void);

// usb connection callback
void usb_connection(uhc_device_t *dev, bool b_present);

// usb wakeup callback
void usb_wakeup(void);

// usb start-of-frame callback
void usb_sof(void);

// usb end-of-enumeration callback
void usb_enum(uhc_device_t *dev, uhc_enum_status_t status);

// mouse event callbacks
void hid_mouse_btn_left(bool b_state);
void hid_mouse_btn_right(bool b_state);
void hid_mouse_btn_middle(bool b_state);
void hid_mouse_move(int8_t x, int8_t y, int8_t scroll);


#endif // header guard
