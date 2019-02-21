# pragma once
# include <Siv3D.hpp>

/// <summary>
/// ���\�[�X���[�h�p�N���X
/// </summary>
class ResourceLoader {

public:

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	ResourceLoader() = default;

	/// <summary>
	/// �f�[�^�̃��[�h�B���ׂ�Asset�B
	/// </summary>
	void load();

	/// <summary>
	/// �t�H���g�̃��[�h
	/// </summary>
	void loadFonts();

	/// <summary>
	/// �摜�̃��[�h
	/// </summary>
	void loadTextures();

};