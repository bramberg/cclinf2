
#ifndef _MODELS_DB_SETTINGS_H_
#define _MODELS_DB_SETTINGS_H_

class Settings {
public:
  struct Version {
    int major;
    int minor;
    int release;
  };

  Version GetVersion() const;
  void SetVersion(const Version &GetVersion);

private:
  Version version_;

};


#endif // _MODELS_DB_SETTINGS_H_

