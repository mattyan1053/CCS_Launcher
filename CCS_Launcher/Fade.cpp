# pragma once
# include "Fade.hpp"

void Fade(double t, bool in)
{
	if (t > 0.75)
	{
		Window::ClientRect().draw(ColorF(0.0));
		return;
	}

	t *= (1 / 0.75);

	Graphics2D::SetStencilState(StencilState::Replace);
	Graphics2D::SetStencilValue(1);

	TextureAsset(L"ccslogo")
		.scale(4 * EaseIn(Easing::Quad, 1 - t))
		.rotate((in ? (1.0 - t) : t) * 10)
		.drawAt(Window::Center());

	Graphics2D::SetStencilState(StencilState::Test(StencilFunc::NotEqual));
	Window::ClientRect().draw(ColorF(0.0, t * 4.0));
	Graphics2D::SetStencilState(StencilState::Default);
}

void FadeIn(double t)
{
	Fade(1.0 - t, true);
}

void FadeOut(double t)
{
	Fade(t, false);
}