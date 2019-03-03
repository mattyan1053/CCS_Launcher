# pragma once
# include <Siv3D.hpp>
# include "ResourceLoader.hpp"

void ResourceLoader::load() {

	loadFonts();
	loadTextures();

}

void ResourceLoader::loadFonts() {

	FontAsset::Register(L"title", 45, Typeface::Black);
	FontAsset::Register(L"title2", 35, L"メイリオ", FontStyle::Outline);
	FontAsset(L"title2").changeOutlineStyle(TextOutlineStyle(Palette::White, Palette::White, 3.0));
	FontAsset::Register(L"title3", 25, L"メイリオ", FontStyle::Outline);
	FontAsset(L"title3").changeOutlineStyle(TextOutlineStyle(Palette::White, Palette::White, 2.5));
	FontAsset::Register(L"subtitle", 25, Typeface::Bold);
	FontAsset::Register(L"summary", 25, L"メイリオ", FontStyle::Bold);
	FontAsset::Register(L"button", 20, Typeface::Default);
	FontAsset::Register(L"tag", 13, L"メイリオ", FontStyle::Bold);
	FontAsset::Register(L"arrow", 50, Typeface::Black);

}

void ResourceLoader::loadTextures() {

	TextureAsset::Register(L"ccslogo", L"img/ccslogoonly.png");

}