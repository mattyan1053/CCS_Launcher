# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

/// <summary>
/// �Z���N�g��ʂ̃A�C�e���ݒ�
/// </summary>
class SelectItems {

public :

	const Size itemSize = {200, 300};
	const Size screenshotSize = { 180, 200 };
	const Vec2 screenshotPos = { 20, 80 };
	const Vec2 pos;
	const AppInfo appInfo;

	unsigned int id;
	RectF itemFrame;
	RectF screenshotFrame;

	/// <summary>
	/// �R���X�g���N�^�B�������Q
	/// </summary>
	SelectItems(const int& _id, const Vec2& pos, const AppInfo& _appInfo);

	void draw() const;

};