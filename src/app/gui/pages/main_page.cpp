#include "main_page.h"

namespace iamaprogrammer {

  MainPage::MainPage(ApplicationModel& applicationModel) : Page(applicationModel) {}

  void MainPage::init(lv_display_t* disp) {
    int32_t screen_width = lv_display_get_horizontal_resolution(disp);
    int32_t screen_height = lv_display_get_vertical_resolution(disp);

    int32_t row1_height = screen_height / 7.5;
    int32_t row2_height = screen_height - row1_height;

    this->grid_columns = {screen_width/3, screen_width/3, screen_width/3, LV_GRID_TEMPLATE_LAST};
    this->grid_rows = {row1_height, row2_height, LV_GRID_TEMPLATE_LAST};

    // Grid
    this->grid = Grid(lv_screen_active(), this->grid_columns, this->grid_rows);
    this->grid.setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
    this->grid.setStyleBgColor(lv_palette_main(LV_PALETTE_RED), 0);
    this->grid.setSize(screen_width, screen_height);
    this->grid.center();
    this->grid.updateLayout();

    // Navbar Cell
    this->navBar = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 0, 3,
      LV_GRID_ALIGN_STRETCH, 0, 1
    );
    this->navBar.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->navBar.updateLayout();

    // Playlists Cell
    this->playlists = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 0, 1,
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->playlists.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->playlists.updateLayout();

    // Songs Cell
    this->songs = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 1, 1,
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->songs.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->songs.updateLayout();

    // Song Cell
    this->song = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 2, 1,
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->song.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->song.updateLayout();

    // Playlists List
    this->playlistsList = ListWidget(this->playlists);
    // this->eventBus.subscribe(this->playlistsList, iamaprogrammer::EVENT_PLAYLIST_UPDATE, [this](LvObject& target, EventBus& eventBus, std::shared_ptr<void> data) {
    //   this->eventPlaylistUpdate(target, eventBus, data);
    // });
    //this->playlistsList.addText("Playlists");
    this->playlistsList.setSize(this->playlists.getWidth(), this->playlists.getHeight());
    this->playlistsList.center();
    this->playlistsList.updateLayout();
  
    // Songs List
    this->songsList = ListWidget(this->songs);
    this->songsList.setSize(this->songs.getWidth(), this->songs.getHeight());
    this->songsList.center();
    this->songsList.updateLayout();

    // this->state.selectedPlaylist.observe([this](const std::string& value) {
    //   TableIterator iterator = this->registry.getTableIterator(value);
    //   std::cout << "SelectedPlaylist: " << value << std::endl;

    //   while (iterator.next()) {
    //     Row row = iterator.row();
    //     std::string value = row["name"].asString();
    //     std::cout << value << std::endl;
    //     this->songsList.addButton(nullptr, value.c_str());
    //   }
    // });

    this->audioControl = AudioControlWidget(this->song);
    this->audioControl.setSize(this->song.getWidth(), this->song.getHeight());
    this->audioControl.center();


    for (std::string playlist : this->applicationModel.getPlaylists()) {
      lv_obj_t* btn = playlistsList.addButton(nullptr, playlist.c_str());

      lv_obj_add_event_cb(btn, [](lv_event_t* e) {
        ApplicationModel* model = static_cast<ApplicationModel*>(lv_event_get_user_data(e));
        lv_obj_t* target = lv_event_get_target_obj(e);
        lv_obj_t* parent = lv_obj_get_parent(target);

        model->selectPlaylist(lv_list_get_button_text(parent, target));
        //state->selectedPlaylist.setValue(lv_list_get_button_text(parent, target));

      }, LV_EVENT_CLICKED, &this->applicationModel);
    }

    this->applicationModel.addListener(ApplicationModel::Events::CHANGED_SELECTED_PLAYLIST, [this]() {
      for (std::pair<std::string, std::string> song : this->applicationModel.getSongs(this->applicationModel.getSelectedPlaylist())) {
        this->songsList.addButton(nullptr, song.second.c_str());
      }
    });

    this->applicationModel.addListener(ApplicationModel::Events::CHANGED_SELECTED_SONG, [this]() {
      
    });

    // this->playlistsList = lv_list_create(this->playlists);
    // this->eventBus.subscribe(this->playlistsList, iamaprogrammer::EVENT_PLAYLIST_UPDATE, [this](lv_obj_t* target, std::shared_ptr<void> data) {
    //   this->eventPlaylistUpdate(target, data);
    // });
    // lv_obj_set_size(this->playlistsList, lv_obj_get_width(this->playlists), lv_obj_get_height(this->playlists));
    // lv_obj_center(this->playlistsList);
    // lv_list_add_text(this->playlistsList, "Playlists");

    // this->songsList = lv_list_create(this->songs);
    // lv_obj_set_size(this->songsList, lv_obj_get_width(this->songs), lv_obj_get_height(this->songs));
    // lv_obj_center(this->songsList);

    //lv_obj_t* libraryButton = lv_list_add_btn(this->playlistsList, nullptr, "Library");
  }

  void MainPage::eventPlaylistUpdate(LvObject& target, EventBus& eventBus, std::shared_ptr<void> data) {
    std::shared_ptr<OperationListMessage<nullptr_t, std::string>> message =
      std::static_pointer_cast<OperationListMessage<nullptr_t, std::string>>(data);
    
    ListWidget list = target;

    for (const auto& entry : message->get()) {
      switch (entry.first) {
        case iamaprogrammer::MessageOperation::ADD: {
          //lv_obj_t* btn = lv_list_add_button(target, nullptr, entry.second.c_str());
          lv_obj_t* btn = list.addButton(nullptr, entry.second.c_str());

          lv_obj_add_event_cb(btn, [](lv_event_t* e) {
            MainPageState* state = static_cast<MainPageState*>(lv_event_get_user_data(e));
            lv_obj_t* target = lv_event_get_target_obj(e);
            lv_obj_t* parent = lv_obj_get_parent(target);

            state->selectedPlaylist.setValue(lv_list_get_button_text(parent, target));

          }, LV_EVENT_CLICKED, &this->state);

          break;
        }
        case iamaprogrammer::MessageOperation::REMOVE:
          
          break;
      }
    }
  }
}