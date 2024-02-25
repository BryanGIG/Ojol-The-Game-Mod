#pragma once

#include "CBaseEntry.hpp"

class User : public CBaseEntry {
public:
    const char *getAssembly() override;

    const char *getNamespace() override;

    const char *getClass() override;

    void Hook() override;

    void setCheat();

    void Initialize() override;

};