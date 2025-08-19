#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <mutex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

class ConfigManager{
public:
    static ConfigManager& getInstance();

    bool loadConfig(const std::string& filepath);
    std::string getValue(const std::string& key, const std::string& defaultValue = "") const;
    bool reloadIfChanged();  // Reloads if file modified

    // Delete copy & assignment constructors
    ConfigManager(const ConfigManager& other) = delete;
    ConfigManager& operator=(const ConfigManager& other) = delete;

private:
    static ConfigManager* instance;
    ConfigManager() = default;
    void parseConfigFile(std::ifstream& file);
    std::unordered_map<std::string, std::string> configMap;
    std::string configFilePath;
    mutable std::mutex configMutex;
    std::filesystem::file_time_type lastModifiedTime;
};

#endif // CONFIG_MANAGER_HPP