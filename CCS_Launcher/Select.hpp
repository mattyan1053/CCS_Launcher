# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// �A�v���P�[�V�����I�����
/// </summary>
class Select : public BaseScene {

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Select();

	void updateLauncher() override;

	/// <summary>
	/// ��ʕ`��
	/// </summary>
	void draw() const override;

};