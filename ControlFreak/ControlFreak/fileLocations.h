#pragma once
#include <string>
#include <vector>

//audio files
//const std::string menuSound_path = "res/mainmenuMP3.mp3";

//images
const std::string bkgdMenu_path = "res/bkgdMenu.png";
const std::string bkgdGameMenu_path = "res/bkgdGame.png";
const std::string bkgdbtnPlay_path = "res/bkgdbtnPlay.png";
const std::string bkgdbtnReset_path = "res/bkgdbtnReset.png";
const std::string bkgdbtnCredit_path = "res/bkgdbtnCredit.png";
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