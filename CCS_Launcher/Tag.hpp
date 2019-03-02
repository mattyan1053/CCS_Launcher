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
	/// �w�i�F
	/// </summary>
	Color clr;

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
	/// <param name="_clr">
	/// �tⳐF
	/// </param>
	Tag(Point pos, Size size, String _text, Color _clr);

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
	/// �w�i�F�t���ݒ�
	/// </summary>
	/// <param name="pos">
	/// �tⳈʒu
	/// </param>
	/// <param name="size">
	/// �tⳃT�C�Y
	/// </param>
	/// <param name="_text">
	/// �tⳃe�L�X�g
	/// </param>
	/// <param name="_clr">
	/// �tⳐF
	/// </param>
	void set(Point pos, Size size, String _text, Color _clr);

	Point center() const {
		return rect.center;
	}

	/// <summary>
	/// �tⳂ̕`��
	/// </summary>
	void draw() const;

};