#pragma once
# include <Siv3D.hpp>

/// <summary>
/// �A�v���P�[�V�����̃f�[�^�{��
/// </summary>
struct AppData {

	/// <summary>
	/// ���s�t�@�C���̃p�X
	/// </summary>
	FilePath executePath;

	/// <summary>
	/// �X�N���[���V���b�g��Texture
	/// </summary>
	Texture screenshot;

	/// <summary>
	/// �Q�[���W������
	/// </summary>
	String kind;

	/// <summary>
	/// ����[��
	/// </summary>
	String usingtext;

	/// <summary>
	/// readme�̓��e
	/// </summary>
	String readme;
};

/// <summary>
/// �A�v���P�[�V�������
/// </summary>
struct AppInfo {

	/// <summary>
	/// �A�v���P�[�V������ID�i�ǂݍ��ݏ��j
	/// </summary>
	unsigned int id;

	/// <summary>
	/// �A�v���P�[�V�������i�\�����j
	/// </summary>
	String name;

	/// <summary>
	/// �A�v���P�[�V�����̖{�f�[�^
	/// </summary>
	AppData appData;
};

/// <summary>
/// �V�[���J�ڂŋ��L����f�[�^
/// </summary>
struct ShereData {

	/// <summary>
	/// �I�𒆂̃A�v���P�[�V����ID
	/// </summary>
	unsigned int selectedID;

	/// <summary>
	/// �A�v���P�[�V�������̔z��
	/// </summary>
	Array<AppInfo> apps;

	/// <summary>
	/// �v���Z�X�̎��s�t���O
	/// </summary>
	Optional<ProcessInfo> process;
};