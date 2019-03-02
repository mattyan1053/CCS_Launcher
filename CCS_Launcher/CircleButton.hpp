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
	/// <param name="r">
	/// �{�^�����a
	/// </param>
	/// <param name="_text">
	/// �{�^���̃e�L�X�g
	/// </param>
	void set(Point _pos, int32 r, String _text);

	bool update();

	/// <summary>
	/// �{�^���`��
	/// </summary>
	void draw() const;

};
