# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Demo.hpp"

/// <summary>
/// �f���V�[���N���X
/// </summary>
class DemoScene : public DemoSceneChanger::Scene {

private:

	/// <summary>
	/// ���g��ID
	/// </summary>
	int32 m_id;

	/// <summary>
	/// ���悩�X�N���[���V���b�g��
	/// </summary>
	bool m_isVideo;

	/// <summary>
	/// �X�N���[���V���b�g�\���Ԋu�Ǘ��p
	/// </summary>
	Stopwatch m_stopwatch;

	/// <summary>
	/// �\���Ԋu
	/// </summary>
	int32 waitTime = 10;

public:

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	DemoScene() = default;

	/// <summary>
	/// �V�[���J�ڎ�
	/// </summary>
	void init() override;

	/// <summary>
	/// ���X�V
	/// </summary>
	void update() override;

	/// <summary>
	/// ��ʍX�V
	/// </summary>
	void draw() const override;

};