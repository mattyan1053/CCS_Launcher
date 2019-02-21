# pragma once
# include <Siv3D.hpp>
# include "ResourceLoader.hpp"

void ResourceLoader::loadFonts() {

	FontAsset::Register(L"nomal", 35, Typeface::Black);

}

void ResourceLoader::loadTextures() {

	TextureAsset::Register(L"No image", L"img/noimg.png");

}

void ResourceLoader::load() {

	loadFonts();
	loadTextures();

}