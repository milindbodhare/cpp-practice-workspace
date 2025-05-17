#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Forward declaration
class Room;

// ========== Device ==========
class Device {
    std::string name;
    bool status = false;
    std::vector<std::weak_ptr<Room>> linkedRooms;  // Weak references

public:
    Device(const std::string& name) : name(name) {}

    void turnOn() { status = true; }
    void turnOff() { status = false; }

    void linkRoom(const std::shared_ptr<Room>& room) {
        linkedRooms.push_back(room);
    }

    void info() const {
        std::cout << "  Device: " << name << " | Status: " << (status ? "ON" : "OFF") << "\n";
    }
};

// ========== Room ==========
class Room : public std::enable_shared_from_this<Room> {
    std::string name;
    std::vector<std::shared_ptr<Device>> devices;

public:
    Room(const std::string& name) : name(name) {}

    void addDevice(const std::shared_ptr<Device>& device) {
        devices.push_back(device);
        device->linkRoom(shared_from_this());  // Safe usage
    }

    void listDevices() const {
        std::cout << "Room: " << name << "\n";
        for (const auto& device : devices) {
            device->info();
        }
    }

    std::string getName() const {
        return name;
    }
};

// ========== SmartController ==========
class SmartController {
    std::vector<std::shared_ptr<Room>> rooms;

public:
    void addRoom(const std::shared_ptr<Room>& room) {
        rooms.push_back(room);
    }

    void listAllRooms() const {
        std::cout << "\n=== Smart Home Overview ===\n";
        for (const auto& room : rooms) {
            room->listDevices();
        }
    }
};

// ========== Main Function ==========
int main() {
    SmartController controller;

    // Creating rooms
    auto livingRoom = std::make_shared<Room>("Living Room");
    auto kitchen = std::make_shared<Room>("Kitchen");

    // Creating devices
    auto light = std::make_shared<Device>("Smart Light");
    auto fan = std::make_shared<Device>("Ceiling Fan");
    auto ac = std::make_shared<Device>("Air Conditioner");

    // Assigning devices to rooms
    livingRoom->addDevice(light);
    livingRoom->addDevice(fan);
    livingRoom->addDevice(ac); // shared device in both rooms

    kitchen->addDevice(ac);
    kitchen->addDevice(light);  // shared device in both rooms

    // Adding rooms to controller
    controller.addRoom(livingRoom);
    controller.addRoom(kitchen);

    // List everything
    controller.listAllRooms();

    return 0;
}
