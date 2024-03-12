#include "CBaseEntry.hpp"

class Finance: public CBaseEntry {
public:
    const char *getAssembly() override;

    const char *getNamespace() override;

    const char *getClass() override;

    void Hook() override;

    void Initialize() override;

};