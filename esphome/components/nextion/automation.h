#pragma once
#include "esphome/core/automation.h"
#include "nextion.h"

namespace esphome {
namespace nextion {

class SleepTrigger : public Trigger<> {
 public:
  explicit SleepTrigger(Nextion *nextion) {
    nextion->add_sleep_state_callback([this]() { this->trigger(); });
  }
};

class WakeTrigger : public Trigger<> {
 public:
  explicit WakeTrigger(Nextion *nextion) {
    nextion->add_wake_state_callback([this]() { this->trigger(); });
  }
};

}  // namespace nextion
}  // namespace esphome
