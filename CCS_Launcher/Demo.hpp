# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Scene.hpp"

/// <summary>
/// �f���V�[�������N���X
/// </summary>
struct DemoData {

	/// <summary>
	/// �Đ�����ID
	/// </summary>
	int32 playingID;

	/// <summary>
	/// �A�v���P�[�V������
	/// </summary>
	unsigned int appsNum;

	/// <summary>
	/// �A�v���P�[�V�����f�[�^(ShareData���Q��)
	/// </summary>
	Array<AppInfo> apps;

	std::function<void(String)> changeBaseScene;

};

using DemoSceneChanger = SceneManager<int32, DemoData>;

class Demo : public BaseScene {
private:

	/// <summary>
	/// �V�[���J�ڃ}�l�[�W���[
	/// </summary>
	DemoSceneChanger m_manager;

public:

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Demo() = default;

	/// <summary>
	/// �V�[���J�ڂ��ꂽ�Ƃ��̏�����
	/// </summary>
	void init() override;

	/// <summary>
	/// �V�[���̍X�V
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void draw() const override;

};
