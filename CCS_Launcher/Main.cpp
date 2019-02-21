# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"
# include "ResourceLoader.hpp"

void Main()
{

	// リソースの読み込み
	ResourceLoader resourceLoader;
	resourceLoader.load();

	// ランチャーの生成
	Launcher launcher(L"./Game");

	launcher.start();

}
