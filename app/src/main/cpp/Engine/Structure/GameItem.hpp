#include "CBaseEntry.hpp"

class GameItem : public CBaseEntry {
public:
    const char *getAssembly() override;

    const char *getNamespace() override;

    const char *getClass() override;

    void Hook() override;

    void zeroDollar();

    void Initialize() override;

};