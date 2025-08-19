#include "config_manager.hpp"

ConfigManager* ConfigManager::instance = nullptr;

ConfigManager& ConfigManager::getInstance(){
    //std::lock_guard<std::mutex> lock(configMutex);
    if(!instance) 
        instance = new ConfigManager();
    return *instance;
}

bool ConfigManager::loadConfig(const std::string& filepath) {
    std::lock_guard<std::mutex> lock(configMutex);

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filepath << "\n";
        return false;
    }

    configMap.clear();
    parseConfigFile(file);
    configFilePath = filepath;
    lastModifiedTime = std::filesystem::last_write_time(filepath);

    return true;
}

void ConfigManager::parseConfigFile(std::ifstream& file) {
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            key.erase(0, key.find_first_not_of(" \t\n\r"));
            key.erase(key.find_last_not_of(" \t\n\r") + 1);
            value.erase(0, value.find_first_not_of(" \t\n\r"));
            value.erase(value.find_last_not_of(" \t\n\r") + 1);
            configMap[key] = value;
        }
    }
}

std::string ConfigManager::getValue(const std::string& key, const std::string& defaultValue) const {
    std::lock_guard<std::mutex> lock(configMutex);
    auto it = configMap.find(key);
    return (it != configMap.end()) ? it->second : defaultValue;
}

bool ConfigManager::reloadIfChanged() {
    std::lock_guard<std::mutex> lock(configMutex);

    if (configFilePath.empty())
        return false;

    auto currentModifiedTime = std::filesystem::last_write_time(configFilePath);
    if (currentModifiedTime != lastModifiedTime) {
        std::ifstream file(configFilePath);
        if (!file.is_open())
            return false;

        configMap.clear();
        parseConfigFile(file);
        lastModifiedTime = currentModifiedTime;
        std::cout << "Config reloaded from file.\n";
        return true;
    }

    return false;
}

int main()
{
    auto& config = ConfigManager::getInstance();
    if (config.loadConfig("config.txt")) {
        std::cout << "DB Host: " << config.getValue("db_host") << "\n";
        std::cout << "DB Port: " << config.getValue("db_port") << "\n";
    }

    // Simulate reloading if file changes
    config.reloadIfChanged();

    return 0;

}