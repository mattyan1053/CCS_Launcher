# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "SelectItem.hpp"
# include "Button.hpp"
# include "CircleButton.hpp"

/// <summary>
/// �A�v���P�[�V�����I�����
/// </summary>
class Select : public BaseScene {

private:

	/// <summary>
	/// �A�C�e���z��
	/// </summary>
	Array<SelectItem> m_items;

	/// <summary>
	/// �T�v���p��`
	/// </summary>
	Rect m_frameSummary;

	/// <summary>
	/// �ڍ׃{�^��
	/// </summary>
	Button m_detailButton;

	/// <summary>
	/// �f���J�ڃ{�^��
	/// </summary>
	Button m_demoButton;

	/// <summary>
	/// �A�C�e���ʒu�ړ��{�^����
	/// </summary>
	CircleButton m_leftButton;

	/// <summary>
	/// �A�C�e���ʒu�ړ��{�^���E
	/// </summary>
	CircleButton m_rightButton;

	/// <summary>
	/// �A�C�e���ړ��t���O
	/// </summary>
	int32 m_moveFlag = 0;

public:

	/// <summary>
	/// �T�v���p�����[�^
	/// </summary>
	const Point summaryPos = { 120, 450 };
	const Size summarySize = { 700, 250 };

	/// <summary>
	/// �{�^���p�����[�^
	/// </summary>
	const Size buttonSize = { 200, 60 };
	const Point buttonPos = { summaryPos + summarySize - buttonSize - Point(50, 20) };
	const Point demoButtonPos = { Window::Size().x - buttonSize.x - 50, 10 };
	const int32 moveButtonRadius = 40;
	const Point leftButtonPos = { 20 + moveButtonRadius, 240 };
	const Point rightButtonPos = { Window::Size().x - 20 - moveButtonRadius, 240 };

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Select() = default;

	/// <summary>
	/// �V�[���N���X�̏�����
	/// </summary>
	void init() override;

	/// <summary>
	/// ���쒆�̉�ʍX�V(�V�[���J�ڒ��y�ё��̃V�[�����͌Ă΂�Ȃ�)
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// ��ʕ`��
	/// </summary>
	void draw() const override;

};