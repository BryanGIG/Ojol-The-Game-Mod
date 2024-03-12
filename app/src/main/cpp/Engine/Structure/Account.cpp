#include "../Includes.hpp"

User *(*LoadUser)(Account *);

User *new_LoadUser(Account *account) {
    User *user = LoadUser(account);
    LOGI("Patch User::setCheat()");
    user->setCheat();
    return user;
}

void Account::Initialize() {
    setPointer(LoadUser, "LoadUser", 0);
}
void Account::Hook() {
    setHook(LoadUser, "LoadUser")
}

const char *Account::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *Account::getNamespace() {
    return "Controller";
}

const char *Account::getClass() {
    return "Account";
}
