#include "application_model.h"

// #include "playlist/playlist_manager.h"
// #include "audio/audio_manager.h"

namespace iamaprogrammer {

  ApplicationModel::ApplicationModel() {
    this->initSongDatabase();
  }

  void ApplicationModel::selectPlaylist(std::string playlist) {
    this->selectedPlaylist = playlist;
    this->notifyListeners(ApplicationModel::Events::CHANGED_SELECTED_PLAYLIST);
  }

  void ApplicationModel::selectSong(std::string playlist) {
    
  }

  std::string ApplicationModel::getSelectedPlaylist() {
    return this->selectedPlaylist;
  }

  std::string ApplicationModel::getSelectedSong() {
    return this->selectedSong;
  }


  std::vector<std::string> ApplicationModel::getPlaylists() {
    return this->audioRegistry.getTableNames();
  }

  std::vector<std::pair<std::string, std::string>> ApplicationModel::getSongs(std::string playlist) {
    std::vector<std::pair<std::string, std::string>> songs;
    TableIterator iterator = this->audioRegistry.getTableIterator(playlist);

    while (iterator.next()) {
      Row row = iterator.row();
      std::string hash = row["hash"].asString();
      std::string name = row["name"].asString();
      songs.push_back({hash, name});
    }

    return songs;
  }

  void ApplicationModel::addListener(ApplicationModel::Events event, std::function<void()> listener) {
    this->listeners[event].push_back(listener);
  }

  void ApplicationModel::notifyListeners(ApplicationModel::Events event) {
    for (std::function<void()> listener : this->listeners[event]) {
      listener();
    }
  }

  void ApplicationModel::initSongDatabase() {
    this->audioRegistry.addTable(this->audioLibraryName, &this->playlistSchema);
    std::unordered_set<std::string> musicExtensions = {".mp3", ".wav", ".flac"};

    // Iterate through library
    for (const auto& entry : std::filesystem::directory_iterator(PATH_AUDIO_LIBRARY)) {
      if (musicExtensions.find(entry.path().extension()) == musicExtensions.end()) {
        continue;
      }

      std::cout << entry.path() << std::endl;
      // Generate md5 hash for file entry
      md5_builder hashBuilder;
      std::ifstream audioFile(entry.path());
      std::vector<char> buffer(1024);

      if (!audioFile.is_open()) {
        continue;
      }

      do {
        audioFile.read(buffer.data(), 1024);
        hashBuilder.update(buffer.data(), audioFile.gcount());
      } while (audioFile.gcount() > 0);

      // Add hash to registry if not found.
      md5_hash hash = hashBuilder.finalize();
      if (!this->audioRegistry.hasEntry(this->audioLibraryName, hash.to_string())) {
        std::cout << "Song of name: " << entry.path().filename() << " with hash: " << hash.to_string() << " not found, adding it to database" << std::endl;
        this->audioRegistry.addEntry(this->audioLibraryName)
          .value(hash.to_string())
          .value(entry.path().filename());
      }
    }
  }
}