# pragma once
# include <Siv3D.hpp>
# include "Tag.hpp"

Tag::Tag(Point pos, Size size, String _text)
	: text(_text),
	mat(Mat3x2::Rotate(Radians(2), pos))
{
	rect.set(pos, size);
}

void Tag::set(Point pos, Size size, String _text) {

	rect.set(pos, size);
	text = _text;

	mat = Mat3x2::Rotate(Radians(2), pos);

}

void Tag::draw() const {
	
	{
		const Transformer2D transformer(mat, true);
		rect.drawShadow({ 1, 1 }, 12, -1, ColorF(0, 0.4));
	}

	rect.draw();

	FontAsset(L"tag")(text).drawCenter(rect.center, Palette::Black);

}