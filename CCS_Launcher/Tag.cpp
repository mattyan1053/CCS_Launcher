# pragma once
# include <Siv3D.hpp>
# include "Tag.hpp"

Tag::Tag(Point pos, Size size, String _text)
	: text(_text),
	mat(Mat3x2::Rotate(Radians(2), pos)),
	clr(Palette::White)
{
	rect.set(pos, size);
}

Tag::Tag(Point pos, Size size, String _text, Color _clr)
	: text(_text),
	mat(Mat3x2::Rotate(Radians(2), pos)),
	clr(_clr)
{
	rect.set(pos, size);
}

void Tag::set(Point pos, Size size, String _text) {

	rect.set(pos, size);
	text = _text;

	clr = Palette::White;

	mat = Mat3x2::Rotate(Radians(2), pos);

}

void Tag::set(Point pos, Size size, String _text, Color _clr) {

	rect.set(pos, size);
	text = _text;

	clr = _clr;

	mat = Mat3x2::Rotate(Radians(2), pos);

}

void Tag::draw() const {
	
	{
		const Transformer2D transformer(mat, true);
		rect.drawShadow({ 1, 1 }, 12, -1, ColorF(0, 0.4));
	}

	rect.draw(clr);
	

	FontAsset(L"tag")(text).drawCenter(rect.center, Palette::Black);

}