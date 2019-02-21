# pragma once
# include <Siv3D.hpp>
# include "SelectItems.hpp"

SelectItems::SelectItems(const int& _id, const Vec2& _pos, const AppInfo& _appInfo) 
	: id(_id), 
	pos(_pos),
	itemFrame(pos, itemSize),
	screenshotFrame(pos + screenshotPos, screenshotSize),
	appInfo(_appInfo)
{



}

void SelectItems::draw() const{

	itemFrame.draw();
	FontAsset(L"nomal")(appInfo.name).draw(pos);
	screenshotFrame.draw();

}