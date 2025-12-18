#include "component.h"
#include "esphome/core/log.h"

namespace esphome {
namespace my_epaper_component {

static const char *TAG = "my_epaper_component";

MyEPaper::MyEPaper() 
    : display_(GxGDEH029Z13(/*CS=*/17, /*DC=*/18, /*RST=*/16, /*BUSY=*/15)) {}

void MyEPaper::setup() {
  ESP_LOGCONFIG(TAG, "Initializing e-paper display...");
  display_.init();
  display_.setRotation(0);
  display_.fillScreen(GxEPD_WHITE);
  display_.update();
}

void MyEPaper::update() {
  display();
}

void MyEPaper::fill(Color color) {
  uint16_t c = color.is_on() ? GxEPD_BLACK : GxEPD_WHITE;
  display_.fillScreen(c);
}

void MyEPaper::draw_absolute_pixel_internal(int x, int y, Color color) {
  uint16_t c = color.is_on() ? GxEPD_BLACK : GxEPD_WHITE;
  display_.drawPixel(x, y, c);
}

int MyEPaper::get_width_internal() {
  return display_.width();
}

int MyEPaper::get_height_internal() {
  return display_.height();
}

}  // namespace my_epaper_component
}  // namespace esphome
