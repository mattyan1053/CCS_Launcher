# pragma once
# include <Siv3D.hpp>
# include "SelectItem.hpp"

// 静的メンバの初期化
int32 SelectItem::m_itemPos = SelectItem::marginX;
int32 SelectItem::m_itemNum = 0;

SelectItem::SelectItem(const unsigned int _id, const AppInfo appInfo)
	: id(_id),
	m_appInfo(appInfo),
	m_isMouseOver(false),
	m_stretchRate(0)
{
	m_pos = { id * (itemSize.x + marginX), marginTop };
	m_frame.setPos(m_pos);
	m_frame.setSize(itemSize);
}

SelectItem::posState SelectItem::checkPos() {

	if (m_itemPos >= marginX) {
		m_itemPos = marginX;
		return overLeft;
	}
	if (m_itemPos <= Window::Size().x - (sizeX + marginX) * m_itemNum - marginX) {
		m_itemPos = Window::Size().x - (sizeX + marginX) * m_itemNum - marginX;
		return overRight;
	}

	return ok;

}

bool SelectItem::update(const unsigned int _id) {

	// 選択状態なら拡大、そうでなければ元のサイズに戻す
	if (m_isMouseOver = m_frame.movedBy({ m_itemPos, 0 }).mouseOver || id == _id) {
		m_stretchRate = Min(m_stretchRate + stretchRateMax / 10, stretchRateMax);
		return true;
	}
	m_stretchRate = Max(m_stretchRate - stretchRateMax / 20, 0.0);
	return false;

}

bool SelectItem::checkClick() {

	if (m_frame.movedBy({ m_itemPos, 0 }).leftClicked) return true;
	return false;

}

void SelectItem::draw() const {

	m_frame.movedBy({ m_itemPos, 0 }).stretched(m_stretchRate).drawShadow({ m_stretchRate,  m_stretchRate }, m_stretchRate, 6);
	m_frame.movedBy({ m_itemPos, 0 }).stretched(m_stretchRate)(m_appInfo.appData.screenshot).draw().drawFrame(0, 10, Palette::White);

	{
		const Tag tag({ m_frame.movedBy({ m_itemPos, 0 }).pos.x + 15,m_frame.movedBy({ m_itemPos, 0 }).pos.y + itemSize.y - nameTagSize.y }, nameTagSize, m_appInfo.name, Palette::Aliceblue);
		const Transformer2D transformer(Mat3x2::Scale(m_stretchRate / 100 + 1, tag.center() - Point(0, 50)).rotate(Radians(-5), tag.center()));
		tag.draw();
	}


}

void SelectItem::moveItemPos(int32 diff) {

	m_itemPos -= diff * 100;
	SelectItem::checkPos();

}

void SelectItem::setItemNum(int32 itemNum) {
	m_itemNum = itemNum;
}