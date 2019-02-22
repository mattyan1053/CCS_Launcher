# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "Button.hpp"
# include "Tag.hpp"
# include "InlineFrame.hpp"
# include "Fade.hpp"

/// <summary>
/// �A�v���P�[�V�������e�ڍׁ��N�����
/// </summary>
class Detail : public BaseScene {

private:

	/// <summary>
	/// �Q�[���̊J�n�{�^��
	/// </summary>
	Button m_startButton;

	/// <summary>
	/// �Z���N�g��ʂ֖߂�{�^��
	/// </summary>
	Button m_backButton;

	/// <summary>
	/// �Q�[���W������
	/// </summary>
	Tag m_kind;

	/// <summary>
	/// ������@
	/// </summary>
	Tag m_usetext;

	/// <summary>
	/// Readme �t���[��
	/// </summary>
	InlineFrame frame;

public:

	/// <summary>
	/// �㉺���E�̋�
	/// </summary>
	const int32 marginLeft = 30;
	const int32 marginRight = 50;
	const int32 marginTop = 60;
	const int32 marginBottom = 50;

	/// <summary> 
	/// �{�^���T�C�Y
	/// </summary>
	const int32 buttonSizeX = 230;
	const int32 buttonSizeY = 60;
	const Size buttonSize = { buttonSizeX, buttonSizeY };
	const Point startButtonPos = {marginLeft, Window::Size().y - marginBottom - buttonSizeY};
	const Point backButtonPos = { marginLeft + buttonSizeX + 30, Window::Size().y - marginBottom - buttonSizeY };

	/// <summary>
	/// �X�N���[���V���b�g�T�C�Y
	/// </summary>
	const Point screenshotPos = { marginLeft, marginTop + 80 };
	const int32 screenshotSizeX = 450;
	const Size screenshotSize = { screenshotSizeX, screenshotSizeX * 3 / 4 };

	/// <summary>
	/// �^�O�T�C�Y
	/// </summary>
	const Point tagPos = { marginLeft, marginTop + 80 + screenshotSize.y };
	const Size tagSize = { 500, 50 };

	/// <summary>
	/// Readme �T�C�Y
	/// </summary>
	const Point readmePos = { marginLeft + screenshotSizeX + 100, 80 };
	const Size readmeSize = Window::Size() - readmePos - Size(marginLeft, 30);

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Detail() = default;

	/// <summary>
	/// ������
	/// </summary>
	void init() override;

	/// <summary>
	/// ��ʏ��X�V&�V�[���J��
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// ��ʕ`��
	/// </summary>
	void draw() const override;

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