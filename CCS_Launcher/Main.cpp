# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"
# include "ResourceLoader.hpp"

void Main()
{

	// リソースの読み込み
	ResourceLoader resourceLoader;
	resourceLoader.load();

	Launcher launcher(L"./Game");

	while (System::Update())
	{
		launcher.update();
		launcher.draw();
	}
}
