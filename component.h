#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"

// Include GxEPD2 headers
#include <GxEPD2.h>
#include <GxGDEH029Z13/GxGDEH029Z13.h>

namespace esphome {
namespace my_epaper_component {

class MyEPaper : public PollingComponent, public display::DisplayBuffer {
 public:
  MyEPaper();

  void setup() override;
  void loop() override {}
  void update() override;
  void fill(Color color) override;
  void draw_absolute_pixel_internal(int x, int y, Color color) override;

  int get_width_internal();
  int get_height_internal();

 protected:
  GxEPD2_BW<GxGDEH029Z13, GxEPD2_296> display_;  // configure display type here
};

}  // namespace my_epaper_component
}  // namespace esphome
