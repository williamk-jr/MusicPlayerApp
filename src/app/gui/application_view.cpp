#include "application_view.h"

namespace iamaprogrammer {
  void ApplicationView::addPage(std::string name, Page& page) {
    this->pages.insert({name, page});
  }

  Page& ApplicationView::getPage(std::string pageName) {
    return this->pages.at(pageName);
  }


  Page& ApplicationView::getActivePage() {
    return this->getPage(this->activePage);
  }

  void ApplicationView::setActivePage(std::string pageName) {
    Page& page = this->getPage(pageName);
    page.setVisible(true);

    // Disable currently active page.

    this->activePage = pageName;
  }

}