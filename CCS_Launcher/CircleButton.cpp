# include "CircleButton.hpp"

void CircleButton::set(Point _pos, int32 _r, String _text){

	pos = _pos;
	r = _r;
	text = _text;
	m_button.set(pos, r);

}

bool CircleButton::update() {
	return m_button.leftClicked;
}

void CircleButton::draw() const {

	if (m_button.mouseOver) {
		m_button.draw(Palette::Skyblue);
		m_button.drawFrame(4, 0, Palette::White);
		FontAsset(L"arrow")(text).drawCenter(m_button.center, Palette::White);
	}
	else {
		m_button.draw(Palette::White);
		m_button.drawFrame(2, 0, Palette::Skyblue);
		FontAsset(L"arrow")(text).drawCenter(m_button.center, Palette::Skyblue);
	}

}
