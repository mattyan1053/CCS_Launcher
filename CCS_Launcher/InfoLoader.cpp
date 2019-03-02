# pragma once
# include "InfoLoader.hpp"

AppData InfoLoader::loadAppData(const FilePath& path) {

	Array<FilePath> fileList = FileSystem::DirectoryContents(path);
	AppData appData;
	bool screenshotFlag = false, infoFlag = false, readmeFlag = false;
	m_isMovieExist = false;

	Font font(10, Typeface::Default);

	for (const auto& file : fileList) {

		// screenshot�̃��[�h
		if (file.includes(L"screenshot") || file.includes(L"Screenshot") || file.includes(L"ScreenShot")) {
			appData.screenshot = Texture(file);
			screenshotFlag = true;
			continue;
		}

		// ���s�t�@�C�����A�W�������A������@�̃��[�h
		if (file.includes(L"info") || file.includes(L"Info")) {
			TextReader reader(file);
			infoFlag = true;
			reader.readLine(appData.executePath);
			reader.readLine(appData.kind);
			reader.readLine(appData.usingtext);
			continue;
		}

		// readme�̃��[�h
		if (file.includes(L"readme") || file.includes(L"readMe") || file.includes(L"Readme") || file.includes(L"ReadMe") || file.includes(L"README")) {
			// �e�L�X�g�t�@�C���ǂݍ���
			TextReader reader(file);
			String content = reader.readAll();
			readmeFlag = true;

			// �C���[�W�ϊ�
			Image contentImg;
			contentImg.resize(font.region(content).size, Palette::White);
			font.write(contentImg, content, Point::Zero, Palette::Black);
			appData.readme = Texture(contentImg);

			continue;
		}

		// �f�����[�r�[�̃��[�h
		if (file.includes(L"Demo") || file.includes(L"demo")) {
			if (file.includes(L".avi") || file.includes(L".AVI") || file.includes(L".wmv") || file.includes(L".WMV")) {
				appData.demo.open(file);
				m_isMovieExist = true;
			}
		}

	}

	// ���s�t�@�C���̃p�X�ϊ�
	appData.executePath = path + appData.executePath;

	// �ǂݍ��߂Ă��Ȃ��t�@�C��������΃f�o�b�O�\��
	if (!screenshotFlag) {
		appData.screenshot = Texture(L"img/noimg.png");
		Println(L"screenshot�����[�h�ł��܂���ł����B\n�A�v���P�[�V�������F" + FileSystem::BaseName(path));
	}

	if (!infoFlag) {
		Println(L"info�����[�h�ł��܂���ł����B\n�A�v���P�[�V�������F" + FileSystem::BaseName(path));
	}
	else {

		// ���s�t�@�C�������݂��Ȃ���΃f�o�b�O�\��
		if (!FileSystem::Exists(appData.executePath)) {
			Println(L"���s�t�@�C�������݂��܂���B <" + appData.executePath + L">");
		}

		if (appData.kind == L"" || appData.usingtext == L"") {
			Println(L"info�̓��e���s���ł��B\n�A�v���P�[�V�������F" + FileSystem::BaseName(path));
		}
	}

	if (!readmeFlag) {
		Println(L"readme�����[�h�ł��܂���ł����B\n�A�v���P�[�V�������F" + FileSystem::BaseName(path));
	}

	return appData;

}

Array<AppInfo> InfoLoader::load() {

	Array<FilePath> folderList = FileSystem::DirectoryContents(m_folderPath);
	Array<AppInfo> apps;

	// �A�v���P�[�V�������Ƃ�AppInfo���쐬���Ēǉ�
	for (unsigned int i = 0; i < folderList.size(); i++) {
		apps.push_back({ i, FileSystem::BaseName(folderList[i]), loadAppData(folderList[i]), m_isMovieExist });
	}

	return apps;

}