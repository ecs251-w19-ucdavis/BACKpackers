
#ifndef CORE_CONSOLE_CONTROLLER_H_
#define CORE_CONSOLE_CONTROLLER_H_

#include <jsoncpp/jsoncpp1/include/json/json.h>
#include <memory>
#include <vector>
#include <thread>

#include "Controller.h"

namespace core {

class Controller;

class ConsoleController : public Controller {
 public:
  ConsoleController();
  ConsoleController(std::shared_ptr<Dispatcher> dispatcher);
  void start(const std::string& localBackupInfoLocation);
  void start();
  void stop() { }
 private:
  std::vector<std::shared_ptr<Controller>> asyncControllers_;
  std::vector<std::shared_ptr<std::thread>> asyncControllerThreads_;
  
  void createControllers(bool deferChecking = false);
  void startAllAsync();
  void stopAllAsync();
  bool getTrackerInfo(Json::Value& configInfo);
}; // class ConsoleController

} // namespace core

#endif // CORE_CONSOLE_CONTROLLER_H_
