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

        if (Il2Cpp::Init("libil2cpp.so") == -1) {
            LOGE("ERROR");
            return;
        }

        // Initialize the classes
        ListCBaseEntry::add(std::make_shared<Account>());
        ListCBaseEntry::add(std::make_shared<Finance>());
        ListCBaseEntry::add(std::make_shared<GameItem>());
        ListCBaseEntry::add(std::make_shared<User>());
        ListCBaseEntry::Initialize();
    }).detach();
}
