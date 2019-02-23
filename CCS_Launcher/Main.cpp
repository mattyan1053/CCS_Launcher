# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"
# include "ResourceLoader.hpp"
# include "WindowSetting.hpp"

Size windowSize = { 1280,720 };
Point windowPos = { 100, 100 };

void Main()
{

	// ウィンドウの設定
	Window::SetTitle(L"CCS Works");
	Window::Resize(windowSize);
	Window::SetPos(windowPos);

	Graphics::SetBackground(Palette::Skyblue);

	// リソースの読み込み
	ResourceLoader resourceLoader;
	resourceLoader.load();

	// ランチャーの生成
	Launcher launcher(L"./Game");

	launcher.init();

}
