# pragma once
# include "Button.hpp"

/// <summary>
/// �ۂ��{�^���N���X
/// </summary>
class CircleButton : public Button {

private:

	/// <summary>
	/// �{�^���p�~
	/// </summary>
	Circle m_button;

public:

	/// <summary>
	/// �~�̔��a
	/// </summary>
	int32 r;

	/// <summary>
	/// �{�^���ݒ�
	/// </summary>
	/// <param name="_pos">
	/// �{�^���̒��S���W
	/// </param>
	/// <param name="_r">
	/// �{�^�����a
	/// </param>
	/// <param name="_text">
	/// �{�^���̃e�L�X�g
	/// </param>
	void set(Point _pos, int32 _r, String _text);

	/// <summary>
	/// �{�^���̃N���b�N����
	/// </summary>
	/// <returns>
	/// ������Ă���� true �A������Ă��Ȃ���� false ��Ԃ�
	/// </returns>
	bool update();

	/// <summary>
	/// �{�^���`��
	/// </summary>
	void draw() const;

};
