#include "../Includes.hpp"
#include "User.hpp"

uintptr_t Money;
uintptr_t Coin;
uintptr_t Energy;

void User::setCheat() {
    Il2Cpp::SetField(this, Money, 1000000.f);
    Il2Cpp::SetField(this, Coin, 1000000.f);
    Il2Cpp::SetField(this, Energy, 1000000.f);
}

void User::Initialize() {
    setFieldOffset(Money, "Money");
    setFieldOffset(Coin, "Coin");
    setFieldOffset(Energy, "Energy");
}

const char *User::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *User::getNamespace() {
    return "Model.Account";
}

const char *User::getClass() {
    return "User";
}

void User::Hook() {

}
