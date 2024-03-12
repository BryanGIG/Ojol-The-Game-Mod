#include "../Includes.hpp"

uintptr_t priceMoney;
uintptr_t priceCoin;

void GameItem::zeroDollar() {
    Il2Cpp::SetField(this, priceMoney, 0);
    Il2Cpp::SetField(this, priceCoin, 0);
}

void GameItem::Hook() {

}

void GameItem::Initialize() {
    setFieldOffset(priceMoney, "priceMoney");
    setFieldOffset(priceCoin, "priceCoin");
}

const char *GameItem::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *GameItem::getNamespace() {
    return "";
}

const char *GameItem::getClass() {
    return "GameItem";
}