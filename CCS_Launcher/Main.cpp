# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"
# include "ResourceLoader.hpp"
# include "WindowSetting.hpp"

Size windowSize = { 1280,720 };
Point windowPos = { 100, 100 };

void ErrorDialog(String errMsg) {

	GUI gui(GUIStyle::Default);
	gui.setTitle(L"読み込みエラー");
	gui.addln(GUIText::Create(errMsg));
	gui.addln(L"exitbutton", GUIButton::Create(L"終了"));
	gui.setCenter(Window::Center());

	while (System::Update()) {
		if (gui.button(L"exitbutton").pushed) {
			System::Exit();
		}
	}

}

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

	// Gameディレクトリの確認
	if (!FileSystem::Exists(L"./Game")) {
		ErrorDialog(L"Gameディレクトリがありません。");
	}
	if (FileSystem::IsEmpty(L"./Game")) {
		ErrorDialog(L"Gameディレクトリが空です。");
	}

	// ランチャーの生成
	Launcher launcher(L"./Game");

	launcher.init();

}
