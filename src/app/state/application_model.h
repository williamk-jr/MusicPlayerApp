#pragma once
#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include <map>
#include <unordered_set>

#include <libaudio/libaudio/backends/port_audio_backend.h>
#include <libaudio/libaudio/audio_stream.h>

#include "registry/src/registry/registry.h"

#include <src/app/crypt/md5.h>

// #include "playlist/playlist_manager.h"
// #include "audio/audio_manager.h"

namespace iamaprogrammer {
  class ApplicationModel {
    public:
      enum class Events {
        CHANGED_SELECTED_PLAYLIST,
        CHANGED_SELECTED_SONG
      };

      ApplicationModel();

      void selectPlaylist(std::string playlist);
      void selectSong(std::string playlist);

      std::string getSelectedPlaylist();
      std::string getSelectedSong();

      std::vector<std::string> getPlaylists();
      std::vector<std::pair<std::string, std::string>> getSongs(std::string playlist);

      void addListener(ApplicationModel::Events event, std::function<void()> listener);

      // AudioManager& getAudioManager();
      // PlaylistManager& getPlaylistManager();
      
    private:
      std::filesystem::path PATH_APP_DATA = "/etc/musicapp";
      std::filesystem::path PATH_AUDIO_LIBRARY = PATH_APP_DATA / "library";
      std::filesystem::path PATH_PLAYLISTS = PATH_APP_DATA / "playlists";
      std::filesystem::path PATH_DATA = PATH_APP_DATA / "data";

      const std::string audioLibraryName = "library";
      iamaprogrammer::Registry audioRegistry = Registry(PATH_DATA / "library.db");

      iamaprogrammer::TableSchema playlistSchema = iamaprogrammer::TableBuilder()
        .column("hash", RegistryType::stringType())
        .column("name", RegistryType::stringType())
        .finish();

      iamaprogrammer::PortAudioBackend audioBackend;
      iamaprogrammer::AudioStream stream;

      std::string selectedPlaylist;
      std::string selectedSong;

      std::map<ApplicationModel::Events, std::vector<std::function<void()>>> listeners;

      void notifyListeners(ApplicationModel::Events event);
      void initSongDatabase();
  };
}