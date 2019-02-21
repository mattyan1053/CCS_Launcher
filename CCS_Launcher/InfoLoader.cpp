# pragma once
# include "InfoLoader.hpp"

InfoLoader::InfoLoader(const FilePath& path) : m_folderPath(path) {

}

AppData InfoLoader::loadAppData(const FilePath& path) {

	Array<FilePath> fileList = FileSystem::DirectoryContents(path);

	AppData appData;

	for (const auto& file : fileList) {
		if (file.includes(L"screenshot")) {
			appData.screenshot = Texture(file);
			continue;
		}
		if (file.includes(L"info")) {
			TextReader reader(file);
			reader.readLine(appData.executePath);
			reader.readLine(appData.kind);
			reader.readLine(appData.usingtext);
			continue;
		}
		if (file.includes(L"readme") || file.includes(L"readMe") || file.includes(L"Readme") || file.includes(L"ReadMe")) {
			TextReader reader(file);
			appData.readme = reader.readAll();
			continue;
		}
	}

	appData.executePath = path + appData.executePath;

	return appData;

}

Array<AppInfo> InfoLoader::Load() {

	Array<FilePath> folderList = FileSystem::DirectoryContents(m_folderPath);

	Array<AppInfo> apps;

	for (unsigned int i = 0; i < folderList.size(); i++) {
		apps.push_back({i, FileSystem::BaseName(folderList[i]), loadAppData(folderList[i])});
	}

	return apps;

}