# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// �A�v���P�[�V�������e�ڍׁ��N�����
/// </summary>
class Detail : public BaseScene {

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Detail();

	/// <summary>
	/// ��ʏ��X�V&�V�[���J��
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// ��ʕ`��
	/// </summary>
	void draw() const override;

};