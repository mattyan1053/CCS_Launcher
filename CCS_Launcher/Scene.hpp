# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Defines.hpp"

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

using SceneChanger = SceneManager<String, ShereData>;