# pragma once
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);

	while (System::Update())
	{
		font(L"CCS Launcher!!").draw();
	}
}
