#pragma once
#include <string>
#include <vector>

const std::string version = "1.0.0.0"; //version control

//audio files
//const std::string menuSound_path = "res/mainmenuMP3.mp3";

//images
const std::string bkgdMenu_path = "res/bkgdMenu.png";
const std::string bkgdMenuV2_path = "res/bkgdMenuV2.png";
const std::string bkgdMenuV201_path = "res/bkgdMenuV201.png";
const std::string bkgdSettingsMenu_path = "res/bkgdSettingsMenu.png";
const std::string bkgdGameMenu_path = "res/bkgdGame.png";
const std::string bkgdbtnPlay_path = "res/bkgdbtnPlay.png";
const std::string bkgdbtnReset_path = "res/bkgdbtnReset.png";
const std::string bkgdbtnCredit_path = "res/bkgdbtnCreditV2.png";
const std::string bkgdbtnHost_path = "res/bkgdbtnHostV2.png";
const std::string bkgdbtnJoin_path = "res/bkgdbtnJoin.png";
const std::string bkgdSettings_path = "res/bkgdSettingsButton.png";
const std::string bkgdQuit_path = "res/bkgdQuit.png";

const std::string icon_path = "res/icon.png";
//fonts
const std::string comicFont_path = "res/comic.ttf";

//arrayForCheck
const std::vector<std::string> arrayFiles = {
	//audio

	//fonts
	comicFont_path,

	//pics
	bkgdMenu_path,
	bkgdbtnReset_path,
	bkgdbtnCredit_path,
	bkgdGameMenu_path,

	//DLLS
	"libfreetype-6.dll",
	"libjpeg-9.dll",
	"libmpg123-0.dll",
	"libpng16-16.dll",
	"libtiff-5.dll",
	"libwebp-7.dll",
	"SDL2.dll",
	"SDL2_image.dll",
	"SDL2_mixer.dll",
	"SDL2_ttf.dll",
	"zlib1.dll"
};