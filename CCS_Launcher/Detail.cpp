# pragma once
# include <Siv3D.hpp>
# include <Windows.h>
# include "Detail.hpp"

# define NOMINMAX
# undef CreateProcess

void Detail::init() {

	// ボタンの設定
	m_startButton.set(startButtonPos, buttonSize, L"あそぶ");
	m_backButton.set(backButtonPos, buttonSize, L"もどる");

	// 概要欄の設定
	m_kind.set(tagPos, tagSize, L"ゲームジャンル：" + m_data->apps[m_data->selectedID].appData.kind);
	m_usetext.set(tagPos + Point(0, tagSize.y + 20), tagSize, L"操作：" + m_data->apps[m_data->selectedID].appData.usingtext);

	// Readme　設定
	frame = InlineFrame(Rect(readmePos, readmeSize));

	// 動画再生
	if (m_data->apps[m_data->selectedID].isMovieExist) {
		m_data->apps[m_data->selectedID].appData.demo.play();
	}

}

void Detail::updateLauncher() {

	// 動画更新
	if (m_data->apps[m_data->selectedID].isMovieExist) {
		if (Window::Focused() && !m_data->apps[m_data->selectedID].appData.demo.isPlaying()) m_data->apps[m_data->selectedID].appData.demo.play();
		m_data->apps[m_data->selectedID].appData.demo.update();
	}
	
	// ランチャーがアクティブでないときポーズ
	if (m_data->apps[m_data->selectedID].isMovieExist && m_data->apps[m_data->selectedID].appData.demo.isPlaying() && Window::Focused() == false) {
		m_data->apps[m_data->selectedID].appData.demo.pause();
	}

	// 戻る
	if (m_backButton.update()) {
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			m_data->apps[m_data->selectedID].appData.demo.stop();
		}
		changeScene(L"Select");
	}

	// 遊ぶ
	if (m_startButton.update()) {
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			m_data->apps[m_data->selectedID].appData.demo.pause();
		}
		
		// EXE形式以外のファイルはShellExecuteExを使用して開いている。
		// EXE形式のファイルもShellExecuteで問題ないと考えられるが、動作の安定に不安があるため一応残してある
		if (FileSystem::Extension(m_data->apps[m_data->selectedID].appData.executePath) == L"exe") {
			m_data->process = System::CreateProcess(m_data->apps[m_data->selectedID].appData.executePath);
		}
		else {
			m_data->handle = openOtherApps(FileSystem::FileName(m_data->apps[m_data->selectedID].appData.executePath), FileSystem::ParentPath(m_data->apps[m_data->selectedID].appData.executePath));
		}

	}

	frame.update(m_data->apps[m_data->selectedID].appData.readme.size);

}

void Detail::draw() const{

	// タイトル

	const Mat3x2 mat = Mat3x2::Rotate(-5_deg, screenshotPos);
	{
		const Transformer2D transformer(mat, true);
		const Rect screenshotFrame(screenshotPos, screenshotSize);
		const auto ty = [=](KineticTypography& k) {
			k.pos.x += k.index * 4;
		};
		// タイトルの文字数が大きい場合は小さいフォントを使う
		if (FontAsset(L"title2")(m_data->apps[m_data->selectedID].name).region().w < screenshotSizeX + 50) {
			FontAsset(L"title2")(m_data->apps[m_data->selectedID].name).drawKinetic(marginLeft, marginTop, ty);
		}
		else {
			FontAsset(L"title3")(MakeTailCutString(m_data->apps[m_data->selectedID].name, screenshotSizeX + 50, L"title3")).drawKinetic(marginLeft, marginTop, ty);
		}
		screenshotFrame.drawShadow({ 6, 6 }, 3, 5);
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			screenshotFrame(m_data->apps[m_data->selectedID].appData.demo.getFrameTexture().resize(screenshotSize)).draw().drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);
		}
		else {
			screenshotFrame(m_data->apps[m_data->selectedID].appData.screenshot.resize(screenshotSize)).draw().drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);
		}
	}

	// 付箋
	m_kind.draw();
	m_usetext.draw();

	// ボタン
	m_startButton.draw();
	m_backButton.draw();

	// Readme
	FontAsset(L"subtitle")(L"Read me !!").draw(readmePos.x, 30);
	const InlineFrameData frameData = frame.getFrameData();
	frameData.contentsArea.draw(Palette::White);
	Texture& texture = m_data->apps[m_data->selectedID].appData.readme;
	texture(frameData.contentsOffset, Min(frameData.contentsArea.w, texture.width), Min(frameData.contentsArea.h, texture.height)).draw(frameData.contentsArea.pos);
	frame.draw();
	frameData.region.drawFrame(0, 1.5, Palette::Gray);

}

# define NOMINMAX

HANDLE Detail::openOtherApps(const FilePath & file, const FilePath & directory) {

	SHELLEXECUTEINFO shellExeInfo;
	memset(&shellExeInfo, 0, sizeof(shellExeInfo));
	shellExeInfo.cbSize = sizeof(shellExeInfo);
	shellExeInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shellExeInfo.lpVerb = L"open";
	shellExeInfo.lpFile = file.c_str();
	shellExeInfo.lpParameters = nullptr;
	shellExeInfo.lpDirectory = directory.c_str();
	shellExeInfo.nShow = SW_SHOWNORMAL;

	ShellExecuteExW(&shellExeInfo);

	HANDLE handle = shellExeInfo.hProcess;

	return handle;

}