# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"
# include "ResourceLoader.hpp"

void Main()
{

	// ウィンドウの設定
	Window::SetTitle(L"CCS Work Station");
	Window::Resize(1000, 600);

	// リソースの読み込み
	ResourceLoader resourceLoader;
	resourceLoader.load();

	// ランチャーの生成
	Launcher launcher(L"./Game");

	launcher.start();

}
