# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

class SelectItem {

private:

	/// <summary>
	/// �S�A�C�e���̐擪�ʒu
	/// </summary>
	static int32 m_itemPos;

	/// <summary>
	/// �A�C�e����
	/// </summary>
	static int32 m_itemNum;

	/// 	/// <summary>
	/// �A�C�e���̃t���[��
	/// </summary>
	RectF m_frame;

	/// <summary>
	/// �A�C�e���A�C�R���̏ꏊ
	/// </summary>
	Vec2 m_pos;

	/// <summary>
	/// �A�C�e���Ɋi�[����A�v���P�[�V����
	/// </summary>
	AppInfo m_appInfo;

	/// <summary>
	/// �}�E�X���悹���Ă��邩�ǂ����t���O
	/// </summary>
	bool m_isMouseOver;

	/// <summary>
	/// �J�[�\�������킹�Ă���Ƃ��̊g�嗦
	/// </summary>
	double m_stretchRate;

public:


	/// <summary>
	/// �A�C�e��ID
	/// </summary>
	const unsigned int id;

	/// <summary>
	/// �A�C�e���̃T�C�Y
	/// </summary>
	static const int32 sizeX = 300;
	const Size itemSize = { sizeX, sizeX * 3 / 4 };
	static const int32 marginX = 60;
	const int32 marginTop = 130;
	const double stretchRateMax = 40.0;

	/// <summary>
	/// �R���X�g���N�^
	/// �A�C�e���̐����A������
	/// </summary>
	/// <param name="pos">
	/// �A�C�e���̏����ʒu
	/// </param>
	/// <param name="appInfo">
	/// �A�C�e���Ɋi�[����A�v���P�[�V�������
	/// </param>
	SelectItem(const unsigned int _id, const AppInfo appInfo);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SelectItem() = default;

	/// <summary>
	/// �A�C�e�����̍X�V
	/// </summary>
	/// <returns>
	/// �}�E�X�I�[�o�[���Ă���� 1 �A���Ă��Ȃ���� 0 ��Ԃ�
	/// </returns>
	int update(const unsigned int _id);

	/// <summary>
	/// �A�C�e���̃N���b�N����
	/// </summary>
	/// <returns>
	/// �N���b�N����Ă���� 1 �A����Ă��Ȃ���� 0 ��Ԃ�
	/// </returns>
	int checkClick();

	/// <summary>
	/// �A�C�e���̕`��
	/// </summary>
	void draw() const;

	/// <summary>
	/// �A�C�e���̉����̎擾
	/// </summary>
	/// <returns>
	/// �]�����݃A�C�e���S�̂̉���
	/// </returns>
	int getItemWidth() {
		return itemSize.x + marginX;
	}

	/// <summary>
	/// �A�C�e���S�̊J�n�ʒu�̈ړ�
	/// </summary>
	/// <param name="diff">
	/// �ړ�����
	/// </param>
	static void moveItemPos(int32 diff);

	/// <summary>
	/// �A�C�e�����̐ݒ�
	/// </summary>
	/// <param name="itemNum">
	/// �A�C�e����
	/// </param>
	static void setItemNum(int32 itemNum);

};