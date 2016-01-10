
#include "db/settings.h"

Settings::Version Settings::GetVersion() const { return version_; }

void Settings::SetVersion(const Version &version) { version_ = version; }
