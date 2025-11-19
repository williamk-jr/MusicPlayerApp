#include "main_page.h"

namespace iamaprogrammer {

  MainPage::MainPage() {}

  void MainPage::init(lv_display_t* disp) {
    int32_t screen_width = lv_display_get_horizontal_resolution(disp);
    int32_t screen_height = lv_display_get_vertical_resolution(disp);

    int32_t row1_height = screen_height / 7.5;
    int32_t row2_height = screen_height - row1_height;

    this->grid = iamaprogrammer::Create<iamaprogrammer::Grid>(
      lv_screen_active(), 
      std::vector{screen_width/3, screen_width/3, screen_width/3, LV_GRID_TEMPLATE_LAST}, 
      std::vector{row1_height, row2_height, LV_GRID_TEMPLATE_LAST}
    );
    this->grid->setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
    this->grid->setStyleBgColor(lv_palette_main(LV_PALETTE_RED), 0);
    this->grid->setSize(screen_width, screen_height);
    this->grid->center();

    this->navBar = iamaprogrammer::Create<iamaprogrammer::GridCell>(*this->grid, 
      LV_GRID_ALIGN_STRETCH, 0, 3, 
      LV_GRID_ALIGN_STRETCH, 0, 1
    );
    std::cout << "Address: " << &this->navBar << std::endl;
    std::cout << "Width: " << this->navBar->getWidth() << std::endl;

    this->navBar->setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);

    this->playlists = iamaprogrammer::Create<iamaprogrammer::GridCell>(*this->grid, 
      LV_GRID_ALIGN_STRETCH, 0, 1, 
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->playlists->setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 1), 0);

    this->songs = iamaprogrammer::Create<iamaprogrammer::GridCell>(*this->grid, 
      LV_GRID_ALIGN_STRETCH, 1, 1, 
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->songs->setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 2), 0);

    this->song = iamaprogrammer::Create<iamaprogrammer::GridCell>(*this->grid, 
      LV_GRID_ALIGN_STRETCH, 2, 1, 
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->song->setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 3), 0);
  }
}