# pragma once
# include "InfoLoader.hpp"

AppData InfoLoader::loadAppData(const FilePath& path) {

	Array<FilePath> fileList = FileSystem::DirectoryContents(path);
	AppData appData;
	m_isMovieExist = false;

	Font font(10, Typeface::Default);

	for (const auto& file : fileList) {

		// screenshotのロード
		if (file.includes(L"screenshot") || file.includes(L"Screenshot") || file.includes(L"ScreenShot")) {
			appData.screenshot = Texture(file);
			continue;
		}

		// 実行ファイル名、ジャンル、操作方法のロード
		if (file.includes(L"info") || file.includes(L"Info")) {
			TextReader reader(file);
			reader.readLine(appData.executePath);
			reader.readLine(appData.kind);
			reader.readLine(appData.usingtext);
			continue;
		}

		// readmeのロード
		if (file.includes(L"readme") || file.includes(L"readMe") || file.includes(L"Readme") || file.includes(L"ReadMe") || file.includes(L"README")) {
			// テキストファイル読み込み
			TextReader reader(file);
			String content = reader.readAll();

			// イメージ変換
			Image contentImg;
			contentImg.resize(font.region(content).size, Palette::White);
			font.write(contentImg, content, Point::Zero, Palette::Black);
			appData.readme = Texture(contentImg);

			continue;
		}

		// デモムービーのロード
		if (file.includes(L"Demo") || file.includes(L"demo")) {
			if (file.includes(L".avi") || file.includes(L".AVI") || file.includes(L".wmv") || file.includes(L".WMV")) {
				appData.demo.open(file);
				m_isMovieExist = true;
			}
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
		apps.push_back({ i, FileSystem::BaseName(folderList[i]), loadAppData(folderList[i]), m_isMovieExist });
	}

	return apps;

}