#pragma once
# include <Siv3D.hpp>

// �A�v���P�[�V�����̃f�[�^
struct AppData {
	FilePath executePath;
	Texture screenshot;
	String kind;
	String usingtext;
	String readme;
};

// �A�v���P�[�V�����̏��
struct AppInfo {
	unsigned int id;
	String name;
	AppData appData;
};