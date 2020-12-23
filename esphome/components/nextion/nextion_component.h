#pragma once
#include "esphome/core/defines.h"
#include "esphome/core/color.h"
#include "nextion_base.h"
#ifdef USE_API
#include "esphome/components/api/api_server.h"
#endif
namespace esphome {
namespace nextion {
class NextionComponent;

class NextionComponent : public NextionComponentBase {
 public:
  // void set_variable_name(std::string variable_name, std::string variable_name_to_send = "");
  void update_component(bool ignore_needs_update = false);
  bool get_needs_to_send_update() { return this->needs_to_send_update_; }

  void set_background_color(Color bco);
  void set_background_pressed_color(Color bco2);
  void set_foreground_color(Color pco);
  void set_foreground_pressed_color(Color pco2);
  void set_font_id(uint8_t font_id);
  void set_visible(bool visible);

 protected:
  NextionBase *nextion_;
  bool needs_to_send_update_;

  bool bco_needs_update_ = false;
  bool bco_is_set_ = false;
  Color bco_;
  bool bco2_needs_update_ = false;
  bool bco2_is_set_ = false;
  Color bco2_;
  bool pco_needs_update_ = false;
  bool pco_is_set_ = false;
  Color pco_;
  bool pco2_needs_update_ = false;
  bool pco2_is_set_ = false;
  Color pco2_;
  uint8_t font_id_ = 0;
  bool font_id_needs_update_ = false;
  bool font_id_is_set_ = false;

  bool visible_ = true;
  bool visible_needs_update_ = false;
  bool visible_is_set_ = false;

  virtual void send_state_to_nextion() = 0;
};
}  // namespace nextion
}  // namespace esphome
