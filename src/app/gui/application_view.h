#pragma once
#include <vector>
#include <map>
#include <string>
#include "pages/page.h"

namespace iamaprogrammer {
  class ApplicationView {
    public:
      ApplicationView();

      void addPage(std::string name, Page& page);
      Page& getPage(std::string pageName);

      Page& getActivePage();
      void setActivePage(std::string pageName);
    private:
      std::map<std::string, Page&> pages;
      std::string activePage;
  };
}