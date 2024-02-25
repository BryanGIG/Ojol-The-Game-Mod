#include <jni.h>
#include <string>
#include <thread>
#include "Engine/Includes.hpp"

__attribute__ ((constructor))
void lib_main() {
    std::thread([]() {
        sleep(5);

        ProcMap map;
        do {
            map = KittyMemory::getElfBaseMap("libil2cpp.so");
        } while (!map.isValid() && !map.isValidELF());
        LOGI("libil2cpp.so: %08llX", map.startAddress);

        Il2Cpp::Init("libil2cpp.so");

        // Initialize the classes
        ListCBaseEntry::add(std::make_shared<Account>());
        ListCBaseEntry::add(std::make_shared<User>());
        ListCBaseEntry::Initialize();
    }).detach();
}
