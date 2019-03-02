# pragma once
# include <Siv3D.hpp>
# include "ResourceLoader.hpp"

void ResourceLoader::load() {

	loadFonts();
	loadTextures();

}

void ResourceLoader::loadFonts() {

	FontAsset::Register(L"title", 45, Typeface::Black);
	FontAsset::Register(L"title2", 35, Typeface::Black);
	FontAsset::Register(L"title3", 25, Typeface::Black);
	FontAsset::Register(L"subtitle", 25, Typeface::Bold);
	FontAsset::Register(L"summary", 25, Typeface::Black);
	FontAsset::Register(L"button", 20, Typeface::Default);
	FontAsset::Register(L"tag", 13, Typeface::Default);
	FontAsset::Register(L"arrow", 50, Typeface::Black);
	FontAsset::Register(L"appname", 20, Typeface::Black, FontStyle::Outline);
	FontAsset(L"appname").changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 1.0));

}

void ResourceLoader::loadTextures() {

	TextureAsset::Register(L"ccslogo", L"img/ccslogoonly.png");

}