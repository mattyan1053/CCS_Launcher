# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// �A�v���P�[�V�������e�ڍׁ��N�����
/// </summary>
class Detail : public SceneChanger::Scene {

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Detail();

	/// <summary>
	/// ��ʏ��X�V&�V�[���J��
	/// </summary>
	void update() override;

	/// <summary>
	/// ��ʕ`��
	/// </summary>
	void draw() const override;

};