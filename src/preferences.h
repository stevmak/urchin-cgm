#pragma once

#include <pebble.h>

#define PERSIST_KEY_VERSION 0
#define PERSIST_KEY_PREFERENCES_OBJECT 1

#define PREFERENCES_SCHEMA_VERSION 13

enum {
  ALIGN_LEFT,
  ALIGN_CENTER,
  ALIGN_RIGHT,
};

enum {
  BATTERY_LOC_NONE,
  BATTERY_LOC_STATUS_RIGHT,
  BATTERY_LOC_TIME_TOP_LEFT,
  BATTERY_LOC_TIME_TOP_RIGHT,
  BATTERY_LOC_TIME_BOTTOM_LEFT,
  BATTERY_LOC_TIME_BOTTOM_RIGHT,
};

enum {
  CONN_STATUS_LOC_NONE,
  CONN_STATUS_LOC_GRAPH_TOP_LEFT,
  CONN_STATUS_LOC_GRAPH_BOTTOM_LEFT,
};

enum {
  RECENCY_LOC_NONE,
  RECENCY_LOC_GRAPH_TOP_LEFT,
  RECENCY_LOC_GRAPH_BOTTOM_LEFT,
  RECENCY_LOC_STATUS_TOP_RIGHT,
  RECENCY_LOC_STATUS_BOTTOM_RIGHT,
  RECENCY_LOC_TIME_TOP_LEFT,
  RECENCY_LOC_TIME_TOP_RIGHT,
  RECENCY_LOC_TIME_BOTTOM_LEFT,
  RECENCY_LOC_TIME_BOTTOM_RIGHT,
};

enum {
  RECENCY_STYLE_SMALL_NO_CIRCLE,
  RECENCY_STYLE_MEDIUM_PIE,
  RECENCY_STYLE_MEDIUM_RING,
  RECENCY_STYLE_MEDIUM_NO_CIRCLE,
  RECENCY_STYLE_LARGE_PIE,
  RECENCY_STYLE_LARGE_RING,
  RECENCY_STYLE_LARGE_NO_CIRCLE,
};

enum {
  POINT_SHAPE_RECTANGLE,
  POINT_SHAPE_CIRCLE,
};

// The order here should match constants.PROPERTIES.
enum {
  ELEMENT_TYPE,
  ELEMENT_ENABLED,
  ELEMENT_WIDTH,
  ELEMENT_HEIGHT,
  ELEMENT_BLACK,
  ELEMENT_BOTTOM,
  ELEMENT_RIGHT,
  NUM_ELEMENT_PROPERTIES,
};

enum {
  GRAPH_ELEMENT,
  SIDEBAR_ELEMENT,
  STATUS_BAR_ELEMENT,
  TIME_AREA_ELEMENT,
  BG_ROW_ELEMENT,
  MAX_LAYOUT_ELEMENTS,
};

enum {
  COLOR_KEY_POINT_DEFAULT,
  COLOR_KEY_POINT_HIGH,
  COLOR_KEY_POINT_LOW,
  COLOR_KEY_PLOT_LINE,
  COLOR_KEY_RECENCY_CIRCLE,
  COLOR_KEY_RECENCY_TEXT,
  NUM_COLOR_KEYS,
};

enum {
  STATUS_RECENCY_FORMAT_PAREN_LEFT,
  STATUS_RECENCY_FORMAT_BRACKET_LEFT,
  STATUS_RECENCY_FORMAT_COLON_LEFT,
  STATUS_RECENCY_FORMAT_CLOSE_PAREN_LEFT,
  STATUS_RECENCY_FORMAT_PLAIN_LEFT,
  STATUS_RECENCY_FORMAT_PAREN_RIGHT,
  STATUS_RECENCY_FORMAT_BRACKET_RIGHT,
};

typedef struct __attribute__((__packed__)) ElementConfig {
  unsigned int el:3;
  uint8_t w;
  uint8_t h;
  bool black;
  bool bottom;
  bool right;
} ElementConfig;

typedef struct __attribute__((__packed__)) Preferences {
  bool mmol;
  uint16_t top_of_graph;
  uint16_t top_of_range;
  uint8_t bottom_of_range;
  uint8_t bottom_of_graph;
  uint8_t h_gridlines;
  bool battery_as_number;
  bool basal_graph;
  unsigned int basal_height:5;
  bool update_every_minute;
  unsigned int time_align:2;
  unsigned int battery_loc:3;
  unsigned int conn_status_loc:2;
  unsigned int recency_loc:4;
  unsigned int recency_style:3;
  unsigned int point_shape:2;
  unsigned int point_rect_height:5;
  unsigned int point_width:5;
  int8_t point_margin;
  unsigned int point_right_margin:5;
  bool plot_line;
  unsigned int plot_line_width:4;
  bool plot_line_is_custom_color;
  unsigned int num_elements:3;
  ElementConfig elements[MAX_LAYOUT_ELEMENTS];
  GColor colors[NUM_COLOR_KEYS];
  uint8_t status_min_recency_to_show_minutes;
  uint16_t status_max_age_minutes;
  unsigned int status_recency_format:3;
} Preferences;

void init_prefs();
void deinit_prefs();
Preferences* get_prefs();
void set_prefs(DictionaryIterator *data);
