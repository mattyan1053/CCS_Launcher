#pragma once
# include <Siv3D.hpp>

// アプリケーションのデータ
struct AppData {
	FilePath executePath;
	Texture screenshot;
	String kind;
	String usingtext;
	String readme;
};

// アプリケーションの情報
struct AppInfo {
	unsigned int id;
	String name;
	AppData appData;
};