# pragma once
# include <Siv3D.hpp>

/// <summary>
/// �tⳃN���X
/// </summary>
class Tag {

private:

	/// <summary>
	/// �tⳂɕ\������e�L�X�g
	/// </summary>
	String text;

	/// <summary>
	/// �tⳗp��`
	/// </summary>
	Rect rect;

	/// <summary>
	/// �QD��]�p
	/// </summary>
	Mat3x2 mat;

public:

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Tag() = default;

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">
	/// �tⳂ̈ʒu
	/// </param>
	/// <param name="size">
	/// �tⳂ̃T�C�Y
	/// </param>
	/// <param name="_text">
	/// �tⳂ̃e�L�X�g
	/// </param>
	Tag(Point pos, Size size, String _text);

	/// <summary>
	/// �p�����[�^�Đݒ�
	/// </summary>
	/// <param name="pos">
	/// �tⳈʒu
	/// </param>
	/// <param name="size">
	/// �tⳂ̃T�C�Y
	/// </param>
	/// <param name="_text">
	/// �tⳂ̃e�L�X�g
	/// </param>
	void set(Point pos, Size size, String _text);

	/// <summary>
	/// �tⳂ̕`��
	/// </summary>
	void draw() const;

};