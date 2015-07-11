#pragma once

#include "Header.h"

static class Settings
{
public:
	static int TimeBank;
	static int TimePerMove;
	static string HeroName;
	static string VillainName;
	static int FieldHeight;
	static int FieldWidth;

	static void ParseSetting (string setting, string value);

private:
	Settings ();
	~Settings ();
};

