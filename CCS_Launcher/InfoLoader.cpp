# pragma once
# include "InfoLoader.hpp"

AppData InfoLoader::loadAppData(const FilePath& path) {

	Array<FilePath> fileList = FileSystem::DirectoryContents(path);
	AppData appData;

	for (const auto& file : fileList) {

		// screenshotのロード
		if (file.includes(L"screenshot")) {
			appData.screenshot = Texture(file);
			continue;
		}

		// 実行ファイル名、ジャンル、操作方法のロード
		if (file.includes(L"info")) {
			TextReader reader(file);
			reader.readLine(appData.executePath);
			reader.readLine(appData.kind);
			reader.readLine(appData.usingtext);
			continue;
		}

		// readmeのロード
		if (file.includes(L"readme") || file.includes(L"readMe") || file.includes(L"Readme") || file.includes(L"ReadMe")) {
			TextReader reader(file);
			appData.readme = reader.readAll();
			continue;
		}

	}

	// 実行ファイルのパス変換
	appData.executePath = path + appData.executePath;

	return appData;

}

Array<AppInfo> InfoLoader::load() {

	Array<FilePath> folderList = FileSystem::DirectoryContents(m_folderPath);
	Array<AppInfo> apps;

	// アプリケーションごとにAppInfoを作成して追加
	for (unsigned int i = 0; i < folderList.size(); i++) {
		apps.push_back({i, FileSystem::BaseName(folderList[i]), loadAppData(folderList[i])});
	}

	return apps;

}