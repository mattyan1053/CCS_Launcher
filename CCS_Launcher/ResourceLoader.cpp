# pragma once
# include <Siv3D.hpp>
# include "ResourceLoader.hpp"

void ResourceLoader::load() {

	loadFonts();
	loadTextures();

}

void ResourceLoader::loadFonts() {

	FontAsset::Register(L"title", 35, Typeface::Black);
	FontAsset::Register(L"title2", 25, Typeface::Black);
	FontAsset::Register(L"subtitle", 25, Typeface::Bold);
	FontAsset::Register(L"summary", 20, Typeface::Black);
	FontAsset::Register(L"button", 20, Typeface::Default);
	FontAsset::Register(L"tag", 13, Typeface::Default);
	FontAsset::Register(L"arrow", 50, Typeface::Black);

}

void ResourceLoader::loadTextures() {

	TextureAsset::Register(L"No image", L"img/noimg.png");
	TextureAsset::Register(L"ccslogo", L"img/ccslogoonly.png");

}