#include "../Includes.hpp"

User *(*BuyItem)(Finance *i, User *user, char by, int type, GameItem *gameItem);

User *new_BuyItem(Finance *i, User *user, char by, int type, GameItem *gameItem) {
    gameItem->zeroDollar();
    return BuyItem(i, user, by, type, gameItem);
}

void Finance::Initialize() {
    setPointer(BuyItem, "BuyItem", 4);
}

void Finance::Hook() {
    setHook(BuyItem, "BuyItem")
}

const char *Finance::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *Finance::getNamespace() {
    return "Controller";
}

const char *Finance::getClass() {
    return "Finance";
}

