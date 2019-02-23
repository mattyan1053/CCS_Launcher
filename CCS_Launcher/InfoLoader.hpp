# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

/// <summary>
/// �f�B���N�g�����A�v���P�[�V�������
/// </summary>
class InfoLoader {

private:

	/// <summary>
	/// �����擾����f�B���N�g���̃p�X
	/// </summary>
	FilePath m_folderPath;

	/// <summary>
	/// �f�����[�r�[���݃t���O
	/// </summary>
	bool m_isMovieExist;

	/// <summary>
	/// �A�v���P�[�V�����̏����擾���܂��B
	/// </summary>
	/// <param name = "path">
	/// �����擾����A�v���P�[�V�����̃f�B���N�g��
	/// </param>
	/// <returns>
	/// �ǂݎ�����A�v���P�[�V�������(AppData�^)
	/// </returns>
	AppData loadAppData(const FilePath& path);

public:

	/// <summary>
	/// �R���X�g���N�^
	/// �󂯎�����p�X��o�^���܂��B
	/// </summary>
	/// <param name="path">
	/// �o�^����f�B���N�g���̃p�X
	/// </param>
	InfoLoader(const FilePath& path) : m_folderPath(path) {};

	/// <summary>
	/// �f�B���N�g�����̃A�v���P�[�V�������ꗗ���擾���܂��B
	/// </summary>
	/// <returns>
	/// �f�B���N�g�����̃A�v���P�[�V�������(AppInfo)�̔z��
	/// </returns>
	Array<AppInfo> load();

};