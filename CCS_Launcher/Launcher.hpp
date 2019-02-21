# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "Defines.hpp"
# include "InfoLoader.hpp"
# include "Select.hpp"
# include "Detail.hpp"

/// <summary>
/// �����`���[�{�̑����N���X
/// </summary>
class Launcher {
private:

	/// <summary>
	/// �V�[���J�ڃ}�l�[�W���[
	/// </summary>
	SceneChanger m_manager;

	/// <summary>
	/// �f�B���N�g�����̃��[�_�[
	/// </summary>
	InfoLoader m_infoLoader;

public:

	/// <summary>
	/// �R���X�g���N�^
	/// path�̃f�B���N�g���̃����`���[�ɂȂ�B
	/// </summary>
	/// <param name = "path">
	/// �����`���[�Ƃ������f�B���N�g���̃p�X
	/// </param>
	Launcher(const FilePath& path);

	/// <summary>
	/// �����`���[�̊J�n
	/// </summary>
	void start();
};