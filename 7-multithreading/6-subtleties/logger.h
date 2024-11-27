// OTUS C++ Basic course
// MT logger example

#pragma once

#include <chrono>
#include <ctime>
#include <fstream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <iostream>
#include <iomanip>

class Logger {
  public:
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    void log(const std::string &msg) {
        std::lock_guard lock{mtx_};
        std::time_t now = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        logfile_ << std::put_time(std::localtime(&now), "%c %Z")
                 << " TID:" << std::this_thread::get_id() << " " << msg
                 << std::endl;
    }
    static Logger &getLogger() {
        static std::once_flag flag_;
        std::call_once(flag_,
                       [&]() { instance_.reset(new Logger("example.log")); });
        return *instance_;
    }

  private:
    Logger(const std::string &logpath) : logfile_{logpath, std::ios_base::app} {
        if (!logfile_.is_open()) {
            throw std::runtime_error{"Failed to open '" + logpath + "'"};
        }
    }
    inline static std::unique_ptr<Logger> instance_ = nullptr;
    std::mutex mtx_;
    std::ofstream logfile_;
};
