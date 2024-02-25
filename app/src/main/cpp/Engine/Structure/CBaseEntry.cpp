#include "CBaseEntry.hpp"

std::mutex listMutex;
std::vector<std::shared_ptr<CBaseEntry>> list;

void ListCBaseEntry::add(const std::shared_ptr<CBaseEntry>& entry)  {
    std::lock_guard<std::mutex> guard(listMutex);
    list.push_back(entry);
}

void ListCBaseEntry::remove(const std::shared_ptr<CBaseEntry>& entry) {
    std::lock_guard<std::mutex> guard(listMutex);
    auto it = std::find(list.begin(), list.end(), entry);
    if (it != list.end()) {
        list.erase(it);
    }
}

std::vector<std::shared_ptr<CBaseEntry>> ListCBaseEntry::getList() {
    std::lock_guard<std::mutex> guard(listMutex);
    return list;  // This makes a copy of the list
}

void ListCBaseEntry::Initialize() {
    std::lock_guard<std::mutex> guard(listMutex);
    for (auto &entry : list) {
        entry->Initialize();
        entry->Hook();
    }
}