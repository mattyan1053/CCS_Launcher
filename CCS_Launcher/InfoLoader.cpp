# pragma once
# include "InfoLoader.hpp"

AppData InfoLoader::loadAppData(const FilePath& path) {

	Array<FilePath> fileList = FileSystem::DirectoryContents(path);
	AppData appData;

	for (const auto& file : fileList) {

		// screenshot�̃��[�h
		if (file.includes(L"screenshot")) {
			appData.screenshot = Texture(file);
			continue;
		}

		// ���s�t�@�C�����A�W�������A������@�̃��[�h
		if (file.includes(L"info")) {
			TextReader reader(file);
			reader.readLine(appData.executePath);
			reader.readLine(appData.kind);
			reader.readLine(appData.usingtext);
			continue;
		}

		// readme�̃��[�h
		if (file.includes(L"readme") || file.includes(L"readMe") || file.includes(L"Readme") || file.includes(L"ReadMe")) {
			TextReader reader(file);
			appData.readme = reader.readAll();
			continue;
		}

	}

	// ���s�t�@�C���̃p�X�ϊ�
	appData.executePath = path + appData.executePath;

	return appData;

}

Array<AppInfo> InfoLoader::load() {

	Array<FilePath> folderList = FileSystem::DirectoryContents(m_folderPath);
	Array<AppInfo> apps;

	// �A�v���P�[�V�������Ƃ�AppInfo���쐬���Ēǉ�
	for (unsigned int i = 0; i < folderList.size(); i++) {
		apps.push_back({i, FileSystem::BaseName(folderList[i]), loadAppData(folderList[i])});
	}

	return apps;

}