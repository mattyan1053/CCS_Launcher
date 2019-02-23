# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Defines.hpp"
# include "Fade.hpp"

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

/// <summary>
/// �V�[���J�ڃN���X�p���N���X
/// </summary>
/// <remarks>
/// �������z�֐����܂ނ̂ŁA�C���X�^���X���s��
/// </remarks>
class BaseScene : public SceneChanger::Scene{

public:

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	BaseScene() = default;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseScene() = default;

	/// <summary>
	/// ���X�V&�V�[���J��
	/// </summary>
	void update() override;

	/// <summary>
	/// �����`���[�̍X�V
	/// </summary>
	/// <remarks>
	/// �v���Z�X�̋N��������������ƌĂ΂��B
	/// �K���I�[�o�[���C�h���邱��
	/// </remarks>
	virtual void updateLauncher() = 0;

	/// <summary>
	/// �t�F�[�h�C�����̉��o
	/// </summary>
	void drawFadeIn(double t) const override {
		draw();
		FadeIn(t);
	}

	/// <summary>
	/// �t�F�[�h�A�E�g���̉��o
	/// </summary>
	void drawFadeOut(double t) const override {
		draw();
		FadeOut(t);
	}

};