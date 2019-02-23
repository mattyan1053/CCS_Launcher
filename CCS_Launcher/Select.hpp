# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "SelectItem.hpp"
# include "Button.hpp"

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

public:

	/// <summary>
	/// �T�v���p�����[�^
	/// </summary>
	const Point summaryPos = {20, 450};
	const Size summarySize = { 700, 250 };

	/// <summary>
	/// �{�^���p�����[�^
	/// </summary>
	const Size buttonSize = { 200, 60 };
	const Point buttonPos = { summaryPos + summarySize - buttonSize - Point(50, 20) };
	const Point demoButtonPos = { Window::Size().x - buttonSize.x - 50, 10 };

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