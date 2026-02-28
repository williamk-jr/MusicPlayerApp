#include "audio_manager.h"

namespace iamaprogrammer {
  AudioManager::AudioManager(std::filesystem::path& audioLibraryPath, iamaprogrammer::Registry& registry) 
    : registry(registry), audioLibraryPath(audioLibraryPath) {
    
  }

  void AudioManager::selectFromPlaylist(std::string playlist, std::string hash) {
    iamaprogrammer::Row entry = this->registry.getEntry(playlist, hash);
    std::string name = entry["name"].asString();

    if (!this->stream.isStopped()) {
      if (this->stream.isActive()) {
        this->stream.stop();
      }

      this->stream.end();
    }

    this->stream = iamaprogrammer::AudioStreamFactory::fromFile(this->audioBackend, this->audioLibraryPath / name);
  }
}