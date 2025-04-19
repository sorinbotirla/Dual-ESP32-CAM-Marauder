#pragma once

#ifndef configs_h

  #define configs_h

  #define POLISH_POTATO

  #define ROTATION_PORTRAIT 0
  #define ROTATION_LANDSCAPE 1

  #define TFT_MODEL_COLOR 1 // 1 - blue display, 2 - red display

  #ifndef CALIBRATION_PORTRAIT 
    #ifndef CALIBRATION_LANDSCAPE 
      #if TFT_MODEL_COLOR == 1  // blue display
        #define CALIBRATION_PORTRAIT { 233, 3539, 200, 3511, 0 }
        #define CALIBRATION_LANDSCAPE { 215, 3498, 267, 3553, 5 }
      #elif TFT_MODEL_COLOR == 2  // red display
        #define CALIBRATION_PORTRAIT { 327, 3438, 404, 3468, 4 }
        #define CALIBRATION_LANDSCAPE { 355, 3512, 293, 3458, 7 }
      #endif
    #endif
  #endif

  //// BOARD TARGETS
  #define MARAUDER_ESPCAM

  // BEGIN LED STRIP MOD CONFIG
  // change this number if you want to use a single or dual led strip mod
  #define LED_STRIP_MOD 2 // 0 - disabled, 1 - single led strip, 2 - dual led strip

  #ifdef LED_STRIP_MOD
    #if LED_STRIP_MOD == 1
      #define SINGLE_LED_STRIP
    #elif LED_STRIP_MOD == 2
      #define DUAL_LED_STRIP
    #endif
  #endif

  #ifdef DUAL_LED_STRIP
    // if you're using 2 led strips edit these values
    #define TOTAL_PIXELS 10 // total pixels used on both strips (wifi/bt strip + gps strip)
    #define FIRST_PIXEL 0 // first pixel used
    #define FIRST_PIXEL_STRIP_WIFI 0 // first pixel of the wifi/bt strip
    #define LAST_PIXEL_STRIP_WIFI 4 // last pixel of the wifi/bt strip - must not be higher than TOTAL_PIXELS
    #define FIRST_PIXEL_STRIP_GPS 5 // first pixel of the gps strip
    #define LAST_PIXEL_STRIP_GPS 9 // last pixel of the gps strip - must not be higher than TOTAL_PIXELS

    #define TOTAL_PIXELS_STRIP_WIFI LAST_PIXEL_STRIP_WIFI - FIRST_PIXEL_STRIP_WIFI
    #define TOTAL_PIXELS_STRIP_GPS LAST_PIXEL_STRIP_GPS - FIRST_PIXEL_STRIP_GPS
  #else 

    // if you're using a single led strip edit these values
    #define TOTAL_PIXELS 6 // total pixels used for the single led strip
    #define FIRST_PIXEL 0
    #define FIRST_PIXEL_STRIP_WIFI FIRST_PIXEL // first pixel of the wifi/bt strip
    #define LAST_PIXEL_STRIP_WIFI TOTAL_PIXELS // last pixel of the wifi/bt strip - must not be higher than TOTAL_PIXELS
    #define FIRST_PIXEL_STRIP_GPS FIRST_PIXEL // first pixel of the gps strip
    #define LAST_PIXEL_STRIP_GPS TOTAL_PIXELS // last pixel of the gps strip - must not be higher than TOTAL_PIXELS

    #define TOTAL_PIXELS_STRIP_WIFI LAST_PIXEL_STRIP_WIFI - FIRST_PIXEL_STRIP_WIFI
    #define TOTAL_PIXELS_STRIP_GPS LAST_PIXEL_STRIP_GPS - FIRST_PIXEL_STRIP_GPS
  #endif

  // END LED STRIP MOD CONFIG

  //// END BOARD TARGETS

  #define MARAUDER_VERSION "v2.32 Escape Edition"

  //// HARDWARE NAMES
  #define HARDWARE_NAME "Marauder ESP CAM"

  //// END HARDWARE NAMES

 //// BOARD FEATURES
  #define HAS_BATTERY
  #define HAS_BT
  #define HAS_BT_REMOTE
  #define HAS_BUTTONS
  #define HAS_NEOPIXEL_LED
  //#define HAS_PWR_MGMT
  #define HAS_SCREEN
  #define HAS_SD
  #define USE_SD
  #define HAS_TEMP_SENSOR
  #define HAS_GPS
  //// END BOARD FEATURES

  //// POWER MANAGEMENT
  #ifdef HAS_PWR_MGMT
    #include "AXP192.h"
  #endif
  //// END POWER MANAGEMENT

  //// BUTTON DEFINITIONS
  #ifdef HAS_BUTTONS
    #define L_BTN -1
    #define C_BTN 0
    #define U_BTN -1
    #define R_BTN -1
    #define D_BTN -1

    //#define HAS_L
    //#define HAS_R
    //#define HAS_U
    //#define HAS_D
    #define HAS_C

    #define L_PULL true
    #define C_PULL true
    #define U_PULL true
    #define R_PULL true
    #define D_PULL true
  #endif
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  #ifdef HAS_SCREEN
    #define TFT_MOSI 11
    #define TFT_SCLK 14
    #define TFT_CS 12
    #define TFT_DC 16
    #define TFT_RST 5
    #define TOUCH_CS 21

    #define SCREEN_CHAR_WIDTH 40
    #define HAS_ILI9341
  
    #define BANNER_TEXT_SIZE 2

    #ifndef TFT_WIDTH
      #define TFT_WIDTH 240
    #endif

    #ifndef TFT_HEIGHT
      #define TFT_HEIGHT 320
    #endif

    #define TFT_DIY
  
    #define SCREEN_WIDTH TFT_WIDTH
    #define SCREEN_HEIGHT TFT_HEIGHT
    #define HEIGHT_1 TFT_WIDTH
    #define WIDTH_1 TFT_HEIGHT
    #define STANDARD_FONT_CHAR_LIMIT (TFT_WIDTH/6) // number of characters on a single line with normal font
    #define TEXT_HEIGHT 16 // Height of text to be printed and scrolled
    #define BOT_FIXED_AREA 0 // Number of lines in bottom fixed area (lines counted from bottom of screen)
    #define TOP_FIXED_AREA 48 // Number of lines in top fixed area (lines counted from top of screen)
    #define YMAX 320 // Bottom of screen area
    #define minimum(a,b)     (((a) < (b)) ? (a) : (b))
    //#define MENU_FONT NULL
    #define MENU_FONT &FreeMono9pt7b // Winner
    //#define MENU_FONT &FreeMonoBold9pt7b
    //#define MENU_FONT &FreeSans9pt7b
    //#define MENU_FONT &FreeSansBold9pt7b
    #define BUTTON_SCREEN_LIMIT 12
    #define BUTTON_ARRAY_LEN 12
    #define STATUS_BAR_WIDTH 16
    #define LVGL_TICK_PERIOD 6

    #define FRAME_X 100
    #define FRAME_Y 64
    #define FRAME_W 120
    #define FRAME_H 50
  
    // Red zone size
    #define REDBUTTON_X FRAME_X
    #define REDBUTTON_Y FRAME_Y
    #define REDBUTTON_W (FRAME_W/2)
    #define REDBUTTON_H FRAME_H
  
    // Green zone size
    #define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
    #define GREENBUTTON_Y FRAME_Y
    #define GREENBUTTON_W (FRAME_W/2)
    #define GREENBUTTON_H FRAME_H
  
    #define STATUSBAR_COLOR 0x4A49
  
    #define KIT_LED_BUILTIN 13

    #define BANNER_TIME 100
    
    #define COMMAND_PREFIX "!"
    
    // Keypad start position, key sizes and spacing
    #define KEY_X 120 // Centre of key
    #define KEY_Y 50
    #define KEY_W 240 // Width and height
    #define KEY_H 22
    #define KEY_SPACING_X 0 // X and Y gap
    #define KEY_SPACING_Y 1
    #define KEY_TEXTSIZE 1   // Font size multiplier
    #define ICON_W 22
    #define ICON_H 22
    #define BUTTON_PADDING 22
    //#define BUTTON_ARRAY_LEN 5
  
    //// SD DEFINITIONS
    #if defined(USE_SD)
      #ifndef SD_CS
        #define SD_CS 13
      #endif
      #ifndef SD_MOSI
        #define SD_MOSI 15
      #endif
      #ifndef SD_MISO
        #define SD_MISO 22
      #endif
      #ifndef SD_SCK
        #define SD_SCK 17
      #endif
    #endif
    //// END SD DEFINITIONS
  #endif
  //// END DISPLAY DEFINITIONS

  //// SCREEN OFF STUFF
  #ifndef HAS_SCREEN
    #define TFT_WHITE 0
    #define TFT_CYAN 0
    #define TFT_BLUE 0
    #define TFT_RED 0
    #define TFT_GREEN 0
    #define TFT_GREY 0
    #define TFT_GRAY 0
    #define TFT_MAGENTA 0
    #define TFT_VIOLET 0
    #define TFT_ORANGE 0
    #define TFT_YELLOW 0
    #define STANDARD_FONT_CHAR_LIMIT 40
    #define FLASH_BUTTON -1

    #include <FS.h>
    #include <functional>
    #include <LinkedList.h>
    #include "SPIFFS.h"
    #include "Assets.h"

  #endif
  //// END SCREEN OFF STUFF

  //// MEMORY LOWER LIMIT STUFF
  // These values are in bytes
  #define MEM_LOWER_LIM 20000
  //// END MEMORY LOWER LIMIT STUFF

  //// NEOPIXEL STUFF  
  #ifdef HAS_NEOPIXEL_LED
    #define PIN 25 
  #endif
  //// END NEOPIXEL STUFF

  //// EVIL PORTAL STUFF
  #define MAX_HTML_SIZE 11400
  //// END EVIL PORTAL STUFF

  //// GPS STUFF
  #ifdef HAS_GPS
      #define GPS_SERIAL_INDEX 2
      // #define GPS_TX 4
      // #define GPS_RX 13
      #define GPS_TX 10 //FOR ESPCAM
      #define GPS_RX 9  //FOR ESPCAM
      #define mac_history_len 512
  #else
    #define mac_history_len 512
  #endif
  //// END GPS STUFF

  //// MARAUDER TITLE STUFF
  #define MARAUDER_TITLE_BYTES 13578
  //// END MARAUDER TITLE STUFF
#endif
